##############################################################################
#   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    #
#   Copyright (C) 2019-2025 Members of R3B Collaboration                     #
#                                                                            #
#             This software is distributed under the terms of the            #
#                 GNU General Public Licence (GPL) version 3,                #
#                    copied verbatim in the file "LICENSE".                  #
#                                                                            #
# In applying this license GSI does not waive the privileges and immunities  #
# granted to it by virtue of its status as an Intergovernmental Organization #
# or submit itself to any jurisdiction.                                      #
##############################################################################

# Create a library called "libR3BTofi" which includes the source files given
# in the array. The extension is already found. Any number of sources could be
# listed here.

set(SRCS
    #Put here your sourcefiles
    sim/R3BTofi.cxx
    sim/R3BGeoTofi.cxx
    pars/R3BGeoTofiPar.cxx
    pars/R3BTofiDigiPar.cxx)

set(HEADERS
    #Put here your sourcefiles
    sim/R3BTofi.h
    sim/R3BGeoTofi.h
    pars/R3BGeoTofiPar.h
    pars/R3BTofiDigiPar.h)

add_library_with_dictionary(
    LIBNAME
    R3BTofi
    LINKDEF
    TofiLinkDef.h
    HEADERS
    ${HEADERS}
    SRCS
    ${SRCS}
    INCLUDEDIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    pars
    sim
    DEPENDENCIES
    R3BTCal
    R3BTracking)
