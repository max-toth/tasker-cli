#include <iostream>
#include <fstream>
#include <string>

#include "Command.h"
#include "Help.cpp"

class CreateCmd : public Command
{

public:
    CreateCmd() {}
	virtual void run(int argc, char *argv[])
    {
        if (argc < 3)
        {
            std::cerr << "No ticket description provided" << '\n';
            helpCmd.run(argc, argv);
        }
        else
        {
        	std::hash<std::string> str_hash;
            std::ofstream taskerFile;
            taskerFile.open(".tasker", std::ios::out | std::ios::app);
            if (taskerFile.is_open())
            {
                std::string description = argv[2];
                taskerFile << str_hash(description) << " " << argv[2] << "\n";
                std::cout << "Ticket created \"" << argv[2] << "\"\n";
                taskerFile.close();
            }
        }
    }

private:
    HelpCmd helpCmd;

};
