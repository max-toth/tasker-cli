#include <iostream>
#include <fstream>
#include <string>

#include "Command.h"

class ResolveCmd: public Command {

public:
	ResolveCmd() {
	}
	virtual ~ResolveCmd() {
	}
	virtual void run(int argc, char *argv[]) {
		if (argc < 3) {
			std::cerr << "No ticket ID provided!" << '\n';
			helpCmd.run(argc, argv);
		} else {
			std::ifstream taskerFileRead;
			std::ofstream taskerFileWrite;
			taskerFileRead.open(".tasker");
			taskerFileWrite.open(".tasker~");
			if (taskerFileRead.is_open() && taskerFileWrite.is_open()) {
				std::string line;
				std::string ticket_id = argv[2];
				while (std::getline(taskerFileRead, line)) {
					if (line.rfind(ticket_id, 0) == 0) {
						line = "* " + line;
					}
					taskerFileWrite << line + "\n";
				}
				taskerFileWrite.close();
				taskerFileRead.close();
			}

			std::ifstream tempFile;
			std::ofstream originFile;
			tempFile.open(".tasker~");
			originFile.open(".tasker");

			if (tempFile.is_open() && originFile.is_open()) {
				std::string line;
				while (std::getline(tempFile, line)) {
					originFile << line + "\n";
				}
				tempFile.close();
				originFile.close();
				std::remove(".tasker~");
			}
		}
	}

private:
    HelpCmd helpCmd;

};
