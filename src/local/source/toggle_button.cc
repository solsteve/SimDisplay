// ====================================================================== BEGIN FILE =====
// **                         N M D   T O G G L E   B U T T O N                         **
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
/** @brief  Toggle Button.
 *  @file   toggle_button.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-03
 *
 *  Provides the methods for a toggle button.
 */
// =======================================================================================

#include <toggle_button.hh>


// =======================================================================================
nmd::ToggleButton::Listener::Listener() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
nmd::ToggleButton::Listener::~Listener() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
nmd::ToggleButton::ToggleButton(wxPanel* parent, const int id) :
    wxButton(parent, wxID_ANY, "START"),
    button_listener{nullptr},
    button_id{id},
    on_text("START"),
    on_foreground("#ffffff"),
    on_background("#007700"),
    off_text("STOP"),
    off_foreground("#ffffff"),
    off_background("#cc0000"),
    first_press{true},
    onState{true}
{
  // -------------------------------------------------------------------------------------
  this->Bind(wxEVT_BUTTON, &ToggleButton::buttonPressed, this);
  this->SetForegroundColour(on_foreground);
  this->SetBackgroundColour(on_background);
  this->SetLabel(on_text);
}


// =======================================================================================
nmd::ToggleButton::~ToggleButton() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
void nmd::ToggleButton::setListener(nmd::ToggleButton::Listener* L) {
  // -------------------------------------------------------------------------------------
  button_listener = L;
}


// =======================================================================================
void nmd::ToggleButton::setOnText(const std::string& text,
                                  const std::string& fg, const std::string& bg) {
  // -------------------------------------------------------------------------------------
  on_text = text;
  on_foreground = wxColor(fg);
  on_background = wxColor(bg);
}


// =======================================================================================
void nmd::ToggleButton::setOffText(const std::string& text,
                                   const std::string& fg, const std::string& bg) {
  // -------------------------------------------------------------------------------------
  off_text = text;
  off_foreground = wxColor(fg);
  off_background = wxColor(bg);
}


// =======================================================================================
void nmd::ToggleButton::buttonPressed(wxCommandEvent& event) {
  // -------------------------------------------------------------------------------------
  if (button_listener) {
    if (first_press) {
      first_press = false;
      button_listener->firstPress(button_id);
    }
    if (onState) { // button press activates on to the listener
      this->SetForegroundColour(off_foreground);
      this->SetBackgroundColour(off_background);
      this->SetLabel(off_text);
      onState = false;
      button_listener->on(button_id);
    } else {       // button press activates off to the listener
      this->SetForegroundColour(on_foreground);
      this->SetBackgroundColour(on_background);
      this->SetLabel(on_text);
      button_listener->off(button_id);
      onState = true;
    }
  }
}


// =======================================================================================
// **                         N M D   T O G G L E   B U T T O N                         **
// ======================================================================== END FILE =====
