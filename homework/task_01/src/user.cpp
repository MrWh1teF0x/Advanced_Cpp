#include "user.hpp"

#include "group.hpp"

User::User(int id, std::string name) : name_(name), id_(id) {}

User::User(int id, std::string name, std::weak_ptr<Group> group_ptr)
    : id_(id), name_(name), group_ptr_(group_ptr) {}

int User::GetId() const { return id_; }

int User::GetGroupId() const {
  if (group_ptr_.lock()) return group_ptr_.lock()->GetId();
  return -1;
}

std::string User::GetName() const { return name_; }

void User::SetGroup(std::weak_ptr<Group> group_ptr) { group_ptr_ = group_ptr; }

void User::PrintInfo() const {
  std::cout << "------------------------------------------\n";
  std::cout << "===> User ID: " << id_ << '\n';
  std::cout << "===> User Name: " << name_ << '\n';
  std::cout << "===> Group ID: "
            << (group_ptr_.lock() ? std::to_string(group_ptr_.lock()->GetId())
                                  : "none")
            << '\n';
  std::cout << "------------------------------------------\n";
}