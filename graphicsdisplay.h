#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer<State> {
  const int row, col;
  Xwindow xw;

 public:
  GraphicsDisplay(int row, int col);
  void drawScore(int score); // change current score
  void drawNext(StateType type); // draw next block
  void drawHiScore(int score); // change High score
  void drawLevel(int lv); // change current level
  void notify(Subject<State> &whoNotified) override;
};
#endif

