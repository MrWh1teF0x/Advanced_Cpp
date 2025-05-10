#ifndef COUNTER_HPP
#define COUNTER_HPP

template <typename T>
class counter {
 public:
  counter() { count_++; }

  counter(const counter&) { count_++; }

  counter(counter&&) noexcept { count_++; }

  ~counter() { count_--; }

  static size_t count() { return count_; }

 private:
  inline static size_t count_ = 0;
};

#endif  // COUNTER_HPP