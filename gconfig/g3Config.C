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

// Configuration macro for Geant3 VirtualMC

void Config()
{
    FairRunSim* fRun = FairRunSim::Instance();
    TString* gModel = fRun->GetGeoModel();
    TGeant3* geant3 = NULL;
    if (strncmp(gModel->Data(), "TGeo", 4) == 0)
    {
        geant3 = new TGeant3TGeo("C++ Interface to Geant3");
        cout << "-I- G3Config: Geant3 with TGeo has been created." << endl;
    }
    else
    {
        geant3 = new TGeant3("C++ Interface to Geant3");
        cout << "-I- G3Config: Geant3 native has been created." << endl;
    }
    // create Fair Specific Stack
    R3BStack* stack = new R3BStack();
    stack->SetDebug(kFALSE);
    stack->StoreSecondaries(kTRUE);
    stack->SetMinPoints(1);
    geant3->SetStack(stack);

    // ******* Geant3 configuration for simulated Runs  *******
    geant3->SetTRIG(1); // Number of events to be processed
    geant3->SetSWIT(4, 100);
    geant3->SetDEBU(0, 0, 1);
    geant3->SetDCAY(1);
    geant3->SetPAIR(1);
    geant3->SetCOMP(1);
    geant3->SetPHOT(1);
    geant3->SetPFIS(0); //
    geant3->SetDRAY(1);
    geant3->SetANNI(1);
    geant3->SetBREM(1);
    geant3->SetMUNU(1);
    geant3->SetCKOV(1);
    geant3->SetHADR(3); // Select pure GEANH (HADR 1) or GEANH/NUCRIN (HADR 3) //5==GCALOR
    geant3->SetLOSS(1);
    geant3->SetMULS(1);
    geant3->SetRAYL(1);
    geant3->SetSTRA(1);

    geant3->SetAUTO(0); // Select automatic STMIN etc... calc. (AUTO 1) or manual (AUTO 0)
    geant3->SetABAN(0); // Restore 3.16 behaviour for abandoned tracks
    geant3->SetOPTI(2); // Select optimisation level for GEANT geometry searches (0,1,2)
    geant3->SetERAN(5.e-7);

    Float_t cut = 1.e-3; // 1MeV cut by default
    Float_t tofmax = 1.e10;
    // Float_t cut2 =  1.e-10; // 1 keV?
    Float_t cut2 = cut;
    Float_t cut3 = 50.e-6; // Threshold for delta electrons

    Float_t cut5[5] = { 0, 0, 0, 0, 0 };
    // set cuts here
    //             GAM ELEC NHAD CHAD MUON EBREM MUHAB EDEL MUDEL MUPA TOFMAX
    //    geant3->SetCUTS(cut2, cut2, cut2, cut2, cut, cut2, cut2, cut3, cut2, cut2,
    //                    tofmax);
    geant3->SetCUTS(cut2, cut2, cut2, cut2, cut, cut2, cut2, cut2, cut2, cut2, tofmax, cut5);
}
