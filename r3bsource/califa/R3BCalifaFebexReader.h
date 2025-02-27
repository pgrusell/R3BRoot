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

#pragma once

#include "R3BReader.h"
#include <Rtypes.h>

class TClonesArray;

struct EXT_STR_h101_CALIFA_t;
typedef struct EXT_STR_h101_CALIFA_t EXT_STR_h101_CALIFA;
class ext_data_struct_info;
/**
 * A reader of CALIFA FEBEX data with UCESB.
 * Receives mapped raw data and converts it to R3BRoot objects.
 * @author H. Alvarez
 * @since May 16, 2017
 */
class R3BCalifaFebexReader : public R3BReader
{
  public:
    /**
     * Standard constructor.
     * Creates instance of the reader. To be called in the steering macro.
     * @param Pointer to a full C structure generated by the Ucesb unpacker.
     * second parameter seems to be the offset of EXT_STR_h101_califa
     * in the overall event structure.
     */
    R3BCalifaFebexReader(EXT_STR_h101_CALIFA*, size_t);

    // Destructor
    virtual ~R3BCalifaFebexReader();

    // Setup structure information
    virtual Bool_t Init(ext_data_struct_info*) override;

    // Read data from full event structure
    virtual Bool_t R3BRead() override;

    // Reset
    virtual void Reset() override;

    // Accessor to select online mode
    void SetOnline(Bool_t option) { fOnline = option; }

  private:
    // An event counter
    unsigned int fNEvent;
    // Reader specific data structure from ucesb
    EXT_STR_h101_CALIFA* fData;
    // Data offset
    size_t fOffset;
    // Don't store data for online
    Bool_t fOnline;
    // Output array
    TClonesArray* fArray;
    TClonesArray* fArraytrig;

  public:
    ClassDefOverride(R3BCalifaFebexReader, 0);
};
