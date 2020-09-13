#include "grid.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
void Grid::remove_last() {
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    bl.pop_back();
}

void Grid::hint() {
    Block hint_b = bl.back();
    bl.emplace_back(hint_b);
    int min_sofar = 14;
    vector<pair<int, int>> v = lower_bound();
    int size = v.size();
    for (int i = 0; i < size; i++) {
        int c = v[i].second;
        int r = v[i].first;
        if (r == 17) {
            min_sofar = 0;
            break;
        }
        for (int j = r + 1; j < 18; j++) {
            if (theGrid[j][c].getState().type != StateType::None) {
                int diff = j - r - 1;
                if (diff < min_sofar) {min_sofar = diff;}
            }
            else if (j == 17) {
                int diff = j - r;
                if (diff < min_sofar) {min_sofar = diff;}
            }
        }
    }
    (bl.back()).drop(min_sofar);
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::Q_m);
    } 
    v.clear();
}
    
    /*Block hint_b2 = bl.back();
    Block hint_b3 = bl.back();
    Block hint_b4 = bl.back();
    bl.emplace_back(hint_b1);
    int max_sofar1 = 0;
    int max_sofar2 = 0;
    int num_left = 0;
    int position1;
    int position2;
    for (int k = 0; k < 10; k++) {
        (bl.back()).left();
        vector<pair<int, int>> v = lower_bound();
        int size = v.size();
        for (int i = 0; i < size; i++) {
            int c = v[i].second;
            int r = v[i].first;
            if (r == 17) {
                break;
            }
            for (int j = r + 1; j < 18; j++) {
                if (theGrid[j][c].getState().type != StateType::None) {
                    int diff = j - r - 1;
                    if (diff > max_sofar1) {
                        max_sofar1 = diff;
                        position1 = k;
                    }
                }
                else if (j == 17) {
                    int diff = j - r;
                    if (diff > max_sofar1) {
                        max_sofar1 = diff;
                        position1 = k;
                    }
                }
            }
        }
        v.clear();
    }
    bl.pop_back();
    bl.emplace_back(hint_b2);
    for (int k = 0; k < 10; k++) {
        (bl.back()).right();
        vector<pair<int, int>> v = lower_bound();
        int size = v.size();
        for (int i = 0; i < size; i++) {
            int c = v[i].second;
            int r = v[i].first;
            if (r == 17) {
                break;
            }
            for (int j = r + 1; j < 18; j++) {
                if (theGrid[j][c].getState().type != StateType::None) {
                    int diff = j - r - 1;
                    if (diff > max_sofar2) {
                        max_sofar2 = diff;
                        position2 = k;
                    }
                }
                else if (j == 17) {
                    int diff = j - r;
                    if (diff > max_sofar2) {
                        max_sofar2 = diff;
                        position2 = k;
                    }
                }
            }
        }
        v.clear();
    }
    cout << max_sofar2 << max_sofar1 << endl;
    if (max_sofar2 >= max_sofar1) {
        cout << position2;
        bl.pop_back();
        bl.emplace_back(hint_b3);
        for (int i = 0; i < position2; i++) {
            (bl.back()).right();
        }
        (bl.back()).drop(max_sofar2);
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(StateType::Q_m);
        }
    }
    else {
        bl.pop_back();
        bl.emplace_back(hint_b4);
        for (int i = 0; i < position1; i++) {
            (bl.back()).left();
        }
        (bl.back()).drop(max_sofar1);
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(StateType::Q_m);
        }
    }*/



bool Grid::halfboard() {
    for (int j = 0; j < 11; j++) {
        if (theGrid[10][j].getState().type != StateType::None) {
            return 1;
        }
    }
    return 0;
}

void Grid::change_showgd(bool i) {
    showgd = i;
}
Grid::Grid(){}
int Grid::get_score() {
	return score;
}


int Grid::get_level() {
	return level;
}


int Grid::get_highscore() {
	return highscore;
}


