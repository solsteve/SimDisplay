// ====================================================================== BEGIN FILE =====
// **                               T E X T   C O N F I G                               **
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
/** @brief  Text Configuration.
 *  @file   text_config.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-22
 *
 *  Provides the methods for custom text control field.
 */
// =======================================================================================


#include <text_config.hh>


// =======================================================================================
/** Constructor.
 */
// ---------------------------------------------------------------------------------------
nmd::TextConfig::TextConfig()
    : buffer{"blank"},
      foreground{0,0,0},
      background{255,255,255},
      buffer_changed{true},
      foreground_changed{true},
      background_changed{true},
      textCtrl{nullptr},
      mtx{}
{
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::TextConfig::~TextConfig() {
  // -------------------------------------------------------------------------------------
}


// =======================================================================================
/** Set text value.
 * @param[in] text value.
 */
// ---------------------------------------------------------------------------------------
void nmd::TextConfig::setText(const std::string& str) {
  // -------------------------------------------------------------------------------------
  std::lock_guard<std::mutex> lock(mtx);
  buffer         = str;
  buffer_changed = true;
}


// =======================================================================================
/** Set text foreground.
 * @param[in] r   red   component value [0-255].
 * @param[in] g   green component value [0-255].
 * @param[in] b   blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::TextConfig::setForeground(const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  std::lock_guard<std::mutex> lock(mtx);
  foreground.red     = r;
  foreground.grn     = g;
  foreground.blu     = b;
  foreground_changed = true;
}


// =======================================================================================
/** Set text background.
 * @param[in] r   red   component value [0-255].
 * @param[in] g   green component value [0-255].
 * @param[in] b   blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::TextConfig::setBackground(const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  std::lock_guard<std::mutex> lock(mtx);
  background.red     = r;
  background.grn     = g;
  background.blu     = b;
  background_changed = true;
}


// =======================================================================================
/** Update text field.
 */
// ---------------------------------------------------------------------------------------
bool nmd::TextConfig::update() {
  // -------------------------------------------------------------------------------------
  std::lock_guard<std::mutex> lock(mtx);

  if (buffer_changed) {
    textCtrl->ChangeValue(buffer);
  }

  if (foreground_changed) {
    textCtrl->SetForegroundColour(wxColor(
        background.red,
        background.grn,
        background.blu));
  }

  if (background_changed) {
    textCtrl->SetBackgroundColour(wxColor(
        foreground.red,
        foreground.grn,
        foreground.blu));
  }

  return false;
}


// =======================================================================================
// **                               T E X T   C O N F I G                               **
// ======================================================================== END FILE =====
