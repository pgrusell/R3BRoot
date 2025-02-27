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

// Configuration macro for setting common cuts and processes for G3, G4 and Fluka.
// Specific cuts and processes to G3 or G4 should be set in the g3Config.C, g4Config.C or flConfig.C

void SetCuts()
{
    // ------>>>> IMPORTANT!!!!
    // For a correct comparison between GEANE and MC (pull distributions)
    // or for a simulation without the generation of secondary particles:
    // 1. set LOSS = 2, DRAY = 0, BREM = 1
    // 2. set the following cut values: CUTGAM, CUTELE, CUTNEU, CUTHAD, CUTMUO = 1 MeV or less
    //                                  BCUTE, BCUTM, DCUTE, DCUTM, PPCUTM = 10 TeV
    // (For an explanation of the chosen values, please refer to the GEANT User's Guide
    // or to message #5362 in the PandaRoot Forum >> Monte Carlo Engines >> g3Config.C thread)
    //
    // The default settings refer to a complete simulation which generates and follows also the secondary particles.

    TVirtualMC* MC = TVirtualMC::GetMC();

    MC->SetProcess("PAIR", 1); /** pair production*/
    MC->SetProcess("COMP", 1); /**Compton scattering*/
    MC->SetProcess("PHOT", 1); /** photo electric effect */
    MC->SetProcess("PFIS", 0); /**photofission*/
    MC->SetProcess("DRAY", 1); /**delta-ray*/
    MC->SetProcess("ANNI", 1); /**annihilation*/
    MC->SetProcess("BREM", 1); /**bremsstrahlung*/
    MC->SetProcess("HADR", 1); /**hadronic process*/
    MC->SetProcess("MUNU", 1); /**muon nuclear interaction*/
    MC->SetProcess("DCAY", 1); /**decay*/
    MC->SetProcess("LOSS", 1); /**energy loss*/
    MC->SetProcess("MULS", 1); /**multiple scattering*/

    const Double_t cut1 = 1.0E-4; // GeV --> 100 keV
    const Double_t cut2 = 1.0E-2; // GeV --> 10 MeV
    const Double_t tofmax = 1.e1; // seconds

    MC->SetCut("CUTGAM", cut1);   /** gammas (GeV)*/
    MC->SetCut("CUTELE", cut2);   /** electrons (GeV)*/
    MC->SetCut("CUTNEU", cut2);   /** neutral hadrons (GeV)*/
    MC->SetCut("CUTHAD", cut2);   /** charged hadrons (GeV)*/
    MC->SetCut("CUTMUO", cut2);   /** muons (GeV)*/
    MC->SetCut("BCUTE", cut2);    /** electron bremsstrahlung (GeV)*/
    MC->SetCut("BCUTM", cut2);    /** muon and hadron bremsstrahlung(GeV)*/
    MC->SetCut("DCUTE", cut2);    /** delta-rays by electrons (GeV)*/
    MC->SetCut("DCUTM", cut2);    /** delta-rays by muons (GeV)*/
    MC->SetCut("PPCUTM", cut2);   /** direct pair production by muons (GeV)*/
    MC->SetCut("TOFMAX", tofmax); /**time of flight cut in seconds*/
}
