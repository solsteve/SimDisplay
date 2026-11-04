#/ ====================================================================== BEGIN FILE =====
#/ **                            C O M P I L E R   F L A G S                            **
#/ =======================================================================================
#/ **                                                                                   **
#/ **  Copyright (c) 2019-26, Stephen W. Soliday                                        **
#/ **                         stephen.soliday@trncmp.org                                **
#/ **                         http://research.trncmp.org                                **
#/ **                                                                                   **
#/ **  -------------------------------------------------------------------------------  **
#/ **                                                                                   **
#/ **  This program is free software: you can redistribute it and/or modify it under    **
#/ **  the terms of the GNU General Public License as published by the Free Software    **
#/ **  Foundation, either version 3 of the License, or (at your option)                 **
#/ **  any later version.                                                               **
#/ **                                                                                   **
#/ **  This program is distributed in the hope that it will be useful, but WITHOUT      **
#/ **  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    **
#/ **  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.   **
#/ **                                                                                   **
#/ **  You should have received a copy of the GNU General Public License along with     **
#/ **  these files. If not, see <https:#/www.gnu.org/licenses/>.                        **
#/ **                                                                                   **
#/ =======================================================================================

# ---- Global settings ----
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set ( GARCH "-fverbose-asm -ansi -fsigned-char -funsigned-bitfields  \
             -funroll-loops -march=native -mtune=native -fipa-sra -fopenmp" )

set ( GWARN "-W -Wall -Wextra -Wfloat-equal -Wshadow -Wcast-align -Wredundant-decls \
             -Wundef -Wpointer-arith -Wsign-compare -Wconversion -Wpacked -Wno-multichar \
             -Wmissing-noreturn -Wunused-macros -Wendif-labels -Wformat -Wformat-security \
             -Wswitch-default -Wswitch-enum -Wsynth -Wreorder -Winline -Weffc++ \
             -fcheck-new -Wsign-promo -Woverloaded-virtual -Wno-unused-result" )

set ( GFIX   "--param max-inline-insns-single=2000" )

set ( GDEBUG "-g -O0" )

set ( GOPTIM "-O4" )

set ( CMAKE_CXX_FLAGS_RELEASE "-O3 -g ${GOPTIM} ${GWARN} ${GARCH} ${GFIX}" )
set ( CMAKE_CXX_FLAGS_DEBUG   "-O1 -g ${GDEBUG} ${GWARN} ${GARCH}" )


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set ( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_DEBUG} )
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  set ( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS_RELEASE} )
else()
  message(FATAL_ERROR " -- Build type not set" )
endif()


message( STATUS "A -- " ${CMAKE_CXX_FLAGS} )


#/ =======================================================================================
#/ **                            C O M P I L E R   F L A G S                            **
#/ =========================================================================== end FILE ==
