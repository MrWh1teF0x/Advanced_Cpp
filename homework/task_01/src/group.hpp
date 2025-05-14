#ifndef GROUP_HPP
#define GROUP_HPP

#include <map>
#include <memory>

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

#endif  // GROUP_HPP