#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "level.h"
#include <iostream>
#include <string>


class Level2: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };


 #endif

