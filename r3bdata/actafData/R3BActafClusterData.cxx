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

#include "R3BActafClusterData.h"
#include <fmt/core.h>

R3BActafClusterData::R3BActafClusterData(UInt_t side,
                                         double xpos,
                                         double ypos,
                                         double zpos,
                                         double energy,
                                         TVector3 track,
                                         std::vector<uint16_t> padlist,
                                         double chi2polarfit)
    : fSide(side)
    , fXPos(xpos)
    , fYPos(ypos)
    , fZPos(zpos)
    , fEnergy(energy)
    , fTrack(track)
    , fPadList(padlist)
    , fChi2PolarFit(chi2polarfit)
{
}

std::string R3BActafClusterData::toString() const
{
    return fmt::format("Side : {}, X-Pos: {}, Y-Pos: {}, Z-Pos: {}, Energy: {}, Pads: {}, Chi2PolarFit : {}",
                       GetSide(),
                       GetXpos(),
                       GetYpos(),
                       GetZpos(),
                       GetEnergy(),
                       GetNbOfPads(),
                       GetChi2PolarFit());
}

void R3BActafClusterData::Print(const Option_t*) const { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& os, const R3BActafClusterData& data)
{
    os << data.toString();
    return os;
}

ClassImp(R3BActafClusterData)
