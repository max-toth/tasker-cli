#include <iostream>

#include "Command.h"

using namespace std;

class HelpCmd : public Command
{

public:
    virtual void run(int argc, char *argv[])
    {
        cout << "-c, --create <TICKET> Sentence of ticket short description" << '\n';
        cout << "-r, --resolve <TICKET_ID> Resolve ticket by ID" << '\n';
        cout << "-l, List current day tickets" << '\n';
    }

};
