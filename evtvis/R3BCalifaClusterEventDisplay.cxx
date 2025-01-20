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

// --------------------------------------------------------------------
// -----          R3BCalifaClusterEventDisplay source file            -----
// --------------------------------------------------------------------

#include "R3BCalifaClusterEventDisplay.h"

#include "FairEventManager.h"
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairTask.h"
#include "TClonesArray.h"
#include "TObjArray.h"

#include "R3BCalifaClusterData.h"

#include "TCanvas.h"
#include "TH2F.h"
#include "TStyle.h"
#include <iostream>

#include <assert.h>

using std::cout;
using std::endl;

// -----   Default constructor   -------------------------------------------
R3BCalifaClusterEventDisplay::R3BCalifaClusterEventDisplay()
    : FairTask("R3BCalifaClusterEventDisplay", 0)
    , fEventManager(NULL)
{
}
// -----------------------------------------------------------------------

// -----   Standard constructor   -------------------------------------------
R3BCalifaClusterEventDisplay::R3BCalifaClusterEventDisplay(const char* name, Int_t iVerbose)
    : FairTask(name, iVerbose)
    , fEventManager(NULL)
{
}
// -----------------------------------------------------------------------

// -----   Destructor   ----------------------------------------------------
R3BCalifaClusterEventDisplay::~R3BCalifaClusterEventDisplay() {}
// -------------------------------------------------------------------------

// -----   Public method Init   --------------------------------------------
InitStatus R3BCalifaClusterEventDisplay::Init()
{

    FairRootManager* ioManager = FairRootManager::Instance();
    if (!ioManager)
        LOG(fatal) << "Init:No FairRootManager";
    if (!fCaloHitCA)
        fCaloHitCA = dynamic_cast<TClonesArray*>(ioManager->GetObject("CalifaClusterData"));

    CreateHistograms();
    MakeSlots();
    MakeViewerScene();

    return kSUCCESS;
}

// -----   Public method ReInit   --------------------------------------------
InitStatus R3BCalifaClusterEventDisplay::ReInit() { return kSUCCESS; }

// -----   Public method Exec   --------------------------------------------
void R3BCalifaClusterEventDisplay::Exec(Option_t* opt) {}

// ---- Public method Reset   --------------------------------------------------
void R3BCalifaClusterEventDisplay::Reset() {}

// ---- Public method Finish   --------------------------------------------------
void R3BCalifaClusterEventDisplay::Finish() {}

// -----   Private method CreateHistograms  -------------------------------------
void R3BCalifaClusterEventDisplay::CreateHistograms() {}

// -----   Private method MakeSlots  -------------------------------------
void R3BCalifaClusterEventDisplay::MakeSlots() {}

// -----   Private method MakeViewerScene  ---------------------------------
void R3BCalifaClusterEventDisplay::MakeViewerScene() {}

ClassImp(R3BCalifaClusterEventDisplay)
