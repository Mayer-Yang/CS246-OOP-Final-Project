#ifndef _LEVEL1_H_
#define _LEVEL1_H_

#include "level.h"
#include <iostream>
#include <string>


class Level1: public Level {
	string s;
public:
 	Block get_next(string s, double seed);
 };


 #endif

