#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include "grid.h"
#include "block.h"
#include "state.h"
#include "command.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
using namespace std;
int main(int argc, char * argv[]) {
  int check = 1;
  string s2 = "sequence.txt";
  double seed = 1.0;
  Grid g;
  string cmd;
  bool ran = true;
  int level = 0;
  int level_start = 0;
  int count = 0; // new count for lv4 *
  ifstream seqFile;
  ifstream norandomFile;
  vector<string> se;
  vector<string> noran;
  bool is_hint = 0;
  int se_c = 0;
  int noran_c = 0;
  vector<string> ijl{"I", "J", "L", "O", "S", "Z", "T"};
  for (int i = 1; i < argc; ++i) {
    string argument = argv[i];
    if (argument == "-text") {
      g.change_showgd(0);
    } else if (argument == "-seed") {
      stringstream ss{argv[++i]};
      ss >> seed;
    }
    else if (argument == "-scriptfile") {
      s2 = argv[++i];
    }
    else if (argument == "-startlevel") {
      stringstream ss{argv[++i]};
      ss >> level;
      for (int j = 0; j < level; j++) g.level_up();
    }
  }
  srand(seed);
  seed = rand();
  ifstream file{s2};
  string blk;
  level_start = level;
  //auto curBlock = make_shared<Level>();
  //auto nextBlock = make_shared<Level>();
  shared_ptr<Level> curBlock;
  shared_ptr<Level> nextBlock;
  if (level == 0) {
    curBlock = make_shared<Level0>();
    nextBlock = make_shared<Level0>();
  }
  else if (level == 1) {
    curBlock = make_shared<Level1>();
    nextBlock = make_shared<Level1>();
  }
  else if (level == 2) {
    curBlock = make_shared<Level2>();
    nextBlock = make_shared<Level2>();
  }
  else if (level == 3){
    curBlock = make_shared<Level3>();
    nextBlock = make_shared<Level3>();
  }
  else if (level == 4){
    curBlock = make_shared<Level4>();
    nextBlock = make_shared<Level4>();
    count += 1;
  }
  else {
    curBlock = make_shared<Level5>();
    nextBlock = make_shared<Level5>();
  }
  g.init();
  if (level == 0) {
    if (!(file >> blk)) check = 0;
    g.setNext(curBlock->get_next(blk, seed));
    if (!(file >> blk)) check = 0;
    g.update_block(nextBlock->get_next(blk, seed));
  }
  else {
    blk = "random";
    g.setNext(curBlock->get_next(blk, seed));
    g.update_block(nextBlock->get_next(blk, seed));
  }
  cout << g;
  
  while (check) {
    int se_s = se.size();
    if (se_s != se_c) {
      cmd = se[se_c];
      se_c++;
    } else {
      cin >> cmd;
    }
    if (is_hint != 0) {
      g.remove_last();
      g.notifyall();
      is_hint = 0;
    }
    Command comd{cmd};
    int times = 1;
    if (comd.hasInteger()) {
      times = comd.times();
    }
    //getting command type
    cmd = comd.command();
    //performing operations
    if (cmd == "left") {
      for(int i = 0; i < times; ++i) { 
        g.left();
      }
      if (level > 2) g.down();
      g.notifyall();
    }
    else if (cmd == "right") {
      for(int i = 0; i < times; ++i) { 
        g.right();
      }
      if (level > 2) g.down();
      g.notifyall();
    }
    else if (cmd == "down") {
      for(int i = 0; i < times; ++i) {
        g.down();
      }
      if (level > 2) g.down();
      g.notifyall();
    }
    else if (cmd == "clockwise") {
      for(int i = 0; i < times; ++i) {
        g.clockwise();
      }
      if (level > 2) g.down();
      g.notifyall();
    }
    else if (cmd == "counterclockwise") {
      for(int i = 0; i < times; ++i) { 
        g.c_clockwise();
      }
      if (level > 2) g.down();
      g.notifyall();
    } else if (cmd == "drop") {
      bool lost = 0;
      for (int i = 0; i < times; ++i) {
        g.drop();
        if (g.is_lost()) {
	  cout << g;
          cout << "You lost! Try next time!" << endl;
          lost = 1;
          break;
        } 
        level = g.get_level();
        srand(seed);
        seed = rand();
        blk = "random";
        if (level == 0) {
          if (!(file >> blk)) {
            lost = 1;
            break;
          }
          auto nextBlock = make_shared<Level0>();
          g.update_block(nextBlock->get_next(blk, seed));
        } else if (level == 1) {
          auto nextBlock = make_shared<Level1>();
          g.update_block(nextBlock->get_next(blk, seed));
        } else if (level == 2) {
          auto nextBlock = make_shared<Level2>();
          g.update_block(nextBlock->get_next(blk, seed));
        } else if (level == 3) {
          int noran_s = noran.size();
          if (!ran && noran_s != 0) {
            if (noran_s == noran_c) {
              lost = 1;
              break;
            }
            blk = noran[noran_c];
            noran_c += 1;
          }
          auto nextBlock = make_shared<Level3>();
          g.update_block(nextBlock->get_next(blk, seed));
        } else if (level == 4) {
          int noran_s = noran.size();
          if (!ran && noran_s != 0) {
            if (noran_s == noran_c) {
              lost = 1;
              break;
            }
            blk = noran[noran_c];
            noran_c += 1;
          }
          auto nextBlock = make_shared<Level4>();
          g.update_block(nextBlock->get_next(blk, seed));
          count += 1;
        }
        else {
          auto nextBlock = make_shared<Level5>();
          g.update_block(nextBlock->get_next(blk, seed));
        }
        if (count % 5 == 0 && level == 4) g.setStar();
      }
      if (lost == 1) break;
      g.notifyall();
    }
    else if (cmd == "levelup") {
      g.level_up();
      level = g.get_level();
    }
    else if (cmd == "leveldown") {
      g.level_down();
      level = g.get_level();
    }
    else if (cmd == "norandom") {
      string filename;
      cin >> filename;
      ifstream norandomFile{filename};
      while (norandomFile >> filename) {
        noran.push_back(filename);
      }
      ran = false;
    }
    else if (cmd == "random") {
      ran = true;
    }
    else if (cmd == "sequence") {
      string seq;
      cin >> seq;
      ifstream seqFile{seq};
      while (seqFile >> seq) {
        se.push_back(seq);
      }
    }
    else if (find(ijl.begin(), ijl.end(), cmd) != ijl.end()) {
      g.setNext(curBlock->get_next(cmd, seed));
      g.setCur();
      g.update_block(nextBlock->get_next(blk, seed));
      cout << g;
    }
    else if (cmd == "restart") {
      if (level_start == 0) {
        auto curBlock = make_shared<Level0>();
        auto nextBlock = make_shared<Level0>();
      }
      else if (level_start == 1) {
        auto curBlock = make_shared<Level1>();
        auto nextBlock = make_shared<Level1>();
      }
      else if (level_start == 2) {
        auto curBlock = make_shared<Level2>();
        auto nextBlock = make_shared<Level2>();
      }
      else if (level_start == 3) {
        auto curBlock = make_shared<Level3>();
        auto nextBlock = make_shared<Level3>();
      }
      else if (level_start == 4) {
        auto curBlock = make_shared<Level4>();
        auto nextBlock = make_shared<Level4>();
      }
      else {
        auto curBlock = make_shared<Level5>();
        auto nextBlock = make_shared<Level5>();
      }
      for (int i = 0; i < level_start; i++) g.level_up();
      g.init();
      ifstream file{s2};
      file >> blk;
      g.setNext(curBlock->get_next(blk, seed));
      file >> blk;
      g.update_block(nextBlock->get_next(blk, seed));
    }
    else {//if (cmd == "hint");
      g.hint();
      g.notifyall();
      is_hint = 1;
    }
    if (cmd != "invalid input") {
      cout << g;
    }
    else {
      cout << "Invalid Input!" << endl;
    }
  }
}

