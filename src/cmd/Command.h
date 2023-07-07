#include <iostream>

#ifndef COMMAND_H
#define COMMAND_H

class Command
{

public:
	virtual ~Command() {}
    virtual void run(int argc, char *argv[]) = 0;
};

#endif
