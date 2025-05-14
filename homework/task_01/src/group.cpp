#include "group.hpp"

#include "user.hpp"

Group::Group(int id) : id_(id) {}

int Group::GetId() const { return id_; }

void Group::AddUser(std::weak_ptr<User> user) {
  users_[user.lock()->GetId()] = user;
}

void Group::DeleteUser(int user_id) {
  for (const auto& [id, user] : users_) {
    if (id == user_id) {
      users_.erase(user_id);
      return;
    }
  }

  std::string error_message = "User with ID ";
  error_message += user_id;
  error_message += "doesn't exist in group with ID ";
  error_message += id_;
  error_message += "!\n";

  throw std::invalid_argument(error_message);
}

void Group::PrintInfo() const {
  std::cout << "==========================================\n";
  std::cout << "===> Group ID: " << id_ << '\n';
  std::cout << "===> Users: " << (users_.size() ? "\n" : "none\n");

  int i = 0;
  for (const auto& [id, user] : users_) {
    user.lock()->PrintInfo();
    if (++i != users_.size()) std::cout << '\n';
  }

  std::cout << "==========================================\n";
}