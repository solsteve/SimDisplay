#/ ====================================================================== BEGIN FILE =====
#/ **                             docs - C M A K E L I S T                              **
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

find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
  message(STATUS " Build Documentation (Doxygen)")

  set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)


  #/ =====================================================================================
  # Build target to generate documentation
  #/ -------------------------------------------------------------------------------------

  add_custom_target(docs ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
  )


  # Install generated HTML documentation
  install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html/
    DESTINATION ${CMAKE_INSTALL_DOCDIR}/html
  )
else()
  message( WARNING " - Doxygen not installed, no API documentation will be built" )
endif()

#/ =======================================================================================
#/ **                             docs - C M A K E L I S T                              **
#/ =========================================================================== end FILE ==
