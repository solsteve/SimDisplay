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


// =======================================================================================
void TEST01(void) {
  // -------------------------------------------------------------------------------------
  TLogger& logger = TLogger::getInstance();

  logger.info( "ILH" );
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
