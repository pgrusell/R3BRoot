/******************************************************************************
 *   Copyright (C) 2026 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2026 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// -----------------------------------------------------------------
// -----            R3BActafHit2Cluster source file            -----
// -----      Created 12/04/26 by J.L. Rodriguez-Sanchez       -----
// -----------------------------------------------------------------

// ROOT headers
#include <TClonesArray.h>
#include <TMath.h>

// FAIR headers
#include <FairLogger.h>
#include <FairRootManager.h>

// ACTAF headers
#include "R3BActafClusterData.h"
#include "R3BActafHit2Cluster.h"
#include "R3BActafHitData.h"
#include "R3BLogger.h"

// R3BActafHit2Cluster::Default Constructor --------------------------
R3BActafHit2Cluster::R3BActafHit2Cluster()
    : R3BActafHit2Cluster("R3BActafHit2Cluster", 1)
{
}

// R3BActafHit2Cluster::Standard Constructor --------------------------
R3BActafHit2Cluster::R3BActafHit2Cluster(const TString& name, Int_t iVerbose)
    : FairTask(name, iVerbose)
{
}

// Virtual R3BActafHit2Cluster::Destructor
R3BActafHit2Cluster::~R3BActafHit2Cluster()
{
    R3BLOG(debug1, "");
    if (fActafCluster)
    {
        delete fActafCluster;
    }
}

// -----   Public method Init   --------------------------------------------
InitStatus R3BActafHit2Cluster::Init()
{
    R3BLOG(info, "");
    auto* mgr = FairRootManager::Instance();
    R3BLOG_IF(fatal, !mgr, "FairRootManager not found");

    // INPUT DATA
    fActafHitData = dynamic_cast<TClonesArray*>(mgr->GetObject("ActafHitData"));
    R3BLOG_IF(fatal, !fActafHitData, "ActafHitData not found");

    // OUTPUT DATA
    fActafCluster = new TClonesArray("R3BActafClusterData");
    mgr->Register("ActafClusterData", "ACTAF_Cluster", fActafCluster, !fOnline);
    Reset();

    return kSUCCESS;
}

// -----   Public method ReInit   ----------------------------------------------
InitStatus R3BActafHit2Cluster::ReInit()
{
    SetParContainers();
    return kSUCCESS;
}

// -----   Public method Execution   --------------------------------------------
void R3BActafHit2Cluster::Exec(Option_t*)
{
    // Reset entries in the output arrays
    Reset();

    // Reading the Input -- Hit Data --
    auto nHits = fActafHitData->GetEntriesFast();
    if (nHits == 0)
    {
        return;
    }

    std::vector<uint16_t> padlist;

    for (size_t index = 0; index < nHits; ++index)
    {
        auto hitData = dynamic_cast<R3BActafHitData const*>(fActafHitData->At(index));
        auto pad = hitData->GetPad();
        auto zpos = hitData->GetZpos();
        auto energy = hitData->GetEnergy();
        auto track = hitData->GetTrack();

        double chi2polarfit = 0.;

        AddClusterData((pad < 65 ? 1 : 2), 0., 0., zpos, energy, track, padlist, chi2polarfit);
    }
    return;
}

// -----   Public method Reset   ------------------------------------------------
void R3BActafHit2Cluster::Reset()
{
    R3BLOG(debug1, "Clearing ClusterData Structure");
    if (fActafCluster)
    {
        fActafCluster->Clear();
    }
}

// -----   Private method AddClusterData  ----------------------------------------
R3BActafClusterData* R3BActafHit2Cluster::AddClusterData(UInt_t side,
                                                         double xpos,
                                                         double ypos,
                                                         double zpos,
                                                         double energy,
                                                         TVector3 track,
                                                         std::vector<uint16_t> padlist,
                                                         double chi2polarfit)
{
    // It fills the R3BActafClusterData
    TClonesArray& clref = *fActafCluster;
    auto size = clref.GetEntriesFast();
    return new (clref[size]) R3BActafClusterData(side, xpos, ypos, zpos, energy, track, padlist, chi2polarfit);
}

ClassImp(R3BActafHit2Cluster)
