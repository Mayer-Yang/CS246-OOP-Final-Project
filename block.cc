#include <cstddef>
#include <vector>
#include "block.h"
using namespace std;
Block::Block() {}
// construct a block element
Block::Block(pair<int, int> c1, pair<int, int> c2, pair<int, int> c3, pair<int, int> c4, 
	StateType type, Rotate rotate, int level) {
	theBlock.push_back(c1);
	theBlock.push_back(c2);
	theBlock.push_back(c3);
	theBlock.push_back(c4);
	this->type = type; 
	this->level = level;
	this->rotate = rotate;
} 
void Block::cw() {
	if (type == StateType::I) {
		if (theBlock[0].second >= 8 && (rotate != Rotate::Origin)) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[0].first -= 3;
			theBlock[1].first -= 2;
			theBlock[1].second -= 1;
			theBlock[2].first -= 1;
			theBlock[2].second -= 2;
			theBlock[3].second -= 3;
			setRotate(Rotate::Cw1);
		} else {
			theBlock[0].first += 3;
			theBlock[1].first += 2;
			theBlock[1].second += 1;
			theBlock[2].first += 1;
			theBlock[2].second += 2;
			theBlock[3].second += 3;
			setRotate(Rotate::Origin);
		}
	} else if (type == StateType::J) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[0].first -= 1; 
			theBlock[0].second += 1;
			theBlock[1].first -= 2;
			theBlock[2].first -= 1;
			theBlock[2].second -= 1;
			theBlock[3].second -= 2;
			setRotate(Rotate::Cw1);
		} else if (rotate == Rotate::Cw1) {
			theBlock[0].first += 2;
			theBlock[0].second += 1;
			theBlock[1].first += 1;
			theBlock[1].second += 2;
			theBlock[2].second += 1;
			theBlock[3].first -= 1;
			setRotate(Rotate::Cw2);
		} else if (rotate == Rotate::Cw2) {
			theBlock[0].second -= 2;
			theBlock[1].first += 1;
			theBlock[1].second -= 1;
			theBlock[3].first -= 1;
			theBlock[3].second += 1;
			setRotate(Rotate::Cw3);
		} else {
			theBlock[0].first -= 1;
			theBlock[1].second -= 1;
			theBlock[2].first += 1;
			theBlock[3].first += 2;
			theBlock[3].second += 1;
			setRotate(Rotate::Origin);
		}
	} else if (type == StateType::L) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[0].first += 1;
			theBlock[0].second -= 1;
			theBlock[1].second -= 2;
			theBlock[2].first -= 1;
			theBlock[2].second -= 1;
			theBlock[3].first -= 2;
			setRotate(Rotate::Cw1);
		} else if (rotate == Rotate::Cw1) { 
			theBlock[0].second -= 1;
			theBlock[1].first -= 1;
			theBlock[2].second += 1;
			theBlock[3].first += 1;
			theBlock[3].second += 2;
			setRotate(Rotate::Cw2);
		} else if (rotate == Rotate::Cw2) {
			theBlock[0].first -= 2;
			theBlock[1].first -= 1;
			theBlock[1].second += 1;
			theBlock[3].first += 1;
			theBlock[3].second -= 1;
			setRotate(Rotate::Cw3);
		} else {
			theBlock[0].first += 1;
			theBlock[0].second += 2;
			theBlock[1].first += 2;
			theBlock[1].second += 1;
			theBlock[2].first += 1;
			theBlock[3].second -= 1;
			setRotate(Rotate::Origin);
		}
	} else if (type == StateType::S) {
		if (theBlock[0].second > 9) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[1].first += 1;
			theBlock[1].second -= 1;
			theBlock[2].first -= 2;
			theBlock[3].first -= 1;
			theBlock[3].second -= 1;
			setRotate(Rotate::Cw1);
		} else {
			theBlock[1].first -= 1;
			theBlock[1].second += 1;
			theBlock[2].first += 2;
			theBlock[3].first += 1;
			theBlock[3].second += 1;
			setRotate(Rotate::Origin);
		}
	} else if (type == StateType::T) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[0].first -= 1;
			theBlock[0].second += 1;
			theBlock[2].first += 1;
			theBlock[2].second -= 1;
			theBlock[3].first -= 1;
			theBlock[3].second -= 1;
			setRotate(Rotate::Cw1);
		} else if (rotate == Rotate::Cw1) {
			theBlock[0].first += 2;
			theBlock[0].second += 1;
			theBlock[1].first += 1;
			theBlock[2].second -= 1;
			theBlock[3].second += 1;
			setRotate(Rotate::Cw2);
		} else if (rotate == Rotate::Cw2) {
			theBlock[0].second -= 2;
			theBlock[1].first -= 1;
			theBlock[1].second -= 1;
			theBlock[2].first -= 2;
			setRotate(Rotate::Cw3);
		} else {
			theBlock[0].first -= 1;
			theBlock[1].second += 1;
			theBlock[2].first += 1;
			theBlock[2].second += 2;
			theBlock[3].first += 1;
			setRotate(Rotate::Origin);
		}
	} else if (type == StateType::Z) {
		if (theBlock[0].second == 10 && rotate != Rotate::Origin) {
			return;
		}
		if (rotate == Rotate::Origin) {
			theBlock[0].first -= 1;
			theBlock[0].second += 1;
			theBlock[2].first -= 1;
			theBlock[2].second -= 1;
			theBlock[3].second -= 2;
			setRotate(Rotate::Cw1);
		} else {
			theBlock[0].first += 1;
			theBlock[0].second -= 1;
			theBlock[2].first += 1;
			theBlock[2].second += 1;
			theBlock[3].second += 2;
			setRotate(Rotate::Origin);
		}
	} else {
		return;
	}
}
void Block::ccw() {
	if (type == StateType::I) {
		if (theBlock[0].second >= 8 && (rotate != Rotate::Origin)) {
			return;
		}
		cw();
		cw();
		cw();
	} else if (type == StateType::J) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		cw();
		cw();
		cw();
	} else if (type == StateType::L) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		cw();
		cw();
		cw();
	} else if (type == StateType::S) {
		if (theBlock[0].second > 9) {
			return;
		}
		cw();
		cw();
		cw();
	} else if (type == StateType::T) {
		if ((theBlock[0].second == 10 && rotate == Rotate::Cw1) || (theBlock[0].second == 9 && rotate == Rotate::Cw3)) {
			return;
		}
		cw();
		cw();
		cw();
	} else if (type == StateType::Z) {
		if (theBlock[0].second == 10 && rotate != Rotate::Origin) {
			return;
		}
		cw();
		cw();
		cw();
	} else {
		return;
	}
}
// ---------------------------------------------------------------------------------
// same implementation for all subclasses
// set rotation state
void Block::setRotate(Rotate r) {
	rotate = r;
}
// right shift 
void Block::right() {
	for (int j = 0; j < 4; ++j) {
		if (theBlock[j].second == 10) {
			return;
		} 
	} 
	for (int i = 0; i < 4; ++i) {
		theBlock[i].second = theBlock[i].second + 1;
	}
}
// left shift
void Block::left() {
	for (int j = 0; j < 4; ++j) {
		if (theBlock[j].second == 0) {
			return;
		} 
	} 
	for (int i = 0; i < 4; ++i) {
		theBlock[i].second = theBlock[i].second - 1;
	}
}
// block move down by one
void Block::down() {
	for (int i = 0; i < 4; ++i) {
		theBlock[i].first = theBlock[i].first + 1;
	}
}
// block move down by n 
void Block::drop(int x) { 
	for (int i = 0; i < 4; ++i) {
		theBlock[i].first = theBlock[i].first + x;
	}
}
// get the type of block
StateType Block::getType() {
	return type;
}
// get coordinate
int Block::getCor(int index, char c) {
	if (c == 'r') {
		return theBlock[index].first;
	} else {
		return theBlock[index].second;
	}
}
// get level
int Block::getLevel() {
	return level;   
}
// to see if cell had been romoved by checking the size of block
int Block::getSize() {
	return theBlock.size();
}
// remove a cell from block
void Block::notify(int r, int c) {
	int br;
	int bc;
	for (auto it = theBlock.begin(); it != theBlock.end() && !theBlock.empty(); ++it) {
		br = it->first; 
		bc = it->second; 
		//cout << "cell: ("<< r << ", " << c << ")" << endl;
		if (r == br && c == bc) {
			theBlock.erase(it);
			//cout << "size of block after erase: " << theBlock.size() << endl;
			return;
		}
	}
}

void Block::move_down(int r, int c) {
	int br;
	int bc;
	for (auto it = theBlock.begin(); it != theBlock.end() && !theBlock.empty(); ++it) {
		br = it->first; 
		bc = it->second; 
		//cout << "cell: ("<< r << ", " << c << ")" << endl;
		if (r == br && c == bc) {
			it->first += 1;
			//cout << "size of block after erase: " << theBlock.size() << endl;
			return;
		}
	}
}

bool Block::in_block(int r, int c) {
	int br;
	int bc;
	for (auto it = theBlock.begin(); it != theBlock.end() && !theBlock.empty(); ++it) {
		br = it->first; 
		bc = it->second;
		if (r == br && c == bc) {
			return 1;
		} 
	}
	return 0;
}









