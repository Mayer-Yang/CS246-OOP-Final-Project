#ifndef COMMAND_H
#define COMMAND_H
#include <string>
class Command {
	std::string cmd;
public:
	Command(std::string cmd);
	bool hasInteger();
	int times();
	std::string command();
};
#endif