void Grid::level_down() {
    if (level != 0) {
        level--;
        if (td != nullptr) td->reset_lv(level);
        if (showgd == 1 && gd != nullptr) gd->drawLevel(level);
    }
}


void Grid::level_up() { 
    if (level != 5) {
        level++;
        if (td != nullptr) td->reset_lv(level);
        if (showgd == 1 && gd != nullptr) gd->drawLevel(level);
    } 
}


void Grid::update_block(Block b) {
    bl.emplace_back(next);
    td->reset_type(b.getType());
    if (showgd == 1) gd->drawNext(b.getType());
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        StateType t = bl.back().getType();
        theGrid[r][c].setCell(t);
    }
    next = b;
    notifyall();
}

bool Grid::is_lost() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 11; j++) {
            if (theGrid[i][j].getState().type != StateType::None){
                return 1;
            }
        }
    }
    StateType t = next.getType();
    if (t == StateType::I) {
        for (int i = 0; i < 4; i++) {
            if (theGrid[3][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::J) {
        if (theGrid[3][0].getState().type != StateType::None) return 1;
        for (int i = 0; i < 3; i++) {
            if (theGrid[4][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::L) {
        if (theGrid[3][2].getState().type != StateType::None) return 1;
        for (int i = 0; i < 3; i++) {
            if (theGrid[4][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::O) {
        for (int i = 0; i < 2; i++) {
            if (theGrid[3][i].getState().type != StateType::None) {
                return 1;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (theGrid[4][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::S) {
        for (int i = 1; i < 3; i++) {
            if (theGrid[3][i].getState().type != StateType::None) {
                return 1;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (theGrid[4][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::Z) {
        for (int i = 0; i < 2; i++) {
            if (theGrid[3][i].getState().type != StateType::None) {
                return 1;
            }
        }
        for (int i = 1; i < 3; i++) {
            if (theGrid[4][i].getState().type != StateType::None) {
                return 1;
            }
        }
    }
    else if (t ==  StateType::T) {
        for (int i = 0; i < 3; i++) {
            if (theGrid[3][i].getState().type != StateType::None) {
                return 1;
            }
        }
        if (theGrid[4][1].getState().type != StateType::None) return 1;
    }
    return 0;
}

void Grid::init()  {
    for(unsigned int i = 0; i < theGrid.size(); i++) { theGrid[i].clear(); }
    theGrid.clear();
    td = make_shared<TextDisplay>();
    if (showgd == 1) {
        gd = make_shared<GraphicsDisplay>(670, 330);
    }
    td->reset_lv(level);
    if (showgd == 1) gd->drawLevel(level);
    theGrid.resize(18);
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < 11; j++) {
            //Cell c{i, j};
            theGrid[i].push_back(Cell{i,j});
        }
    }
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < 11; j++) {
            theGrid[i][j].attach(td);
            if (showgd == 1) {
                theGrid[i][j].attach(gd);
            }
        }
    }
}

//return -1 if it is full
void Grid::isFull(vector<int> &del) const {
    for (int i = 3; i < 18; i++) {
        int count = 0;
        for (int j = 0; j < 11; j++) {
            if (theGrid[i][j].getState().type == StateType::None) {
                count++;
            }
        }
        if (count == 0) {
            del.emplace_back(i);
        }
    }
}

void Grid::clearLine(bool easy) {
    vector<int> del;
    if (easy == 1 && halfboard()) {
        for (int k = 7; k >= 0; k++) {
            del.emplace_back(17 - k);
        }
    }
    else {
        isFull(del);
    }
    int no_del = del.size();
    int temp = 0;
    if (del.size() == 0) return;
    for (auto it = del.begin(); it != del.end(); ++it) {
        int check = *it;
        for (int i = 3; i < check; i++) {
            for (int j = 0; j < 11; j++) {
                StateType t = theGrid[check - i + 2][j].getState().type;
                theGrid[check - i + 3][j].setCell(t);
                if(find(del.begin(), del.end(), check - i + 3) != del.end()) {
                    for(auto it = bl.begin(); it != bl.end() && !bl.empty(); ++it) {
                        it->notify(check - i + 3, j);
                    }
                }
                else {
                    for(auto it = bl.begin(); it != bl.end() && !bl.empty(); ++it) {
                        it->move_down(check - i + 3, j);
                    }
                }
            }
        }
        for (int j = 0; j < 11; j++) {
            theGrid[3][j].setCell(StateType::None);
        }
    }
    if (easy != 1) {
        for (int i = 0; i < bl.size();) {
            if(bl[i].getSize() == 0) {
                int blevel = bl[i].getLevel();
                bl.erase(bl.begin() + i);
                cout << "block level" << blevel << endl;
                score += (blevel + 1) * (blevel + 1);
                cout << "block score" << score << endl;
            } else {
                ++i;
            }
        }
        score += (level + no_del) * (level + no_del);
        cout << "line score" << score << endl;
        if (highscore < score) {
            highscore = score;
        }
        td->reset_hi_score(highscore);
        td->reset_score(score);
        if (showgd == 1) gd->drawHiScore(highscore);
        if (showgd == 1) gd->drawScore(score);
    }
}


vector<pair<int, int>> Grid::left_bound () {
    bool check = 0;
    vector<pair<int, int>> v;
    int r_0 = bl.back().getCor(0, 'r');
    int c_0 = bl.back().getCor(0, 'c');
    v.push_back(make_pair(r_0, c_0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int size = v.size();
            int r = bl.back().getCor(j, 'r');
            int c = bl.back().getCor(j, 'c');
            for (int k = 0; k < size; k++) {
                if (v[k].first == r) {
                    if (c < v[k].second) {
                        v[k].second = c;
                    }
                    check = 1;
                }
            }
            if (check == 0) {
                v.push_back(make_pair(r, c));
            }
            check = 0;
        }
    }
    return v;
}

vector<pair<int, int>> Grid::right_bound () {
    bool check = 0;
    vector<pair<int, int>> v;
    int r_0 = bl.back().getCor(0, 'r');
    int c_0 = bl.back().getCor(0, 'c');
    v.push_back(make_pair(r_0, c_0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int size = v.size();
            int r = bl.back().getCor(j, 'r');
            int c = bl.back().getCor(j, 'c');
            for (int k = 0; k < size; k++) {
                if (v[k].first == r) {
                    if (c > v[k].second) {
                        v[k].second = c;
                    }
                    check = 1;
                }
            }
            if (check == 0) {
                v.push_back(make_pair(r, c));
            }
            check = 0;
        }
    }
    return v;
}

void Grid::left() { 
    vector<pair<int, int>> v = left_bound();
    StateType t = bl.back().getType();
    int size = v.size();
    int diff = 1;
    for (int i = 0; i < size; i++) {
        int r = v[i].first;
        int c = v[i].second;
        if (c == 0) {
            diff = 0;
        }
        else if (theGrid[r][c - 1].getState().type != StateType::None) {
            diff = 0;
        }
    }
    if (diff == 0) {return;}
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    (bl.back()).left();
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(t);
    } 
}
void Grid::right(){ 
    vector<pair<int, int>> v = right_bound();
    StateType t = bl.back().getType();
    int size = v.size();
    int diff = 1;
    for (int i = 0; i < size; i++) {
        int r = v[i].first;
        int c = v[i].second;
        if (c == 10) {
            diff = 0;
        }
        else if (theGrid[r][c + 1].getState().type != StateType::None) {
            diff = 0;
        }
    }
    if (diff == 0) {return;}
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    (bl.back()).right();
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(t);
    }  
}
void Grid::down() { 
    vector<pair<int, int>> v = lower_bound();
    int size = v.size();
    int diff = 1;
    for (int i = 0; i < size; i++) {
        int r = v[i].first;
        int c = v[i].second;
        if (r == 17) {
            diff = 0;
        }
        else if (theGrid[r + 1][c].getState().type != StateType::None) {
            diff = 0;
        }
    }
    if (diff == 0) {return;}
    StateType t = bl.back().getType();
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    (bl.back()).down();
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(t);
    } 
    v.clear(); 
}

vector<pair<int, int>> Grid::lower_bound () {
    bool check = 0;
    vector<pair<int, int>> v;
    int r_0 = bl.back().getCor(0, 'r');
    int c_0 = bl.back().getCor(0, 'c');
    v.push_back(make_pair(r_0, c_0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int size = v.size();
            int r = bl.back().getCor(j, 'r');
            int c = bl.back().getCor(j, 'c');
            for (int k = 0; k < size; k++) {
                if (v[k].second == c) {
                    if (r > v[k].first) {
                        v[k].first = r;
                    }
                    check = 1;
                }
            }
            if (check == 0) {
                v.push_back(make_pair(r, c));
            }
            check = 0;
        }
    }
    return v;
}

void Grid::drop() { 
    int min_sofar = 14;
    vector<pair<int, int>> v = lower_bound();
    int size = v.size();
    for (int i = 0; i < size; i++) {
        int c = v[i].second;
        int r = v[i].first;
        if (r == 17) {
            min_sofar = 0;
            break;
        }
        for (int j = r + 1; j < 18; j++) {
            if (theGrid[j][c].getState().type != StateType::None) {
                int diff = j - r - 1;
                if (diff < min_sofar) {min_sofar = diff;}
            }
            else if (j == 17) {
                int diff = j - r;
                if (diff < min_sofar) {min_sofar = diff;}
            }
        }
    }
    StateType t = bl.back().getType();
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    (bl.back()).drop(min_sofar);
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(t);
    } 
    v.clear();
    if (level == 5) {
        clearLine(1);
    }
    else  {
        clearLine(0);
    } 
}
void Grid::clockwise() { 
    int check = 0;
    StateType t = bl.back().getType();
    for (int i = 0; i < 4; i++) {
        (bl.back()).cw();
        int r1 = bl.back().getCor(i, 'r');
        int c1 = bl.back().getCor(i, 'c');
        (bl.back()).ccw();
        if ((bl.back()).in_block(r1, c1)) {
            continue;
        }
        else if (theGrid[r1][c1].getState().type != StateType::None) {
            check = 1;
            break;
        }
    }  
    if (check != 1) {
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(StateType::None);
        }
        (bl.back()).cw();
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(t);
        }
    }
}
void Grid::c_clockwise() { 
    int check = 0;
    StateType t = bl.back().getType();
    for (int i = 0; i < 4; i++) {
        (bl.back()).ccw();
        int r1 = bl.back().getCor(i, 'r');
        int c1 = bl.back().getCor(i, 'c');
        (bl.back()).cw();
        if ((bl.back()).in_block(r1, c1)) {
            continue;
        }
        else if (theGrid[r1][c1].getState().type != StateType::None) {
            check = 1;
            break;
        }
    }  
    if (check != 1) {
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(StateType::None);
        }
        (bl.back()).ccw();
        for (int i = 0; i < 4; i++) {
            int r = bl.back().getCor(i, 'r');
            int c = bl.back().getCor(i, 'c');
            theGrid[r][c].setCell(t);
        }
    }
}


void Grid::notifyall() {
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < 11; j++) {
            theGrid[i][j].notifyObservers();
        }
    }
}

void Grid::setNext(Block b) {
    next = b;
}

void Grid::setCur() {
    for (int i = 0; i < 4; i++) {
        int r = bl.back().getCor(i, 'r');
        int c = bl.back().getCor(i, 'c');
        theGrid[r][c].setCell(StateType::None);
    }
    if(!bl.empty()) {
        bl.pop_back();
    } else {
        return;
    } 
}

ostream& operator<<(ostream& out, const Grid& g) {
    out << *(g.td);
    return out;
}



void Grid::setStar() {
    for(int i = 17; i > 2; --i) {
        if (theGrid[i][5].getState().type == StateType::None) {
            theGrid[i][5].setCell(StateType::Star);
            return;
        }
    }
}




