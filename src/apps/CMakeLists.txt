#/ ====================================================================== BEGIN FILE =====
#/ **                             apps - C M A K E L I S T                              **
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

message(STATUS "Configuring application programs")

#/ =======================================================================================
# Function to add a test program
#/ ---------------------------------------------------------------------------------------

function(build_application prog_name source_name)
  message(STATUS "  Added test program: ${prog_name} from ${source_name}.cc")

  add_executable(${prog_name} ${source_name}.cc)

  target_link_libraries( ${prog_name}
    ${LOCALLIB_NAME}
    ${Callisto_LIBNAME}
    ${lapackblas_libraries}
    ${image_libraries}
    ${geo_libraries}
    ${wxWidgets_LIBRARIES}
  )

  target_include_directories(${prog_name}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
  )
endfunction()

#/ =======================================================================================
# Automatically find all files
#/ ---------------------------------------------------------------------------------------

file(GLOB APP_SOURCE    CONFIGURE_DEPENDS "app_main.cc")
file(GLOB OTHER_SOURCES CONFIGURE_DEPENDS "*.cc")

list(FILTER OTHER_SOURCES EXCLUDE REGEX ".*/app_main\\.cc$")

message(STATUS "App:    ${APP_SOURCE}")
message(STATUS "Others: ${OTHER_SOURCES}")

build_application(${APP_NAME} app_main)

foreach(prog_file ${OTHER_SOURCES})
  get_filename_component(prog_name ${prog_file} NAME_WE)
  build_application(${prog_name} ${prog_name})
endforeach()











#/ =======================================================================================
#/ **                             apps - C M A K E L I S T                              **
#/ =========================================================================== end FILE ==
