#include "manager.hpp"

Manager::Manager() {}

bool Manager::IsUserExists(int id) const {
  for (const auto& [user_id, user] : all_users_)
    if (user_id == id) return true;
  return false;
}

bool Manager::IsGroupExists(int id) const {
  for (const auto [group_id, group] : all_groups_)
    if (group_id == id) return true;
  return false;
}

void Manager::CreateUser(int id, std::string name) {
  if (id < 0)
    std::cout << "User ID must be greater than 0!\n";
  else if (IsUserExists(id))
    std::cout << "User with this ID already exists!\n";
  else {
    all_users_[id] = std::make_shared<User>(id, name);

    std::cout << "User was created!\n";
  }
}

void Manager::CreateUser(int id, std::string name, int group_id) {
  if (id < 0)
    std::cout << "User ID must be greater than 0!\n";
  else if (IsUserExists(id))
    std::cout << "User with this ID already exists!\n";
  else {
    if (!IsGroupExists(group_id)) {
      std::cout << "Group with this ID doesn't exist!\n";
      return;
    }

    auto user = std::make_shared<User>(id, name, all_groups_[group_id]);
    all_users_[id] = user;
    all_groups_[group_id]->AddUser(user);

    std::cout << "User was created!\n";
  }
}

void Manager::CreateGroup(int id) {
  if (id < 0)
    std::cout << "Group ID must be greater than 0!\n";
  else if (IsGroupExists(id))
    std::cout << "Group with this ID already exists!\n";
  else {
    all_groups_[id] = std::make_shared<Group>(id);

    std::cout << "Group was created!\n";
  }
}

void Manager::DeleteUser(int id) {
  if (!IsUserExists(id))
    std::cout << "User with this ID doesn't exist!\n";
  else {
    int group_id = all_users_[id]->GetGroupId();
    if (group_id != -1) all_groups_[group_id]->DeleteUser(id);

    all_users_.erase(id);

    std::cout << "User with ID " << id << " was deleted!\n";
  }
}

void Manager::DeleteGroup(int id) {
  if (!IsGroupExists(id))
    std::cout << "Group with this ID doesn't exist!\n";
  else {
    all_groups_.erase(id);

    std::cout << "Group was deleted!\n";
  }
}

void Manager::SetUserToGroup(int user_id, int group_id) {
  if (!IsUserExists(user_id)) std::cout << "User with this ID doesn't exist!\n";
  if (!IsGroupExists(group_id))
    std::cout << "Group with this ID doesn't exist!\n";

  auto group = all_groups_[group_id];
  auto user = all_users_[user_id];

  try {
    if (user->GetGroupId() != -1)
      all_groups_[user->GetGroupId()]->DeleteUser(user_id);

    user->SetGroup(group);
    group->AddUser(user);

    std::cout << "User with ID " << user_id << " was added in group with ID "
              << group_id << "!\n";
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}

void Manager::PrintUserInfo(int id) const {
  if (!IsUserExists(id))
    std::cout << "User with this ID doesn't exist!\n";
  else
    all_users_.at(id)->PrintInfo();
}

void Manager::PrintAllUsersInfo() const {
  if (!all_users_.size()) {
    std::cout << "There are no users!\n";
    return;
  }

  int i = 0;
  for (const auto& [id, user] : all_users_) {
    user->PrintInfo();
    if (++i != all_users_.size()) std::cout << '\n';
  }
}

void Manager::PrintGroupInfo(int id) const {
  if (!IsGroupExists(id))
    std::cout << "Group with this ID doesn't exist!\n";
  else
    all_groups_.at(id)->PrintInfo();
}

void Manager::PrintAllGroupsInfo() const {
  if (!all_groups_.size()) {
    std::cout << "There are no groups!\n";
    return;
  }

  int i = 0;
  for (const auto& [id, group] : all_groups_) {
    PrintGroupInfo(group->GetId());
    if (++i != all_groups_.size()) std::cout << '\n';
  }
}
