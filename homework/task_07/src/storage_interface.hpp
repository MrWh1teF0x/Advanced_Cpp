#include <memory>
#include <vector>

#ifndef STORAGE_INTERFACE_HPP
#define STORAGE_INTERFACE_HPP

class StorageInterface {
 public:
  virtual ~StorageInterface() = default;

  virtual void Add(int element) = 0;

  virtual void Remove(int element) = 0;

  virtual bool Contains(int element) const = 0;

  virtual std::vector<int> GetAll() const = 0;

  virtual std::unique_ptr<StorageInterface> CreateEmpty() const = 0;
};

#endif  // STORAGE_INTERFACE_HPP