#/ ====================================================================== BEGIN FILE =====
#/ **                               B U I L D   G T E S T                               **
#/ =======================================================================================
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

file(GLOB TEST_SOURCES "*.cc")

message( INFO " -- Building unit-test for ${sub_group}: ${TEST_SOURCES}" )

add_executable(test_${sub_group} ${TEST_SOURCES} )

target_link_libraries(test_${sub_group}
    PRIVATE
        Local::App
        ${lapackblas_libraries}
        ${image_libraries}
        ${geo_libraries}
        GTest::gtest
        GTest::gtest_main
)

gtest_discover_tests(test_${sub_group})


#/ =======================================================================================
#/ **                               B U I L D   G T E S T                               **
#/ =========================================================================== end FILE ==
