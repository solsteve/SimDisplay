// ====================================================================== BEGIN FILE =====
// **                                  A P P   M A I N                                  **
// =======================================================================================
// **                                                                                   **
// **  Copyright (c) 2026, Stephen W. Soliday                                           **
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
/** @brief  Demonstration main app.
 *  @file   app_main.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-15
 *
 *  Provides the interface an methods for a demonstration of the SimDisplay.
 */
// =======================================================================================

#include <alpha_demo.hh>
#include <simulation.hh>
#include <entry_point.hh>

#include <TLogger.hh>


// =======================================================================================
int main( int argc, char *argv[], char ** ) {
  // -------------------------------------------------------------------------------------
  TLOGGER_INSTANCE(logger);
  logger.setConsoleLevel(TLogger::DEBUG);

  // setup the configuration
  nmd::Configuration cfg;

  cfg.appTitle     = "Conway's Game of Life";
  cfg.numStatLines = 3;
  cfg.numRows      = 128;
  cfg.numColumns   = 128;
  cfg.scale        = 8;

  // setup the simulation thread
  cfg.simulation = new nmd::AlphaDemo(&cfg);

  // set the Configuration/context
  nmd::EntryPoint::SetStartupConfiguration(&cfg);

  logger.debug("GUI start");
  int result = wxEntry(argc, argv);

  return result;
}


// =======================================================================================
// **                                                             **
// ======================================================================== END FILE =====
