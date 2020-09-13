#ifndef TD_H
#define TD_H
#include <vector>
#include "observer.h"
#include "state.h"
#undef None
class Cell; 


class TextDisplay: public Observer<State> {
  std::vector<std::vector<char>> theDisplay;
  const int row = 20;
  const int col = 11;
  int score = 0;
  int hi_score = 0;
  int level = 0;
  StateType type = StateType::None;
public:
  TextDisplay();
  void reset_lv(int lv);
  void reset_hi_score(int h_s);
  void reset_score(int s);
  void reset_type(StateType t);
  void notify(Subject<State> &whoNotified) override;

  friend std::ostream& operator<<(std::ostream& out, const TextDisplay& td);
};
#endif
