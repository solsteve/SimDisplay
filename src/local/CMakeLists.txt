#/ ====================================================================== BEGIN FILE =====
#/ **                             local - C M A K E L I S T                             **
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

file ( GLOB_RECURSE my_sources CONFIGURE_DEPENDS "*.cc" )

add_library(${LOCALLIB_NAME} STATIC ${my_sources})

add_library(Local::App ALIAS ${LOCALLIB_NAME})

message(STATUS "APP Name     -> ${APP_NAME}")
message(STATUS "Local Lib    -> ${LOCALLIB_NAME}")
message(STATUS "Include Path -> ${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(${LOCALLIB_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(${LOCALLIB_NAME} PUBLIC cxx_std_17)

target_link_libraries(${LOCALLIB_NAME}
  PUBLIC
    Callisto::Callisto
)

if (BUILD_UTESTS)
    add_subdirectory(utest)
endif()

#/ =======================================================================================
#/ **                             local - C M A K E L I S T                             **
#/ =========================================================================== end FILE ==
