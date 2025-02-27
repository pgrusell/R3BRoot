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

// -------------------------------------------------------------------------
// -----                      R3BTraDigi header file                  -----
// -----                  Created 30/06/11  by D.Bertini/Justyna               -----
// -------------------------------------------------------------------------

/**  R3BTraDigi.h
 **/

#ifndef R3BTRADIGI_H
#define R3BTRADIGI_H

#include "TObject.h"
#include "TVector3.h"

class R3BTraDigi : public TObject
{

  public:
    /** Default constructor **/
    R3BTraDigi();
    R3BTraDigi(Double_t ss03_se_f,
               Double_t ss03_spos_f,
               Double_t ss03_sbw_f,
               Double_t ss03_sarea_f,
               Double_t ss03_seta_f,
               Double_t ss03_ke_f,
               Double_t ss03_kpos_f,
               Double_t ss03_kbw_f,
               Double_t ss03_karea_f,
               Double_t ss03_keta_f,
               Double_t ss06_se_f,
               Double_t ss06_spos_f,
               Double_t ss06_sbw_f,
               Double_t ss06_sarea_f,
               Double_t ss06_seta_f,
               Double_t ss06_ke_f,
               Double_t ss06_kpos_f,
               Double_t ss06_kbw_f,
               Double_t ss06_karea_f,
               Double_t ss06_keta_f,
               Double_t ss03_se_p1,
               Double_t ss03_spos_p1,
               Double_t ss03_sbw_p1,
               Double_t ss03_sarea_p1,
               Double_t ss03_seta_p1,
               Double_t ss03_ke_p1,
               Double_t ss03_kpos_p1,
               Double_t ss03_kbw_p1,
               Double_t ss03_karea_p1,
               Double_t ss03_keta_p1,
               Double_t ss06_se_p1,
               Double_t ss06_spos_p1,
               Double_t ss06_sbw_p1,
               Double_t ss06_sarea_p1,
               Double_t ss06_seta_p1,
               Double_t ss06_ke_p1,
               Double_t ss06_kpos_p1,
               Double_t ss06_kbw_p1,
               Double_t ss06_karea_p1,
               Double_t ss06_keta_p1);

    /** Copy constructor **/
    R3BTraDigi(const R3BTraDigi& point) { *this = point; };

    /** Destructor **/
    virtual ~R3BTraDigi();

    /** Output to screen **/
    virtual void Print(const Option_t* opt) const;

    void Setss03_se_f(Double_t en) { Ss03_se_f = en; }
    Double_t Getss03_se_f() { return Ss03_se_f; }

    void Setss03_spos_f(Double_t pos) { Ss03_spos_f = pos; }
    Double_t Getss03_spos_f() { return Ss03_spos_f; }

    void Setss03_sbw_f(Double_t bw) { Ss03_sbw_f = bw; }
    Double_t Getss03_sbw_f() { return Ss03_sbw_f; }

    void Setss03_sarea_f(Double_t area) { Ss03_sarea_f = area; }
    Double_t Getss03_sarea_f() { return Ss03_sarea_f; }

    void Setss03_seta_f(Double_t eta) { Ss03_seta_f = eta; }
    Double_t Getss03_seta_f() { return Ss03_seta_f; }

    void Setss03_ke_f(Double_t en) { Ss03_ke_f = en; }
    Double_t Getss03_ke_f() { return Ss03_ke_f; }

    void Setss03_kpos_f(Double_t pos) { Ss03_kpos_f = pos; }
    Double_t Getss03_kpos_f() { return Ss03_kpos_f; }

    void Setss03_kbw_f(Double_t bw) { Ss03_kbw_f = bw; }
    Double_t Getss03_kbw_f() { return Ss03_kbw_f; }

    void Setss03_karea_f(Double_t area) { Ss03_karea_f = area; }
    Double_t Getss03_karea_f() { return Ss03_karea_f; }

    void Setss03_keta_f(Double_t eta) { Ss03_keta_f = eta; }
    Double_t Getss03_keta_f() { return Ss03_keta_f; }

    void Setss06_se_f(Double_t en) { Ss06_se_f = en; }
    Double_t Getss06_se_f() { return Ss06_se_f; }

    void Setss06_spos_f(Double_t pos) { Ss06_spos_f = pos; }
    Double_t Getss06_spos_f() { return Ss06_spos_f; }

    void Setss06_sbw_f(Double_t bw) { Ss06_sbw_f = bw; }
    Double_t Getss06_sbw_f() { return Ss06_sbw_f; }

    void Setss06_sarea_f(Double_t area) { Ss06_sarea_f = area; }
    Double_t Getss06_sarea_f() { return Ss06_sarea_f; }

    void Setss06_seta_f(Double_t eta) { Ss06_seta_f = eta; }
    Double_t Getss06_seta_f() { return Ss06_seta_f; }

    void Setss06_ke_f(Double_t en) { Ss06_ke_f = en; }
    Double_t Getss06_ke_f() { return Ss06_ke_f; }

    void Setss06_kpos_f(Double_t pos) { Ss06_kpos_f = pos; }
    Double_t Getss06_kpos_f() { return Ss06_kpos_f; }

    void Setss06_kbw_f(Double_t bw) { Ss06_kbw_f = bw; }
    Double_t Getss06_kbw_f() { return Ss06_kbw_f; }

    void Setss06_karea_f(Double_t area) { Ss06_karea_f = area; }
    Double_t Getss06_karea_f() { return Ss06_karea_f; }

