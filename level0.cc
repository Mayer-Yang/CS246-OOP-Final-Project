#include "level0.h"
#include <iostream>
#include <string>
#include "grid.h"
#include <utility>
#include "state.h"
#include "block.h"


using namespace std;


Block Level0::get_next(string s, double seed) {
 	if (s == "I") {
 		return Block{make_pair(3,0), make_pair(3,1), make_pair(3,2), make_pair(3,3), StateType::I, Rotate::Origin, 0};
 	} else if (s == "J") {
 		return Block{make_pair(3,0), make_pair(4,0), make_pair(4,1), make_pair(4,2), StateType::J, Rotate::Origin, 0};
 	} else if (s == "L") {
 		return Block{make_pair(3,2), make_pair(4,2), make_pair(4,1), make_pair(4,0), StateType::L, Rotate::Origin, 0};
 	} else if (s == "O") {
		return Block{make_pair(3,0), make_pair(3,1), make_pair(4,0), make_pair(4,1), StateType::O, Rotate::Origin, 0};
	} else if (s == "S") {
 		return Block{make_pair(3,1), make_pair(3,2), make_pair(4,0), make_pair(4,1), StateType::S, Rotate::Origin, 0};
 	} else if (s == "Z") {
 		return Block{make_pair(3,0), make_pair(3,1), make_pair(4,1), make_pair(4,2), StateType::Z, Rotate::Origin, 0};
 	} else { // (s == "T") 
		return Block{make_pair(3,0), make_pair(3,1), make_pair(3,2), make_pair(4,1), StateType::T, Rotate::Origin, 0};
	}
}


