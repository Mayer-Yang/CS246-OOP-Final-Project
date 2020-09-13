#include "cell.h"
using namespace std;

Cell::Cell(int r, int c): r{r}, c{c}{
	this->setCell(StateType::None);
}

/*void Cell::set_rc(int r, int c) {
	this->r = r;
	this->c = c;
}*/

void Cell::setCell(StateType type) {
	State s{type, Rotate::Origin, r, c};
	this->setState(s);
	//notifyObservers();
}

/*void Cell::setRotate(Rotate rotate) {
	StateType temp_t = get_type();
	Direction temp_d = get_direction();
	setCell(temp_t, rotate, temp_d);
}
void Cell::setDirection(Direction direction) {
	StateType temp_t = get_type();
	Rotate temp_r = get_rotate();
	setCell(temp_t, temp_r, direction);
}*/
int Cell::get_r() {
	return r;
}

int Cell::get_c() {
	return c;
}
/*StateType Cell::get_type() {
	return this->getState().type;
}
Rotate Cell::get_rotate() {
	return this->getState().rotate;
}
Direction Cell::get_direction() {
	return this->getState().direction;
}

void Cell::notify(Subject<State> &whoFrom) {
	Direction d = whoFrom.getState().direction;
	if (d == Direction::None) {
		if (getState().c - whoFrom.getState().c == 1) {
			setDirection(Direction::W);
			notifyObservers();
		}
		else {
			setDirection(Direction::E);
			notifyObservers();
		}
	}
	else if (d == Direction::W) {
		if (getState().c - whoFrom.getState().c == 1) {
			setDirection(Direction::W);
			notifyObservers();
		}
		else  {
			return;
		}
	}
	else {
		if (getState().c - whoFrom.getState().c == -1) {
			setDirection(Direction::E);
			notifyObservers();
		}
		else  {
			return;
		}
	}
}*/




