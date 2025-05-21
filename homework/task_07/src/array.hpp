#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <algorithm>

#include "storage_interface.hpp"

class Array : public StorageInterface {
 public:
  void Add(int element) override {
    if (!Contains(element)) {
      data_.push_back(element);
    }
  }

  void Remove(int element) override {
    auto it = std::find(data_.begin(), data_.end(), element);
    if (it != data_.end()) {
      data_.erase(it);
    }
  }

  bool Contains(int element) const override {
    return std::find(data_.begin(), data_.end(), element) != data_.end();
  }

  std::vector<int> GetAll() const override { return data_; }

  std::unique_ptr<StorageInterface> CreateEmpty() const override {
    return std::make_unique<Array>();
  }

 private:
  std::vector<int> data_;
};

#endif  // ARRAY_HPP