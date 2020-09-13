#include <iostream>
#include <vector>
#include <string>
#include "cell.h"
#include "subject.h"
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay() {
	for (int i = 0; i < row; ++i) {
		theDisplay.emplace_back(vector<char>(col));
	}

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (i == 0 || i == 19) {
				theDisplay[i][j] = '-';
			}
			else {
				theDisplay[i][j] = ' ';
			}	
		}
	}
}

void TextDisplay::reset_lv(int lv) {
	this->level = lv;
}
void TextDisplay::reset_hi_score(int h_s) {
	this->hi_score = h_s;
}
void TextDisplay::reset_score(int s) {
	this->score = s;
}
void TextDisplay::reset_type(StateType t) {
	this->type = t;
}

void TextDisplay::notify(Subject<State> &whoNotified) {
	State curState = whoNotified.getState();
	if (curState.type == StateType::I) {
		theDisplay[curState.r + 1][curState.c] = 'I';
	} else if (curState.type == StateType::J) {
		theDisplay[curState.r + 1][curState.c] = 'J';
	} else if (curState.type == StateType::L) {
		theDisplay[curState.r + 1][curState.c] = 'L';
	} else if (curState.type == StateType::O) {
		theDisplay[curState.r + 1][curState.c] = 'O';

	} else if (curState.type == StateType::S) {
		theDisplay[curState.r + 1][curState.c] = 'S';

	} else if (curState.type == StateType::Z) {
		theDisplay[curState.r + 1][curState.c] = 'Z';

	} else if (curState.type == StateType::T) {
		theDisplay[curState.r + 1][curState.c] = 'T';
	} else if (curState.type == StateType::Star) {
		theDisplay[curState.r + 1][curState.c] = '*';
	} else if (curState.type == StateType::Q_m) {
		theDisplay[curState.r + 1][curState.c] = '?';
	}
	else {
		theDisplay[curState.r + 1][curState.c] = ' ';
	}
}

std::ostream& operator<<(std::ostream &out, const TextDisplay &td) {
	out << "Level:     " << td.level << endl;
	out << "Score:     " << td.score << endl;
	out << "Hi Score:  " << td.hi_score << endl;
	for (int i = 0; i < td.row; ++i) {
		for (int j = 0; j < td.col; ++j) {
			out << td.theDisplay[i][j];
		}
		out << endl;
	}
	out << "Next:" << endl;
	StateType type = td.type;
	if (type == StateType::I) {
		out << "IIII" << endl;
	}
	else if (type == StateType::J) {
		out << "J" << endl << "JJJ" << endl;
	}
	else if (type == StateType::L) {
		out << "  L" << endl << "LLL" << endl;
	}
	else if (type == StateType::O) {
		out << "OO" << endl << "OO" << endl;
	}
	else if (type == StateType::S) {
		out << " SS" << endl << "SS" << endl;
	}
	else if (type == StateType::Z) {
		out << "ZZ" << endl << " ZZ" << endl;
	}
	else if (type == StateType::T) {
		out << "TTT" << endl << " T" << endl;
	}
	return out;
}





