#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <string>
using namespace std;


class Block;

class Level {
public:
 	virtual Block get_next(string s, double seed) = 0;
};
 
#endif
