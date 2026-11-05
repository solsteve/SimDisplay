// ====================================================================== BEGIN FILE =====
// **                                A L P H A   D E M O                                **
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
/** @brief  Alpha Demo.
 *  @file   alpha_demo.cc
 *  @author Stephen W. Soliday
 *  @date   2026-Oct-17
 *
 *  Provides the methods for a grid display based simulation.
 */
// =======================================================================================


#include <alpha_demo.hh>

#include <Dice.hh>
#include <appleII_pallet.hh>


// =======================================================================================
/** Constructor.
 * @param cfg pointer to shared configuration.
 */
// ---------------------------------------------------------------------------------------
nmd::AlphaDemo::AlphaDemo(nmd::Configuration* cfg) :
    Simulation(cfg),
    delay{cfg->delay},
    grid{nullptr},
    pallet{nullptr}
{
  // -------------------------------------------------------------------------------------
  Dice::getInstance().seed_set();
  grid   = new ScreenBuffer(cfg->numRows, cfg->numColumns);
  pallet = new AppleII_Pallet();
}


// =======================================================================================
/** Destructor.
 */
// ---------------------------------------------------------------------------------------
nmd::AlphaDemo::~AlphaDemo() {
  // -------------------------------------------------------------------------------------
  delete pallet;
  delete grid;
}


// =======================================================================================
/** Number of buttons.
 * @return number of available buttons.
 */
// ---------------------------------------------------------------------------------------
int nmd::AlphaDemo::getMoreNumberOfButtons() const {
  // -------------------------------------------------------------------------------------
  return 2;
}


// =======================================================================================
/** Get Buttons.
 * @param parent pointer to the parent panel.
 * @param n      button index.
 * @return pointer to a new button instance.
 */
// ---------------------------------------------------------------------------------------
wxAnyButton* nmd::AlphaDemo::getMoreButtons(wxPanel* parent, const int n) {
  // -------------------------------------------------------------------------------------
  if (n==1) {
    wxButton* quitButton  = new wxButton(parent, wxID_ANY, "Alpha");
    quitButton->SetForegroundColour(wxColour(config->uiColors.quitButtonFG));
    quitButton->SetBackgroundColour(wxColour(config->uiColors.quitButtonBG));
    return quitButton;
  }

  if (n==2) {
    wxButton* quitButton  = new wxButton(parent, wxID_ANY, "Beta");
    quitButton->SetForegroundColour(wxColour(config->uiColors.quitButtonFG));
    quitButton->SetBackgroundColour(wxColour(config->uiColors.quitButtonBG));
    return quitButton;
  }

  return nullptr;
}


// =======================================================================================
/** Create a FrameBuffer.
 * @param parent pointer to the parent panel.
 * @return pointer to a new FrameBuffer.
 */
// ---------------------------------------------------------------------------------------
nmd::FrameBuffer* nmd::AlphaDemo::getFrameBuffer(wxPanel* parent) {
  // -------------------------------------------------------------------------------------

  nmd::FrameBuffer* fb = new nmd::FrameBuffer(parent, grid, pallet);

  fb->SetMinSize(wxSize(config->numColumns * config->scale,
                        config->numRows    * config->scale));
  fb->SetBackgroundColour(wxColour(config->uiColors.displayPanel));

  return fb;
}






// =======================================================================================
struct Life {
  // -------------------------------------------------------------------------------------
  int mnLive = 0;
  int mxLive = 0;
  int mnDead = 0;
  int mxDead = 0;
};


// =======================================================================================
/**
 * @param A     pointer to the grid.
 * @param row   cell's row index.
 * @param col   cell's column index.
 * @param alive color index for live cells.
 * @return
 */
// ---------------------------------------------------------------------------------------
int Count(nmd::ScreenBuffer* A,
          const int row, const int col, const int alive) {
  // -------------------------------------------------------------------------------------
  int n = 0;
  if (A->get(row-1, col-1) == alive) n += 1;
  if (A->get(row+0, col-1) == alive) n += 1;
  if (A->get(row+1, col-1) == alive) n += 1;
  if (A->get(row-1, col+0) == alive) n += 1;
  if (A->get(row+1, col+0) == alive) n += 1;
  if (A->get(row-1, col+1) == alive) n += 1;
  if (A->get(row+0, col+1) == alive) n += 1;
  if (A->get(row+1, col+1) == alive) n += 1;
  return n;
}


// =======================================================================================
/** Execise rule.
 * @param[in] a less.
 * @param[in] x value.
 * @param[in] b more.
 * @return
 */
// ---------------------------------------------------------------------------------------
bool rule(const int a, const int x, const int b) {
  // -------------------------------------------------------------------------------------
  if (x < a) { return true; }
  if (x > b) { return true; }
  return false;
}


// =======================================================================================
/** Update cell.
 * @param A     pointer to the grid.
 * @param row   cell's row index.
 * @param col   cell's column index.
 * @param life  reference to the life rules.
 * @param dead  color index for dead cell.
 * @param alive color index for live cell.
 * @return 0 on success.
 */
// ---------------------------------------------------------------------------------------
int updateCell(nmd::ScreenBuffer* A,
               const int row, const int col, 
               const Life& life,
               const int dead, const int alive) {
  // -------------------------------------------------------------------------------------
  int center = A->get(row, col);
  int count  = Count(A, row, col, alive);

  // -------------------------------------------------------------------------------------
  if (alive == center) {
    if (rule(life.mnLive,count,life.mxLive)) {
      A->set(row, col, dead);
    } else {
      A->set(row, col, alive);
    }
    return 0;
  }

  // -------------------------------------------------------------------------------------
  if (dead == center) {
    if (rule(life.mnDead,count,life.mxDead)) {
      A->set(row, col, dead);
    } else {
      A->set(row, col, alive);
    }
    return 0;
  }

  // -------------------------------------------------------------------------------------
  return 1;
}


// =======================================================================================
/** Seed the simulation.
 * @param A     pointer to the grid.
 * @param n     number of live cells.
 * @param dead  color index for dead cell.
 * @param alive color index for live cell.
 */
// ---------------------------------------------------------------------------------------
void seed(nmd::ScreenBuffer* A, const int n, const int dead, const int alive) {
  // -------------------------------------------------------------------------------------
  Dice& dd = Dice::getInstance();
  const int nrow = A->size(0);
  const int ncol = A->size(1);
  A->clear(dead);
  for (int i=0; i<n; i++) {
    int r = dd.randint(nrow-2) + 1;
    int c = dd.randint(ncol-2) + 1;
    A->set(r,c,alive);
  }
}


// =======================================================================================
/** Main Simulation Loop.
 */
// ---------------------------------------------------------------------------------------
void nmd::AlphaDemo::runProcess() {
  // -------------------------------------------------------------------------------------
  const Life life { 2, 3, 3, 3 };

  const int nrow  = grid->size(0);
  const int ncol  = grid->size(1);
  const int nclr  = pallet->size();

  const int BLACK = 0;
  const int WHITE = nclr - 1;
  // -------------------------------------------------------------------------------------
  logger.debug("  Seed life");
  seed(grid, 1500, BLACK, WHITE);
  Thread::msleep(500);

  logger.debug("  Run life");
  while(proc_running) {
    for (int ir=1; ir<nrow-1; ir++) {
      for (int ic=1; ic<ncol-1; ic++) {
        updateCell(grid, ir, ic, life, BLACK, WHITE);
      }
    }
    Thread::msleep(300);
  }

  logger.debug("  End life");
}

// =======================================================================================
// **                                A L P H A   D E M O                                **
// ======================================================================== END FILE =====