    void Setss06_keta_f(Double_t eta) { Ss06_keta_f = eta; }
    Double_t Getss06_keta_f() { return Ss06_keta_f; }

    void Setss03_se_p1(Double_t en) { Ss03_se_p1 = en; }
    Double_t Getss03_se_p1() { return Ss03_se_p1; }

    void Setss03_spos_p1(Double_t pos) { Ss03_spos_p1 = pos; }
    Double_t Getss03_spos_p1() { return Ss03_spos_p1; }

    void Setss03_sbw_p1(Double_t bw) { Ss03_sbw_p1 = bw; }
    Double_t Getss03_sbw_p1() { return Ss03_sbw_p1; }

    void Setss03_sarea_p1(Double_t area) { Ss03_sarea_p1 = area; }
    Double_t Getss03_sarea_p1() { return Ss03_sarea_p1; }

    void Setss03_seta_p1(Double_t eta) { Ss03_seta_p1 = eta; }
    Double_t Getss03_seta_p1() { return Ss03_seta_p1; }

    void Setss03_ke_p1(Double_t en) { Ss03_ke_p1 = en; }
    Double_t Getss03_ke_p1() { return Ss03_ke_p1; }

    void Setss03_kpos_p1(Double_t pos) { Ss03_kpos_p1 = pos; }
    Double_t Getss03_kpos_p1() { return Ss03_kpos_p1; }

    void Setss03_kbw_p1(Double_t bw) { Ss03_kbw_p1 = bw; }
    Double_t Getss03_kbw_p1() { return Ss03_kbw_p1; }

    void Setss03_karea_p1(Double_t area) { Ss03_karea_p1 = area; }
    Double_t Getss03_karea_p1() { return Ss03_karea_p1; }

    void Setss03_keta_p1(Double_t eta) { Ss03_keta_p1 = eta; }
    Double_t Getss03_keta_p1() { return Ss03_keta_p1; }

    void Setss06_se_p1(Double_t en) { Ss06_se_p1 = en; }
    Double_t Getss06_se_p1() { return Ss06_se_p1; }

    void Setss06_spos_p1(Double_t pos) { Ss06_spos_p1 = pos; }
    Double_t Getss06_spos_p1() { return Ss06_spos_p1; }

    void Setss06_sbw_p1(Double_t bw) { Ss06_sbw_p1 = bw; }
    Double_t Getss06_sbw_p1() { return Ss06_sbw_p1; }

    void Setss06_sarea_p1(Double_t area) { Ss06_sarea_p1 = area; }
    Double_t Getss06_sarea_p1() { return Ss06_sarea_p1; }

    void Setss06_seta_p1(Double_t eta) { Ss06_seta_p1 = eta; }
    Double_t Getss06_seta_p1() { return Ss06_seta_p1; }

    void Setss06_ke_p1(Double_t en) { Ss06_ke_p1 = en; }
    Double_t Getss06_ke_p1() { return Ss06_ke_p1; }

    void Setss06_kpos_p1(Double_t pos) { Ss06_kpos_p1 = pos; }
    Double_t Getss06_kpos_p1() { return Ss06_kpos_p1; }

    void Setss06_kbw_p1(Double_t bw) { Ss06_kbw_p1 = bw; }
    Double_t Getss06_kbw_p1() { return Ss06_kbw_p1; }

    void Setss06_karea_p1(Double_t area) { Ss06_karea_p1 = area; }
    Double_t Getss06_karea_p1() { return Ss06_karea_p1; }

    void Setss06_keta_p1(Double_t eta) { Ss06_keta_p1 = eta; }
    Double_t Getss06_keta_p1() { return Ss06_keta_p1; }

  protected:
    Double32_t Ss03_se_f;
    Double32_t Ss03_spos_f;
    Double32_t Ss03_sbw_f;
    Double32_t Ss03_sarea_f;
    Double32_t Ss03_seta_f;

    Double32_t Ss03_ke_f;
    Double32_t Ss03_kpos_f;
    Double32_t Ss03_kbw_f;
    Double32_t Ss03_karea_f;
    Double32_t Ss03_keta_f;

    Double32_t Ss06_se_f;
    Double32_t Ss06_spos_f;
    Double32_t Ss06_sbw_f;
    Double32_t Ss06_sarea_f;
    Double32_t Ss06_seta_f;

    Double32_t Ss06_ke_f;
    Double32_t Ss06_kpos_f;
    Double32_t Ss06_kbw_f;
    Double32_t Ss06_karea_f;
    Double32_t Ss06_keta_f;

    Double32_t Ss03_se_p1;
    Double32_t Ss03_spos_p1;
    Double32_t Ss03_sbw_p1;
    Double32_t Ss03_sarea_p1;
    Double32_t Ss03_seta_p1;

    Double32_t Ss03_ke_p1;
    Double32_t Ss03_kpos_p1;
    Double32_t Ss03_kbw_p1;
    Double32_t Ss03_karea_p1;
    Double32_t Ss03_keta_p1;

    Double32_t Ss06_se_p1;
    Double32_t Ss06_spos_p1;
    Double32_t Ss06_sbw_p1;
    Double32_t Ss06_sarea_p1;
    Double32_t Ss06_seta_p1;

    Double32_t Ss06_ke_p1;
    Double32_t Ss06_kpos_p1;
    Double32_t Ss06_kbw_p1;
    Double32_t Ss06_karea_p1;
    Double32_t Ss06_keta_p1;

    ClassDef(R3BTraDigi, 1)
};

#endif
