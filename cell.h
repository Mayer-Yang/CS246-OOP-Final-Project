#ifndef CELL_H
#define CELL_H
#include "state.h"
#include "subject.h"
#include "observer.h"

class Cell : public Subject<State> {
  int r, c;
  StateType type = StateType::None;
public:
  Cell(int r, int c);
  //void set_rc(int r, int c);
  void setCell(StateType type);
  //void setDirection(Direction direction);
  //void setRotate(Rotate rotate); 
  int get_r();
  int get_c();
  //StateType get_type();
  //Rotate get_rotate();
  //Direction get_direction();
  //void notify(Subject<State> &whoFrom) override;
};
#endif
