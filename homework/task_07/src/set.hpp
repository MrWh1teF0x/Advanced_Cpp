#ifndef SET_HPP
#define SET_HPP

#include <iostream>

#include "array.hpp"
#include "hash_table.hpp"

class Set {
 public:
  Set() : storage_(std::make_unique<Array>()) {}

  void Add(int element) {
    storage_->Add(element);
    CheckStorage();
  }

  void Remove(int element) {
    storage_->Remove(element);
    CheckStorage();
  }

  bool Contains(int element) const { return storage_->Contains(element); }

  Set UnionWith(const Set& other) const {
    Set result;
    for (int el : storage_->GetAll()) {
      result.Add(el);
    }
    for (int el : other.storage_->GetAll()) {
      result.Add(el);
    }
    return result;
  }

  Set IntersectionWith(const Set& other) const {
    Set result;
    for (int el : storage_->GetAll()) {
      if (other.Contains(el)) {
        result.Add(el);
      }
    }
    return result;
  }

  void Print() const {
    auto elements = storage_->GetAll();
    std::cout << "{ ";
    for (int el : elements) {
      std::cout << el << " ";
    }
    std::cout << "}\n";
  }

 private:
  std::unique_ptr<StorageInterface> storage_;
  static constexpr size_t threshold_ = 10;

  void CheckStorage() {
    auto elements = storage_->GetAll();
    if (elements.size() > threshold_ &&
        dynamic_cast<HashTable*>(storage_.get()) == nullptr) {
      auto new_storage = std::make_unique<HashTable>();
      for (int el : elements) {
        new_storage->Add(el);
      }
      storage_ = std::move(new_storage);

    } else if (elements.size() <= threshold_ &&
               dynamic_cast<Array*>(storage_.get()) == nullptr) {
      auto new_storage = std::make_unique<Array>();
      for (int el : elements) {
        new_storage->Add(el);
      }
      storage_ = std::move(new_storage);
    }
  }
};

#endif  // SET_HPP