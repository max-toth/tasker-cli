#include <iostream>
#include <fstream>
#include <functional>
#include <string.h>
#include <string_view>
#include <map>

#include "cmd/Create.cpp"
#include "cmd/Resolve.cpp"
#include "cmd/List.cpp"

using namespace std;

Command * helpCmd = new HelpCmd();
Command * createCmd = new CreateCmd();
Command * resolveCmd = new ResolveCmd();
Command * listCmd = new ListCmd();

map<string, Command*> options = {
		{"-c", createCmd},
		{"create", createCmd},
		{"-r", resolveCmd},
		{"resolve", resolveCmd},
		{"-l", listCmd},
		{"list", listCmd}
};


int main(int argc, char *argv[]) {

	if (argc < 2) {
		helpCmd->run(argc, argv);
		return 0;
	}

	string optionKey = argv[1];
	options[optionKey]->run(argc, argv);

}
