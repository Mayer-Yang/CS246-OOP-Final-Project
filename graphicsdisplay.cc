#include <iostream>
#include "graphicsdisplay.h"
#include "state.h"
#include "subject.h"
#include "string"
using namespace std;
#undef None

GraphicsDisplay::GraphicsDisplay(int row, int col):
 row{row}, col{col}, xw{col, row} {
 xw.fillRectangle(0, 0, col, 50, Xwindow::Black);
 xw.drawString(10, 10, "Level:    0", 0);
 xw.drawString(10, 20, "Score:    0", 0);
 xw.drawString(10, 30, "Hi Score:    0", 0);
 xw.fillRectangle(0, 40, col, row - 130, Xwindow::White);
 xw.fillRectangle(0, 590, col, 70, Xwindow::Black);
 xw.drawString(10, 600, "Next:", 0);
}

void GraphicsDisplay::drawScore(int score) {
	xw.fillRectangle(10, 10, col, 10, Xwindow::Black);
	xw.drawString(10, 20, "Score:    " + to_string(score), 0);
} // change current score
void GraphicsDisplay::drawNext(StateType type) {
	xw.fillRectangle(10, 600, col, 60, Xwindow::Black);
	if (type == StateType::I) {
		xw.fillRectangle(10, 600, 120, 30, Xwindow::Red);
	}
	else if (type == StateType::J) {
		xw.fillRectangle(10, 600, 30, 30, Xwindow::Green);
		xw.fillRectangle(10, 630, 90, 30, Xwindow::Green);
	}
	else if (type == StateType::L) {
		xw.fillRectangle(70, 600, 30, 30, Xwindow::Blue);
		xw.fillRectangle(10, 630, 90, 30, Xwindow::Blue);
	}
	else if (type == StateType::O) {
		xw.fillRectangle(10, 600, 60, 30, Xwindow::Cyan);
		xw.fillRectangle(10, 630, 60, 30, Xwindow::Cyan);
	}
	else if (type == StateType::S) {
		xw.fillRectangle(40, 600, 60, 30, Xwindow::Yellow);
		xw.fillRectangle(10, 630, 60, 30, Xwindow::Yellow);
	}
	else if (type == StateType::Z) {
		xw.fillRectangle(10, 600, 60, 30, Xwindow::Magenta);
		xw.fillRectangle(40, 630, 60, 30, Xwindow::Magenta);
	}
	else if (type == StateType::T) {
		xw.fillRectangle(10, 600, 90, 30, Xwindow::Orange);
		xw.fillRectangle(40, 630, 30, 30, Xwindow::Orange);
	}
} // draw next block
void GraphicsDisplay::drawHiScore(int score) {
	xw.fillRectangle(10, 20, col, 10, Xwindow::Black);
	xw.drawString(10, 30, "Hi Score:    " + to_string(score), 0);
} // change High score
void GraphicsDisplay::drawLevel(int lv) {
	xw.fillRectangle(10, 0, col, 10, Xwindow::Black);
	xw.drawString(10, 10, "Level:    " + to_string(lv), 0);
} // change current level


void GraphicsDisplay::notify(Subject<State> &whoNotified) {
  auto state = whoNotified.getState();
  const int cellSize = 30;
  switch(state.type) {
   case StateType::I:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Red);
    break;
   case StateType::J:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Green);
    break;
   case StateType::L:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Blue);
    break;
   case StateType::O:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Cyan);
    break;
   case StateType::S:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Yellow);
    break;
   case StateType::Z:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Magenta);
    break;
   case StateType::T:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Orange);
    break;
   case StateType::Star:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Brown);
    break;
   case StateType::None:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::White);
    break; 
   case StateType::Q_m:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::Black);
    break;
   default:
    xw.fillRectangle(state.c * cellSize, state.r * cellSize + 40, cellSize, cellSize, Xwindow::White);
  }
}
   
