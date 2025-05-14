#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <map>

#include "group.hpp"
#include "user.hpp"

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
};

#endif  // MANAGER_HPP