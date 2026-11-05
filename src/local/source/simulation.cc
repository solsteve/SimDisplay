// ====================================================================== BEGIN FILE =====
// **                            N M D   S I M U L A T I O N                            **
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
/** @brief  Abstract Simulation.
 *  @file   simulation.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-17
 *
 *  Provides the methods for the abstract simulation.
 */
// =======================================================================================


#include <simulation.hh>


TLOGGER_REFERENCE(nmd::Simulation, logger);


// =======================================================================================
/**Constructor.
 * @param cfg pointer to shared configuration.
 */
// ---------------------------------------------------------------------------------------
nmd::Simulation::Simulation(nmd::Configuration* cfg) :
    config{cfg},
    statusText{nullptr},
    proc_running{false}
{
  // -------------------------------------------------------------------------------------
  statusText = new nmd::StatusText(cfg->numStatLines);
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::Simulation::~Simulation() {
  // -------------------------------------------------------------------------------------
  delete statusText;
}


// =======================================================================================
/** Get Status Text.
 * @return pointer to status text.
 */
// ---------------------------------------------------------------------------------------
nmd::StatusText* nmd::Simulation::getStatusText() {
  // -------------------------------------------------------------------------------------
  return statusText;
}


// =======================================================================================
/** Get number of buttons.
 * @return number of nuttons.
 */
// ---------------------------------------------------------------------------------------
int nmd::Simulation::getNumberOfButtons() const {
  // -------------------------------------------------------------------------------------
  return 2 + getMoreNumberOfButtons();
}


// =======================================================================================
/** Get a button.
 * @param     parent pointer to parent panel.
 * @param[in] n      button index.
 * @return pointer to button instance.
 */
// ---------------------------------------------------------------------------------------
wxAnyButton* nmd::Simulation::getButton(wxPanel* parent, const int n) {
  // -------------------------------------------------------------------------------------
  if (n==0) {
    ToggleButton* tb = new ToggleButton(parent, 42);
    tb->setListener(this);
    return tb;
  }

  wxAnyButton* mb = getMoreButtons(parent, n);
  if (mb) { return mb; }

  if (n == 1 + getMoreNumberOfButtons()) {
    wxButton* quitButton  = new wxButton(parent, wxID_ANY, "QUIT");
    quitButton->SetForegroundColour(wxColour(config->uiColors.quitButtonFG));
    quitButton->SetBackgroundColour(wxColour(config->uiColors.quitButtonBG));
    quitButton->Bind(wxEVT_BUTTON, &Simulation::quitSim, this);
    return quitButton;
  }

  logger.error("Control panel only has %d buttons", this->getNumberOfButtons());
  return nullptr;
}


// =======================================================================================
/** Run on first press.
 * @param[in] id sender id number.
 */
// ---------------------------------------------------------------------------------------
void nmd::Simulation::firstPress(const int id) {
  // -------------------------------------------------------------------------------------
  logger.debug("Simulation:  firstPress (%d)", id);
  this->start();
  config->refreshTimer->Start(33);
}


// =======================================================================================
/** Start Inner Loop.
 * @param[in] id sender id number.
 */
// ---------------------------------------------------------------------------------------
void nmd::Simulation::on(const int id) {
  // -------------------------------------------------------------------------------------
  logger.debug("Simulation:  on  (%d)", id);
  proc_running = true;
}


// =======================================================================================
/** Stop Inner Loop.
 * @param[in] id sender id number.
 */
// ---------------------------------------------------------------------------------------
void nmd::Simulation::off(const int id) {
  // -------------------------------------------------------------------------------------
  logger.debug("Simulation:  off (%d)", id);
  proc_running = false;
}


// =======================================================================================
/** Signal Stop.
 */
// ---------------------------------------------------------------------------------------
void nmd::Simulation::quitSim(wxCommandEvent&) {
  // -------------------------------------------------------------------------------------
  proc_running = false;
  this->stop();
  logger.debug("Stop Thread Requested");
}


// =======================================================================================
/** Thread loop.
 */
// ---------------------------------------------------------------------------------------
void nmd::Simulation::run() {
  // -------------------------------------------------------------------------------------
  logger.debug("Start Thread");

  while(running_ && !stop_requested_) {
    if (proc_running) {
      runProcess();
    }
  }

  logger.debug("End Thread");
}


// =======================================================================================
// **                            N M D   S I M U L A T I O N                            **
// ======================================================================== END FILE =====
