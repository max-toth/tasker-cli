#include <iostream>
#include <fstream>
#include <string>

#include "Command.h"

class ListCmd: public Command {

public:

	ListCmd() {
	}

	virtual ~ListCmd() {
	}

	virtual void run(int argc, char *argv[]) {
		std::ifstream taskerFileRead;
		taskerFileRead.open(".tasker");
		if (taskerFileRead.is_open()) {
			std::string line;
			std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
					<< '\n';
			while (std::getline(taskerFileRead, line)) {
				std::cout << "  " << line << '\n';
			}
			std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
					<< '\n';
			taskerFileRead.close();
		}
	}

private:
	HelpCmd helpCmd;
};
