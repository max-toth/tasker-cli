#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <string_view>

static void print_help() {
  std::cout << "-c, --create <TICKET> Sentence of ticket short description" << '\n';
  std::cout << "-r, --resolve <TICKET_ID> Resolve ticket by ID" << '\n';
  std::cout << "-l, List current day tickets" << '\n';
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    print_help();
    return 0;
  }

  std::hash<std::string> str_hash;
  std::string arg1 = argv[1];

  if (arg1 == "-c" || arg1 == "--create") {
      if (argc < 3) {
        std::cerr << "No ticket description provided" << '\n';
        print_help();
      } else {
        std::ofstream taskerFile;
        taskerFile.open(".tasker", std::ios::out|std::ios::app);
        if (taskerFile.is_open()) {
          std::string description = argv[2];
          taskerFile << str_hash(description) << " " << argv[2] << "\n";
          std::cout << "Ticket created \"" << argv[2] << "\"\n";
          taskerFile.close();
        }
      }
  }

  if (arg1 == "-r" || arg1 == "--resolve") {
    if (argc < 3) {
      std::cerr << "No ticket ID provided!" << '\n';
      print_help();
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

  if (arg1 == "-l") {
    std::ifstream taskerFileRead;
    taskerFileRead.open(".tasker");
    if (taskerFileRead.is_open()) {
      std::string line;
      std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
      while (std::getline(taskerFileRead, line)) {
        std::cout << "  " << line << '\n';
      }
      std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
      taskerFileRead.close();
    }
  }
}
