#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include "level.h"
#include <iostream>
#include <string>

class Level3: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };


 #endif

