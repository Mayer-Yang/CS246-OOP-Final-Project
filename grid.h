#ifndef GRID_H 
#define GRID_H
#include <iostream> 
#include <vector> 
#include "cell.h"
#include "block.h"   
#include "graphicsdisplay.h"  
#include "state.h"
#include "textdisplay.h"
#include <memory>
#include <utility>
class TextDisplay;
template <typename State> class Observer;
class Grid {
	std::vector<std::vector<Cell>> theGrid; // the actual grid
	std::shared_ptr<TextDisplay> td = nullptr; // the text display
    std::vector<Block> bl;
    Block next; // take next block
    int level = 0;
    int score = 0;
    int highscore = 0;
	std::shared_ptr<GraphicsDisplay> gd = nullptr;
	bool showgd = 1; 
public:
	Grid();
    void remove_last();
    bool halfboard();
	void change_showgd(bool i);
	bool is_lost();
	void init();
	void isFull(std::vector<int> &) const; 
	void clearLine(bool easy);
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void c_clockwise();
	void hint(); // ***
    void level_up();
    void level_down();
    void update_block(Block b);
    int get_score();
    int get_level();
    int get_highscore();
    void notifyall(); // notify all obs
    void setNext(Block b);
    void setCur();
    std::vector<std::pair<int, int>> lower_bound ();
    std::vector<std::pair<int, int>> right_bound ();
    std::vector<std::pair<int, int>> left_bound ();
    void setStar();
    friend class Level; 
    friend std::ostream& operator<<(std::ostream& out, const Grid& g); 
};
#endif


























































