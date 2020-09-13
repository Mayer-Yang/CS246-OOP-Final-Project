#include "level1.h"
#include <iostream>
#include <string>
#include "grid.h"
#include <utility>
#include "state.h"
#include "block.h"


using namespace std;



Block Level1::get_next(string s, double seed) {
	vector<string> v{"I","J","L","O","S","Z","T"};
  if (s == "random") {
    double val = (double)seed / RAND_MAX;
    int random;
    if (val < 1.0/6.0) {random = 0;}
    else if (val < 1.0/3.0) {random = 1;}
  	else if (val < 1.0/2.0) {random = 2;}
  	else if (val < 2.0/3.0) {random = 3;}
  	else if (val < 9.0/12.0) {random = 4;}
    else if (val < 5.0/6.0) {random = 5;}
    else {random = 6;}
    s = v[random];
  }
  if (s == "I") {
    return Block{make_pair(3,0), make_pair(3,1), make_pair(3,2), make_pair(3,3), StateType::I, Rotate::Origin, 1};
  } else if (s == "J") {
    return Block{make_pair(3,0), make_pair(4,0), make_pair(4,1), make_pair(4,2), StateType::J, Rotate::Origin, 1};
  } else if (s == "L") {
    return Block{make_pair(3,2), make_pair(4,2), make_pair(4,1), make_pair(4,0), StateType::L, Rotate::Origin, 1};
  } else if (s == "O") {
    return Block{make_pair(3,0), make_pair(3,1), make_pair(4,0), make_pair(4,1), StateType::O, Rotate::Origin, 1};
  } else if (s == "S") {
    return Block{make_pair(3,1), make_pair(3,2), make_pair(4,0), make_pair(4,1), StateType::S, Rotate::Origin, 1};
  } else if (s == "Z") {
    return Block{make_pair(3,0), make_pair(3,1), make_pair(4,1), make_pair(4,2), StateType::Z, Rotate::Origin, 1};
  } else { // (s == "T") 
    return Block{make_pair(3,0), make_pair(3,1), make_pair(3,2), make_pair(4,1), StateType::T, Rotate::Origin, 1};
  }
}


