#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "src/group.h"
#include "src/manager.h"
#include "src/user.h"

void rtrim(std::string& s) {
  size_t i = s.size();
  while (i > 0 && std::isspace(static_cast<unsigned char>(s[i - 1]))) --i;

  s.erase(i);
}

void printHelp() {
  std::cout << "\nProgram: User Management System\n\n";
  std::cout << "Commands:\n";
  std::cout << "\tcreateUser <userId> <username> [group_id] - "
               "create new user\n";
  std::cout << "\tcreateGroup <groupId> - create new group\n";
  std::cout << "\tdeleteUser <userId> - delete user\n";
  std::cout << "\tdeleteGroup <groupId> - delete group\n";
  std::cout << "\tsetUserToGroup <userId> <groupId> - set user to group\n";
  std::cout << "\tgetUser <userId> - print information for one user\n";
  std::cout << "\tallUsers - print information on all users\n";
  std::cout << "\tgetGroup <groupId> - print information for one group, "
               "including all users who are members of the group\n";
  std::cout << "\tallGroups - print information on all groups, including all "
               "users who are members of them\n\n";
  std::cout << "To end the program, you need to press CTRL+C\n\n";
}

void parseCommandLine(Manager& manager, std::string line) {
  // Удаляем все пробелы справа
  rtrim(line);

  std::string command, user_name;
  int user_id, group_id;
  std::istringstream iss(line);

  iss >> command;

  if (command == "createUser") {
    if (!(iss >> user_id)) {
      std::cout << "Invalid argument: user_id\n";
      return;
    }

    if (!(iss >> user_name)) {
      std::cout << "Invalid argument: user_name\n";
      return;
    }

    if (iss.eof())
      manager.CreateUser(user_id, user_name);
    else {
      if (!(iss >> group_id) || !iss.eof())
        std::cout << "Invalid argument: group_id\n";
      else
        manager.CreateUser(user_id, user_name, group_id);
    }

  } else if (command == "createGroup") {
    if (!(iss >> group_id) || !(iss.eof())) {
      std::cout << "Invalid argument: group_id\n";
      return;
    }

    manager.CreateGroup(group_id);

  } else if (command == "allUsers") {
    if (!iss.eof())
      std::cout << "Error: must be no arguments\n";
    else
      manager.PrintAllUsersInfo();

  } else if (command == "allGroups") {
    if (!iss.eof())
      std::cout << "Error: must be no arguments\n";
    else
      manager.PrintAllGroupsInfo();

  } else if (command == "deleteUser") {
    if (!(iss >> user_id) || !(iss.eof())) {
      std::cout << "Invalid argument: user_id\n";
      return;
    }

    manager.DeleteUser(user_id);

  } else if (command == "deleteGroup") {
    if (!(iss >> group_id) || !(iss.eof())) {
      std::cout << "Invalid argument: group_id\n";
      return;
    }

    manager.DeleteGroup(group_id);

  } else if (command == "getUser") {
    if (!(iss >> user_id) || !(iss.eof())) {
      std::cout << "Invalid argument: user_id\n";
      return;
    }

    manager.PrintUserInfo(user_id);

  } else if (command == "getGroup") {
    if (!(iss >> group_id) || !(iss.eof())) {
      std::cout << "Invalid argument: group_id\n";
      return;
    }

    manager.PrintGroupInfo(group_id);

  } else if (command == "setUserToGroup") {
    if (!(iss >> user_id)) {
      std::cout << "Invalid argument: user_id\n";
      return;
    }

    if (!(iss >> group_id) || !(iss.eof())) {
      std::cout << "Invalid argument: group_id\n";
      return;
    }

    manager.SetUserToGroup(user_id, group_id);

  } else if (command == "help") {
    if (!iss.eof())
      std::cout << "Error: must be no arguments\n";
    else
      printHelp();

  } else
    std::cout << "Unknown command!\n";
}

int main() {
  Manager manager;

  printHelp();
  while (true) {
    std::cout << ">> ";

    std::string line;
    std::getline(std::cin, line);

    if (line.size()) {
      try {
        parseCommandLine(manager, line);
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
    } else {
      std::cout << "\nThe program was successfully completed.\n";
      break;
    }
  }

  return 0;
}
