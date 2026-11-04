#/ ====================================================================== BEGIN FILE =====
#/ **                              src - C M A K E L I S T                              **
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

#/ =======================================================================================
#/ Find dependent libraries
#/ ---------------------------------------------------------------------------------------

find_package(Threads REQUIRED)

find_package(GTest)

find_package(PNG   REQUIRED)
find_package(JPEG  REQUIRED)
  set(image_libraries ${PNG_LIBRARIES} ${JPEG_LIBRARIES})

find_package(GDAL   REQUIRED)
  set(geo_libraries ${GDAL_LIBRARIES})

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

find_package(LAPACKE REQUIRED)

if(LAPACKE_FOUND AND LAPACK_FOUND AND BLAS_FOUND)
  set(lapackblas_libraries ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} ${LAPACKE_LIBRARIES})
endif()

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

#/ =======================================================================================
#/ Subdirectories
#/ ---------------------------------------------------------------------------------------

add_subdirectory ( local )

add_subdirectory ( apps )

if (BUILD_DOCS)
    add_subdirectory(docs)
endif()

#/ =======================================================================================
#/ **                              src - C M A K E L I S T                              **
#/ =========================================================================== end FILE ==
