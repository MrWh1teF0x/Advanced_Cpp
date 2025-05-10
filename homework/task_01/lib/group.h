#ifndef GROUP_H
#define GROUP_H

#include <map>
#include <memory>
#include <string>

class User;

class Group {
 public:
  Group(int id);

  int GetId() const;

  void AddUser(std::weak_ptr<User> user);

  void DeleteUser(int user_id);

  void PrintInfo() const;

 private:
  int id_;
  std::map<int, std::weak_ptr<User>> users_;
};

#endif  // GROUP_H