// ====================================================================== BEGIN FILE =====
// **                               E N T R Y   P O I N T                               **
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
/** @brief  Entry Point
 *  @file   entry_point.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-16
 *
 *  Provides the methods for the GUI entry point.
 */
// =======================================================================================


#include <entry_point.hh>
#include <main_frame.hh>


nmd::Configuration* nmd::EntryPoint::startupConfiguration = nullptr;

TLOGGER_REFERENCE(nmd::EntryPoint, logger);


// =======================================================================================
/** Asign the configuration.
 * @param cfg pointer to shared configuration.
 */
// ---------------------------------------------------------------------------------------
void nmd::EntryPoint::SetStartupConfiguration(nmd::Configuration* cfg) {
  // -------------------------------------------------------------------------------------
  startupConfiguration = cfg;
}


// =======================================================================================
/* Run on GUI initialization.
 * @return true on success.
 */
// ---------------------------------------------------------------------------------------
bool nmd::EntryPoint::OnInit() {
  // -------------------------------------------------------------------------------------

  config = startupConfiguration;

  if (config == nullptr) {
    return false;
  }

  MainFrame* mainFrame = new nmd::MainFrame(config);

  SetTopWindow(mainFrame);

  mainFrame->Show(true);

  return true;
}


// =======================================================================================
/* Run on GUI finalization.
 * @return true on success.
 */
// ---------------------------------------------------------------------------------------
int nmd::EntryPoint::OnExit() {
  // -------------------------------------------------------------------------------------

  logger.info("Joining simulation thread");
  config->simulation->join();

  logger.info("Joined");
  return wxApp::OnExit();
}


wxIMPLEMENT_APP_NO_MAIN(nmd::EntryPoint);



// =======================================================================================
// **                               E N T R Y   P O I N T                               **
// ======================================================================== END FILE =====
