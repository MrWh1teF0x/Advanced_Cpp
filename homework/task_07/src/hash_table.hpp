#include <unordered_set>

#include "storage_interface.hpp"

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

class HashTable : public StorageInterface {
 public:
  void Add(int element) override { data_.insert(element); }

  void Remove(int element) override { data_.erase(element); }

  bool Contains(int element) const override {
    return data_.find(element) != data_.end();
  }

  std::vector<int> GetAll() const override {
    return std::vector<int>(data_.begin(), data_.end());
  }

  std::unique_ptr<StorageInterface> CreateEmpty() const override {
    return std::make_unique<HashTable>();
  }

 private:
  std::unordered_set<int> data_;
};

#endif  // HASH_TABLE_HPP