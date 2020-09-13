#ifndef BLOCK_H
#define BLOCK_H
#include <cstddef>
#include <vector>
#include "state.h"
#include "cell.h"
class Block {
	std::vector<std::pair<int, int>> theBlock;
	StateType type = StateType::None;
	Rotate rotate = Rotate::Origin;
	int level = 0;
public:
	Block();
	Block(std::pair<int, int> c1, std::pair<int, int> c2, std::pair<int, int> c3, std::pair<int, int> c4, 
		StateType type, Rotate rotate, int level);
	void cw();
	void ccw();
	void setRotate(Rotate r);
	void left();
	void right();
	void down();
	void drop(int x);
	StateType getType();
	int getCor(int index, char c);
	int getLevel();
	int getSize();
	void notify(int r, int c);
	bool in_block(int r, int c);
	void move_down(int r, int c);
};
#endif
