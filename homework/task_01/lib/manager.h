#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <map>

#include "group.h"
#include "user.h"

class Manager {
 public:
  Manager();

  bool IsUserExists(int id) const;

  bool IsGroupExists(int id) const;

  void CreateUser(int id, std::string name);

  void CreateUser(int id, std::string name, int group_id);

  void CreateGroup(int id);

  void DeleteUser(int id);

  void DeleteGroup(int id);

  void SetUserToGroup(int user_id, int group_id);

  void PrintUserInfo(int id) const;

  void PrintAllUsersInfo() const;

  void PrintGroupInfo(int id) const;

  void PrintAllGroupsInfo() const;

 private:
  std::map<int, std::shared_ptr<User>> all_users_;
  std::map<int, std::shared_ptr<Group>> all_groups_;

  int FindUserIndex(int id) const;

  int FindGroupIndex(int id) const;
};

#endif  // MANAGER_H