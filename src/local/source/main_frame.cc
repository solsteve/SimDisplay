// ====================================================================== BEGIN FILE =====
// **                                M A I N   F R A M E                                **
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
/** @brief  Main Appplication Frame.
 *  @file   main_frame.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-15
 *
 *  Provides the methods for the main application frame.
 */
// =======================================================================================


#include <main_frame.hh>
#include <status_text.hh>

#include <StringTool.hh>


// =======================================================================================
/** Constructor
 * @param cfg pointer to shared configuration.
 */
// ---------------------------------------------------------------------------------------
nmd::MainFrame::MainFrame(nmd::Configuration* cfg) :
    wxFrame(nullptr,
            wxID_ANY,
            cfg->appTitle,
            wxDefaultPosition),
    config(cfg),
    sim_thread{cfg->simulation},
    displayPanel{nullptr},
    statusText{nullptr},
    n_stat_lines{0},
    refreshTimer(this)
{
  // ----- build subpanels ---------------------------------------------------------------


  wxPanel* centerPanel  = new wxPanel(this,        wxID_ANY);
  wxPanel* workPanel    = new wxPanel(centerPanel, wxID_ANY);
  wxPanel* controlPanel = new wxPanel(centerPanel, wxID_ANY);

  controlPanel->SetBackgroundColour(wxColour(config->uiColors.controlPanel));

  // -------------------------------------------------------------------------------------

  displayPanel  = config->simulation->getDisplayPanel(workPanel);

  statusText   = config->simulation->getStatusText();
  n_stat_lines = statusText->size();


  // -------------------------------------------------------------------------------------

  wxTextCtrl* temp = nullptr;


  // ----- build north panel -------------------------------------------------------------

  wxPanel*    northPanel = new wxPanel(this, wxID_ANY);
  wxBoxSizer* northSizer = new wxBoxSizer(wxHORIZONTAL);

  temp = new wxTextCtrl(northPanel, wxID_ANY, "north west",
                        wxDefaultPosition, wxSize(50,-1), wxTE_LEFT | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::NW, temp);
  northSizer->Add(temp, 3, wxEXPAND | wxALL, 1);

  temp = new wxTextCtrl(northPanel, wxID_ANY, "north",
                        wxDefaultPosition, wxSize(50,-1), wxTE_CENTER | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::NORTH, temp);
  northSizer->Add(temp, 2, wxEXPAND | wxALL, 1);

  temp = new wxTextCtrl(northPanel, wxID_ANY, "south west",
                        wxDefaultPosition, wxSize(50,-1), wxTE_RIGHT | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::NE, temp);
  northSizer->Add(temp, 3, wxEXPAND | wxALL, 1);

  northPanel->SetSizer(northSizer);
  northPanel->SetBackgroundColour(wxColour(config->uiColors.northPanel));


  // ----- build south panel -------------------------------------------------------------

  wxPanel*    southPanel = new wxPanel(this, wxID_ANY);
  wxBoxSizer* southSizer = new wxBoxSizer(wxHORIZONTAL);

  temp = new wxTextCtrl(southPanel, wxID_ANY, "south west",
                        wxDefaultPosition, wxSize(50,-1), wxTE_LEFT | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::SW, temp);
  southSizer->Add(temp, 2, wxEXPAND | wxALL, 1);

  temp = new wxTextCtrl(southPanel, wxID_ANY, "south",
                        wxDefaultPosition, wxSize(50,-1), wxTE_CENTER | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::SOUTH, temp);
  southSizer->Add(temp, 1, wxEXPAND | wxALL, 1);

  temp = new wxTextCtrl(southPanel, wxID_ANY, "south east",
                        wxDefaultPosition, wxSize(50,-1), wxTE_RIGHT | wxBORDER_SUNKEN);
  statusText->setTextCtrl(nmd::TextPos::SE, temp);
  southSizer->Add(temp, 2, wxEXPAND | wxALL, 1);

  southPanel->SetSizer(southSizer);
  southPanel->SetBackgroundColour(wxColour(config->uiColors.southPanel));


  // ----- build status lines ------------------------------------------------------------

  wxPanel*    linesPanel = new wxPanel(workPanel, wxID_ANY);
  wxBoxSizer* linesSizer = new wxBoxSizer(wxVERTICAL);

  for (int i=0; i<n_stat_lines; i++) {
    char buffer[32];
    sprintf(buffer, "Line %d", i);
    temp = new wxTextCtrl(linesPanel, wxID_ANY, buffer);
    statusText->setTextCtrl(i, temp);
    linesSizer->Add(temp, 0, wxEXPAND | wxALL, 1);
  }

  linesPanel->SetSizer(linesSizer);
  linesPanel->SetBackgroundColour(wxColour(config->uiColors.linesPanel));


  // ----- assemble work panel -----------------------------------------------------------

  wxBoxSizer* workSizer = new wxBoxSizer(wxVERTICAL);

  workSizer->Add(displayPanel, 1, wxEXPAND | wxALL, 1);
  workSizer->Add(linesPanel,   0, wxEXPAND | wxALL, 1);

  workPanel->SetSizer(workSizer);

  // ----- assemble control panel --------------------------------------------------------

  wxBoxSizer* controlSizer = new wxBoxSizer(wxVERTICAL);

  const int num_buttons = config->simulation->getNumberOfButtons();

  for (int ib=0; ib<num_buttons; ib++) {
    wxAnyButton* button = config->simulation->getButton(controlPanel, ib);
    controlSizer->Add(button, 0, wxEXPAND | wxALL, 3);
  }

  controlPanel->SetSizer(controlSizer);
  controlPanel->SetBackgroundColour(wxColour(config->uiColors.controlPanel));


  // ----- assemble center panel ---------------------------------------------------------

  wxBoxSizer* centerSizer = new wxBoxSizer(wxHORIZONTAL);

  centerSizer->Add(workPanel,    1, wxEXPAND | wxALL, 1);
  centerSizer->Add(controlPanel, 0, wxEXPAND | wxALL, 1);

  centerPanel->SetSizer(centerSizer);
  centerPanel->SetBackgroundColour(wxColour(config->uiColors.centerPanel));


  // ----- assemble main frame -----------------------------------------------------------

  wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);

  frameSizer->Add(northPanel,  0, wxEXPAND | wxALL, 1);
  frameSizer->Add(centerPanel, 1, wxEXPAND | wxALL, 1);
  frameSizer->Add(southPanel,  0, wxEXPAND | wxALL, 1);

  this->SetSizer(frameSizer);

  this->SetBackgroundColour(wxColour(config->uiColors.mainFrame));

  frameSizer->Fit(this);

  // -------------------------------------------------------------------------------------

  config->refreshTimer = &refreshTimer;

  Bind(wxEVT_TIMER,
       &nmd::MainFrame::OnRefreshTimer,
       this,
       refreshTimer.GetId());
}


// =======================================================================================
/** Refresh
 */
// ---------------------------------------------------------------------------------------
void nmd::MainFrame::OnRefreshTimer(wxTimerEvent&) {
  // -------------------------------------------------------------------------------------
  displayPanel->updateDisplay();
  statusText->updateText();
}


// =======================================================================================
// **                                M A I N   F R A M E                                **
// ======================================================================== END FILE =====
