#/ ====================================================================== BEGIN FILE =====
#/ **                           Top Level - C M A K E L I S T                           **
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
#/ ----- Modification History ------------------------------------------------------------
#/
#/ @author  Stephen W. Soliday
#/ @date    2019-Apr-18
#/ @date    2021-Nov-21 (Major refactor)
#/ @date    2022-Feb-04 Establishment of Core4
#/ @date    2026-Jan-31 Refactoring of the CMake build generators.
#/
#/ =======================================================================================

cmake_minimum_required(VERSION 3.28)


set ( APP_NAME         SimDisplay )
set ( LOCALLIB_NAME    mylocal )

set( HOME $ENV{HOME} )

set ( CMAKE_BUILD_PARALLEL_LEVEL 64 )

project(${LOCALLIB_NAME}
  VERSION "1.0.0"
  LANGUAGES CXX
  DESCRIPTION "Template application using Callisto library"
)

include ( GNUInstallDirs )


#/ =======================================================================================
#/ Check whether the user has selected a BUILD_TYPE
#/ ---------------------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_UTESTS ON)
    set(BUILD_CTESTS ON)
    set(BUILD_DOCS   OFF)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(BUILD_UTESTS OFF)
    set(BUILD_CTESTS OFF)
    set(BUILD_DOCS   ON)
else()
    message(ERROR " -- Unsupported build type: ${CMAKE_BUILD_TYPE}")
    message(FATAL_ERROR " -- Use: Release or Debug")
endif()

message(STATUS "Configuring ${LOCALLIB_NAME} (${CMAKE_BUILD_TYPE})")

#/ =======================================================================================
#/ Include configuration
#/ ---------------------------------------------------------------------------------------

# Set module path for custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Include compiler flags configuration
include(CompilerFlags)

find_package(Callisto REQUIRED)

#/ =======================================================================================
#/ Set output directories
#/ ---------------------------------------------------------------------------------------

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(src)

message(STATUS "Configuring ${APP_NAME} (${CMAKE_BUILD_TYPE})")



#/ =======================================================================================
#/ **                           Top Level - C M A K E L I S T                           **
#/ =========================================================================== end FILE ==
