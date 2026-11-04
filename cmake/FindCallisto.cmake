#/ ====================================================================== BEGIN FILE =====
#/ **                     F I N D   C A L L I S T O   L I B R A R Y                     **
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


find_path(Callisto_INCLUDE_DIR
  NAMES trncmp.hh
  PATHS
    $ENV{HOME}/.local/include/Callisto
    /usr/local/include
    /usr/include
)

find_library(Callisto_LIBRARY
  NAMES Callisto callisto
  PATHS
    $ENV{HOME}/.local/lib
    /usr/local/lib
    /usr/lib
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Callisto
  REQUIRED_VARS
    Callisto_LIBRARY
    Callisto_INCLUDE_DIR
)

if(Callisto_FOUND AND NOT TARGET Callisto::Callisto)
  add_library(Callisto::Callisto STATIC IMPORTED)

  set_target_properties(Callisto::Callisto PROPERTIES
    IMPORTED_LOCATION ${Callisto_LIBRARY}
    INTERFACE_INCLUDE_DIRECTORIES ${Callisto_INCLUDE_DIR}
  )
endif()


message(STATUS "Found: ${CMAKE_SOURCE_DIR}/FindCallisto.cmake")
message(STATUS "    Library:   ${Callisto_LIBRARY}")
message(STATUS "    Headers:   ${Callisto_INCLUDE_DIR}")


#/ =======================================================================================
#/ **                     F I N D   C A L L I S T O   L I B R A R Y                     **
#/ =========================================================================== end FILE ==
