#include "command.h"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


Command::Command(std::string cmd): cmd{cmd}{}

bool Command::hasInteger() {
	istringstream iss{cmd.substr(0, 1)};
	int n;
	if (iss >> n) {return 1;}
	else {return 0;}
}
int Command::times() {
	string s{""};
	int n;
	int i = 0;
	while (true) {
		s = s + cmd[i];
		this->cmd = cmd.substr(1);
		if (this->hasInteger() == 0) {
			istringstream iss{s};
			iss >> n;
			break;
		}
	}
	return n;
}


string Command::command() {
	vector<string> v{"lef", "ri", "do", "cl", "co", "dr", "levelu",
	"leveld", "n", "ra", "s", "re", "h"};
	vector<string> v_cmd{"left", "right", "down", "clockwise", "counterclockwise",
	"drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart", "hint"};
	const int size_v = v_cmd.size();
	bool is_match = 1;
	if (cmd.length() == 1 && (cmd == "I" || cmd == "J" || cmd == "L" ||
		cmd == "O" || cmd == "Z" || cmd == "T")) {return cmd;}
	else {
		const int size_cmd = cmd.length();
		for (int i = 0; i < size_v; i++) {
			const int size_s = v_cmd[i].length();
			if (size_cmd <= size_s) {
				for (int j = 0; j < size_cmd; j++) {
					if (cmd[j] != v_cmd[i][j]) {
						is_match = 0;
					}
				}
				if (is_match != 0) {
					if (v[i].length() <= cmd.length()) {
						if (v[i] == cmd.substr(0, v[i].length())){
							return v_cmd[i];
						}
					}
            	}
            	is_match = 1;
        	}
		}
	}
	return "invalid input";
}


