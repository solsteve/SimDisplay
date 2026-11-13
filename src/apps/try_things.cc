// ====================================================================== BEGIN FILE =====
// **                                T R Y   T H I N G S                                **
// =======================================================================================
// **                                                                                   **
// **  Copyright (c) 202y, Stephen W. Soliday                                           **
// **                      stephen.soliday@trncmp.org                                   **
// **                      http://research.trncmp.org                                   **
// **                                                                                   **
// **  -------------------------------------------------------------------------------  **
// **                                                                                   **
// **  This program is free software: you can redistribute it and/or modify it under    **
// **  the terms of the GNU General Public License as published by the Free Software    **
// **  Foundation, either version 3 of the License, or (at your option)                 **
// **  any later version.                                                               **
// **                                                                                   **
// **  This program is distributed in the hope that it will be useful, but WITHOUT      **
// **  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS    **
// **  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.   **
// **                                                                                   **
// **  You should have received a copy of the GNU General Public License along with     **
// **  this program. If not, see <http://www.gnu.org/licenses/>.                        **
// **                                                                                   **
// ----- Modification History ------------------------------------------------------------
//
/** @brief  
 *  @file   TryThings.cc
 *  @author Stephen W. Soliday
 *  @date   202y-Mmm-dd
 *
 *  Provides the interface an methods for experimantation.
 */
// =======================================================================================

#include <trncmp.hh>
#include <TLogger.hh>

#include <linalg/vec2.hh>



void display(const vec2& v) {
  const real8_t x = v.x;
  const real8_t y = v.y;
  std::cout << "X: " << x << "  Y: " << y << std::endl;
}


// =======================================================================================
void TEST01(void) {
  // -------------------------------------------------------------------------------------
  vec2 v(1.0,2.0);
  real8_t x = 3.0;
  real8_t y = 4.0;
  display(v);
  display({x,y});
  display(vec2{5.3});
}


// =======================================================================================
int main( void ) {
  // -------------------------------------------------------------------------------------

  TLogger::getInstance().setConsoleLevel( TLogger::DEBUG );

  TEST01();

  return 0;
}


// =======================================================================================
// **                                T R Y   T H I N G S                                **
// ======================================================================== END FILE =====
