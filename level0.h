#ifndef _LEVEL0_H_
#define _LEVEL0_H_

#include "level.h"
#include <iostream>
#include <string>

class Level0: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };

 #endif

