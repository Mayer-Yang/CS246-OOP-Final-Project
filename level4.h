#ifndef _LEVEL4_H_
#define _LEVEL4_H_

#include "level.h"
#include <iostream>
#include <string>

class Level4: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };


 #endif

