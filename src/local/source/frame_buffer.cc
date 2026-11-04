// ====================================================================== BEGIN FILE =====
// **                              F R A M E   B U F F E R                              **
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
/** @brief  Frame Buffer
 *  @file   frame_buffer.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-13
 *
 *  Provides the methods for a frame buffer.
 */
// =======================================================================================

#include <frame_buffer.hh>


// =======================================================================================
nmd::FrameBuffer::FrameBuffer(wxWindow* parent, nmd::ScreenBuffer* b, nmd::RGB_Pallet* r)
    : wxPanel(parent, wxID_ANY),
      image(b->size(0), b->size(1)),
      bitmap(),
      buffer{b},
      pallet{r}
{
  // -------------------------------------------------------------------------------------
  SetBackgroundStyle(wxBG_STYLE_PAINT);

  Bind(wxEVT_PAINT, &nmd::FrameBuffer::OnPaint, this);
}



// =======================================================================================
void nmd::FrameBuffer::updateFrame() {
  // -------------------------------------------------------------------------------------
    const int nr = buffer->size(0);
    const int nc = buffer->size(1);

    unsigned char* pixels = image.GetData();

    for (int ir = 0; ir < nr; ++ir) {
        for (int ic = 0; ic < nc; ++ic) {

            const int   clr = buffer->get(ir, ic);
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
void nmd::FrameBuffer::OnPaint(wxPaintEvent&) {
  // -------------------------------------------------------------------------------------

  wxAutoBufferedPaintDC dc(this);

  dc.SetBackground(*wxBLACK_BRUSH);
  dc.Clear();

  if (!bitmap.IsOk())
    return;

  dc.DrawBitmap(bitmap, 0, 0, false);
}

// =======================================================================================
// **                              F R A M E   B U F F E R                              **
// ======================================================================== END FILE =====
