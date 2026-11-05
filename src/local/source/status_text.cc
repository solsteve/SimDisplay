// ====================================================================== BEGIN FILE =====
// **                               S T A T U S   T E X T                               **
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
/** @brief  Status  text.
 *  @file   status_text.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-24
 *
 *  Provides the methods for a collection of text fields.
 */
// =======================================================================================


#include <status_text.hh>


TLOGGER_REFERENCE(nmd::StatusText, logger);


// =======================================================================================
/** Constructor.
 * @param[in] n number of lines.
 */
// ---------------------------------------------------------------------------------------
nmd::StatusText::StatusText(const int n) :
    north{}, south{}, ne{}, nw{}, se{}, sw{}, lines{nullptr}, num_lines{n} {
  // -------------------------------------------------------------------------------------
  lines = new TextConfig[n];
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::StatusText::~StatusText() {
  // -------------------------------------------------------------------------------------
  delete[] lines;
}


// =======================================================================================
/** Assign Text Field.
 * @param pos position in the status text.
 * @param tp  pointer to an instance of a wxTextCtrl.
 *
 *  Assign an instance of a wxTextCtrl to a position.
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setTextCtrl(nmd::TextPos pos, wxTextCtrl* tp) {
  // -------------------------------------------------------------------------------------
  switch(pos) {
    case nmd::TextPos::NORTH: north.setTextCtrl(tp); break;
    case nmd::TextPos::SOUTH: south.setTextCtrl(tp); break;
    case nmd::TextPos::NE:       ne.setTextCtrl(tp); break;
    case nmd::TextPos::NW:       nw.setTextCtrl(tp); break;
    case nmd::TextPos::SE:       se.setTextCtrl(tp); break;
    case nmd::TextPos::SW:       sw.setTextCtrl(tp); break;
    default: logger.error("nmd::StatusText::getTextCtrl: bad enum"); break;
  }
}


// =======================================================================================
/** Set text value.
 * @param     pos position in the status text.
 * @param[in] text value.
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setText(nmd::TextPos pos,
                              const std::string& str) {
  // -------------------------------------------------------------------------------------
  switch(pos) {
    case nmd::TextPos::NORTH: north.setText(str); break;
    case nmd::TextPos::SOUTH: south.setText(str); break;
    case nmd::TextPos::NE:       ne.setText(str); break;
    case nmd::TextPos::NW:       nw.setText(str); break;
    case nmd::TextPos::SE:       se.setText(str); break;
    case nmd::TextPos::SW:       sw.setText(str); break;
    default: logger.error("nmd::StatusText::setText: bad enum"); break;
  }
}


// =======================================================================================
/** Set text foreground.
 * @param     pos position in the status text.
 * @param[in] r   red   component value [0-255].
 * @param[in] g   green component value [0-255].
 * @param[in] b   blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setForeground(nmd::TextPos pos,
                                    const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  switch(pos) {
    case nmd::TextPos::NORTH: north.setForeground(r,g,b); break;
    case nmd::TextPos::SOUTH: south.setForeground(r,g,b); break;
    case nmd::TextPos::NE:       ne.setForeground(r,g,b); break;
    case nmd::TextPos::NW:       nw.setForeground(r,g,b); break;
    case nmd::TextPos::SE:       se.setForeground(r,g,b); break;
    case nmd::TextPos::SW:       sw.setForeground(r,g,b); break;
    default: logger.error("nmd::StatusText::setForeground: bad enum"); break;
  }
}


// =======================================================================================
/** Set text background.
 * @param     pos position in the status text.
 * @param[in] r   red   component value [0-255].
 * @param[in] g   green component value [0-255].
 * @param[in] b   blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setBackground(nmd::TextPos pos,
                                    const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  switch(pos) {
    case nmd::TextPos::NORTH: north.setBackground(r,g,b); break;
    case nmd::TextPos::SOUTH: south.setBackground(r,g,b); break;
    case nmd::TextPos::NE:       ne.setBackground(r,g,b); break;
    case nmd::TextPos::NW:       nw.setBackground(r,g,b); break;
    case nmd::TextPos::SE:       se.setBackground(r,g,b); break;
    case nmd::TextPos::SW:       sw.setBackground(r,g,b); break;
    default: logger.error("nmd::StatusText::setBackground: bad enum"); break;
  }
}


// =======================================================================================
/** Assign Text Field.
 * @param n   line position in the status text.
 * @param tp  pointer to an instance of a wxTextCtrl.
 *
 *  Assign an instance of a wxTextCtrl to a position.
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setTextCtrl(const int n, wxTextCtrl* tp) {
  // -------------------------------------------------------------------------------------
  lines[n].setTextCtrl(tp);
}


// =======================================================================================
/** Set text value.
 * @param     n    line position in the status text.
 * @param[in] text value.
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setText(const int n,
                              const std::string& str) {
  // -------------------------------------------------------------------------------------
  lines[n].setText(str);
}


// =======================================================================================
/** Set text foreground.
 * @param     n line position in the status text.
 * @param[in] r red   component value [0-255].
 * @param[in] g green component value [0-255].
 * @param[in] b blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setForeground(const int n,
                                    const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  lines[n].setForeground(r,g,b);
}


// =======================================================================================
/** Set text background.
 * @param     n line position in the status text.
 * @param[in] r red   component value [0-255].
 * @param[in] g green component value [0-255].
 * @param[in] b blue  component value [0-255].
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::setBackground(const int n,
                                    const uint8_t r, const uint8_t g, const uint8_t b) {
  // -------------------------------------------------------------------------------------
  lines[n].setBackground(r,g,b);
}


// =======================================================================================
/** Update all text fields.
 */
// ---------------------------------------------------------------------------------------
void nmd::StatusText::updateText() {
  // -------------------------------------------------------------------------------------
  north.update();
  south.update();
  ne.update();
  nw.update();
  se.update();
  sw.update();
  for (int i=0; i<num_lines; i++) {
    lines[i].update();
  }
}


// =======================================================================================
// **                               S T A T U S   T E X T                               **
// ======================================================================== END FILE =====
