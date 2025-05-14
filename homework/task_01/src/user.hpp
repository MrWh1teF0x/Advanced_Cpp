#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <memory>
#include <string>

class Group;

class User {
 public:
  User(int id, std::string name);

  User(int id, std::string name, std::weak_ptr<Group> group_ptr);

  int GetId() const;

  int GetGroupId() const;

  std::string GetName() const;

  void SetGroup(std::weak_ptr<Group> group_ptr);

  void PrintInfo() const;

 private:
  std::string name_;
  int id_;
  std::weak_ptr<Group> group_ptr_;
};

#endif  // USER_HPP