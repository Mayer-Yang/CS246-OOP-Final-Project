#ifndef _LEVEL5_H_
#define _LEVEL5_H_

#include "level.h"
#include <iostream>
#include <string>


class Level5: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };


 #endif

