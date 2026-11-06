// ====================================================================== BEGIN FILE =====
// **                             D I S P L A Y   P A N E L                             **
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
/** @brief  Display Panel.
 *  @file   display_panel.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides the methods for a display panel.
 */
// =======================================================================================


#include <display_panel.hh>


// =======================================================================================
/** Constructor.
 * @param parent pointer to parent window.
 * @param b      pointer to gridData.
 * @param r      pointer to the color pallet.
 */
// ---------------------------------------------------------------------------------------
nmd::DisplayPanel::DisplayPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
  // -------------------------------------------------------------------------------------
  SetBackgroundStyle(wxBG_STYLE_PAINT);

  Bind(wxEVT_PAINT, &nmd::DisplayPanel::OnPaint, this);
}


// =======================================================================================
// **                             D I S P L A Y   P A N E L                             **
// ======================================================================== END FILE =====
