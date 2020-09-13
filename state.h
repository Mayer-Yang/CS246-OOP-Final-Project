#ifndef STATE_H
#define STATE_H
enum class Rotate { Origin, Cw1, Cw2, Cw3 };
enum class StateType { Q_m, Star, I, J, L, O, S, Z, T, None };
struct State {
	StateType type;  
	Rotate rotate;
	int r, c;
};
#endif
