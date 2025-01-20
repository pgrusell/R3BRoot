/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include "TClonesArray.h"
#include "TF1.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TMath.h"
#include "TObjArray.h"
#include "TRandom.h"

#include "TVector3.h"

#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"

#include "R3BCalifaCrystalCalPar.h"
#include "R3BCalifaMapped2CrystalCalPar.h"
#include "R3BCalifaMappedData.h"
#include "R3BCalifaMappingPar.h"

#include <iostream>
#include <stdlib.h>

R3BCalifaMapped2CrystalCalPar::R3BCalifaMapped2CrystalCalPar()
    : R3BCalifaMapped2CrystalCalPar("R3B CALIFA Calibration Parameters Finder ", 1)
{
}

R3BCalifaMapped2CrystalCalPar::R3BCalifaMapped2CrystalCalPar(const char* name, Int_t iVerbose)
    : FairTask(name, iVerbose)
    , fMap_Par(NULL)
    , fCal_Par(NULL)
    , fCalifaMappedDataCA(NULL)
    , fNumCrystals(1)
    , fNumParam(0)
    , fMinStadistics(100)
    , fMapHistos_left(0)
    , fMapHistos_right(0)
    , fMapHistos_bins(0)
    , fMapHistos_leftp(0)
    , fMapHistos_rightp(0)
    , fMapHistos_binsp(0)
    , fNumPeaks(0)
    , fSigma(0)
    , fThreshold(0)
    , fEnergyPeaks(NULL)
    , fDebugMode(0)
{
}

R3BCalifaMapped2CrystalCalPar::~R3BCalifaMapped2CrystalCalPar()
{
    LOG(info) << "R3BCalifaMapped2CrystalCalPar: Delete instance";
    if (fCalifaMappedDataCA)
        delete fCalifaMappedDataCA;
    if (fEnergyPeaks)
        delete fEnergyPeaks;
}

void R3BCalifaMapped2CrystalCalPar::SetParContainers()
{
    // Parameter Container
    // Reading califaMappingPar from FairRuntimeDb
    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    if (!rtdb)
    {
        LOG(error) << "FairRuntimeDb not opened!";
    }

    fMap_Par = dynamic_cast<R3BCalifaMappingPar*>(rtdb->getContainer("califaMappingPar"));
    if (!fMap_Par)
    {
        LOG(error) << "R3BCalifaMapped2CrystalCalPar::Init() Couldn't get handle on califaMappingPar container";
    }
    else
    {
        LOG(info) << "R3BCalifaMapped2CrystalCalPar:: califaMappingPar container open";
    }
}

void R3BCalifaMapped2CrystalCalPar::SetParameter()
{
    if (!fMap_Par)
    {
        LOG(warn) << "R3BCalifaMapped2CrystalCalPar::Container califaMappingPar not found.";
    }
    //--- Parameter Container ---
    fNumCrystals = fMap_Par->GetNumCrystals(); // Number of crystals x 2
    LOG(info) << "R3BCalifaMapped2CrystalCalPar::NumCry " << fNumCrystals;
    // fMap_Par->printParams();
}

InitStatus R3BCalifaMapped2CrystalCalPar::Init()
{
    LOG(info) << "R3BCalifaMapped2CrystalCalPar::Init()";

    if (!fEnergyPeaks)
    {
        fEnergyPeaks = new TArrayF;
        fEnergyPeaks->Set(fNumPeaks);
    }

    FairRootManager* rootManager = FairRootManager::Instance();
    if (!rootManager)
    {
        LOG(error) << "R3BCalifaMapped2CrystalCalPar::Init() FairRootManager not found";
        return kFATAL;
    }

    fCalifaMappedDataCA = dynamic_cast<TClonesArray*>(rootManager->GetObject("CalifaMappedData"));
    if (!fCalifaMappedDataCA)
    {
        LOG(error) << "R3BCalifaMapped2CrystalCalPar::Init() CalifaMappedData not found";
        return kFATAL;
    }

    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    if (!rtdb)
    {
        LOG(error) << "R3BCalifaMapped2CrystalCalPar::Init() FairRuntimeDb not found";
        return kFATAL;
    }

    fCal_Par = dynamic_cast<R3BCalifaCrystalCalPar*>(rtdb->getContainer("califaCrystalCalPar"));
    if (!fCal_Par)
    {
        LOG(error) << "R3BCalifaMapped2CrystalCalPar::Init() Couldn't get handle on califaCrystalCalPar container";
        return kFATAL;
    }

    // Set container with mapping parameters
    SetParameter();

    // Create histograms for crystal calibration
    char name[100];
    Int_t fright, fleft, fbins;
    fh_Map_energy_crystal = new TH1F*[fNumCrystals];
    for (Int_t i = 0; i < fNumCrystals; i++)
        if (fMap_Par->GetInUse(i + 1) == 1)
        {

            sprintf(name, "fh_Map_energy_crystal_%i", i + 1);
            if (i < fMap_Par->GetNumCrystals() / 2)
            {
                fright = fMapHistos_right;
                fleft = fMapHistos_left;
                fbins = fMapHistos_bins;
            }
            else
            {
                fright = fMapHistos_rightp;
                fleft = fMapHistos_leftp;
                fbins = fMapHistos_binsp;
            }
            fh_Map_energy_crystal[i] = new TH1F(name, name, fbins, fleft, fright);
        }

    return kSUCCESS;
}

InitStatus R3BCalifaMapped2CrystalCalPar::ReInit()
{
    SetParContainers();
    SetParameter();
    return kSUCCESS;
}

void R3BCalifaMapped2CrystalCalPar::Exec(Option_t* opt)
{
    Int_t nHits = fCalifaMappedDataCA->GetEntries();
    if (!nHits)
        return;

    R3BCalifaMappedData** MapHit = new R3BCalifaMappedData*[nHits];
    Int_t crystalId = 0;

    for (Int_t i = 0; i < nHits; i++)
    {
        MapHit[i] = dynamic_cast<R3BCalifaMappedData*>(fCalifaMappedDataCA->At(i));
        crystalId = MapHit[i]->GetCrystalId();
        // Fill histograms
        if (fMap_Par->GetInUse(crystalId) == 1)
            fh_Map_energy_crystal[crystalId - 1]->Fill(MapHit[i]->GetEnergy());
    }

    if (MapHit)
        delete[] MapHit;
    return;
}

void R3BCalifaMapped2CrystalCalPar::Reset() {}

void R3BCalifaMapped2CrystalCalPar::FinishEvent() {}

void R3BCalifaMapped2CrystalCalPar::FinishTask()
{
    // Look for the peaks in each spectrum
    SearchPeaks();
    // fCal_Par->printParams();
    if (fDebugMode)
        for (Int_t i = 0; i < fNumCrystals; i++)
            if (fMap_Par->GetInUse(i + 1) == 1 && fh_Map_energy_crystal[i]->GetEntries() > fMinStadistics)
                fh_Map_energy_crystal[i]->Write();
}

void R3BCalifaMapped2CrystalCalPar::SearchPeaks() {}

ClassImp(R3BCalifaMapped2CrystalCalPar)
