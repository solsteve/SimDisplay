// ====================================================================== BEGIN FILE =====
// **                              G R I D   D I S P L A Y                              **
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
/** @brief  Grid Display Panel.
 *  @file   grid_display.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Nov-06
 *
 *  Provides the methods for a display panel.
 */
// =======================================================================================


#include <grid_display.hh>


// =======================================================================================
/** Constructor.
 * @param parent pointer to parent window.
 * @param b      pointer to gridData.
 * @param r      pointer to the color pallet.
 */
// ---------------------------------------------------------------------------------------
nmd::GridDisplay::GridDisplay(wxWindow* parent, nmd::GridData* b, nmd::RGB_Pallet* r)
    : DisplayPanel(parent),
      image(b->size(0), b->size(1)),
      bitmap(),
      gridData{b},
      pallet{r}
{
  // -------------------------------------------------------------------------------------
  SetBackgroundStyle(wxBG_STYLE_PAINT);

  Bind(wxEVT_PAINT, &nmd::GridDisplay::OnPaint, this);
}



// =======================================================================================
/* Update display visual.
 */
// ---------------------------------------------------------------------------------------
void nmd::GridDisplay::updateDisplay() {
  // -------------------------------------------------------------------------------------
  const int nr = gridData->size(0);
  const int nc = gridData->size(1);

  unsigned char* pixels = image.GetData();

  for (int ir = 0; ir < nr; ++ir) {
    for (int ic = 0; ic < nc; ++ic) {

      const int   clr = gridData->get(ir, ic);
      const rgb_s c   = pallet->get(clr);

      const int offset = 3 * (ir * nc + ic);

      pixels[offset    ] = c.red;
      pixels[offset + 1] = c.grn;
      pixels[offset + 2] = c.blu;
    }
  }

  const wxSize size = GetClientSize();

  if (size.x <= 0 || size.y <= 0)
    return;

  wxImage scaled = image.Scale(
      size.x,
      size.y,
      wxIMAGE_QUALITY_NEAREST
                               );

  bitmap = wxBitmap(scaled);

  Refresh(false);

}


// =======================================================================================
/* Execute on paint.
 *
 */
// ---------------------------------------------------------------------------------------
void nmd::GridDisplay::OnPaint(wxPaintEvent&) {
  // -------------------------------------------------------------------------------------

  wxAutoBufferedPaintDC dc(this);

  dc.SetBackground(*wxBLACK_BRUSH);
  dc.Clear();

  if (!bitmap.IsOk())
    return;

  dc.DrawBitmap(bitmap, 0, 0, false);
}

// =======================================================================================
// **                              G R I D   D I S P L A Y                              **
// ======================================================================== END FILE =====
