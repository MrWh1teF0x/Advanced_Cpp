#ifndef TYPEMAP_HPP
#define TYPEMAP_HPP

#include "typelist.hpp"

template <typename... Types>
class TypeMap {
 public:
  template <typename T>
  void AddValue(const T& value) {
    static_assert(typelist::Contains<T, Keys>::value,
                  "Type doesn't exist in TypeMap!");
    std::get<typelist::IndexOf<T, Keys>::index>(values_) = value;
  }

  template <typename T>
  const T& GetValue() const {
    static_assert(typelist::Contains<T, Keys>::value,
                  "Type doesn't exist in TypeMap!");
    return std::get<typelist::IndexOf<T, Keys>::index>(values_);
  }

  template <typename T>
  static constexpr bool Contains() {
    return typelist::Contains<T, Keys>::value;
  }

  template <typename T>
  void RemoveValue() {
    static_assert(typelist::Contains<T, Keys>::value,
                  "Type doesn't exist in TypeMap!");
    std::get<typelist::IndexOf<T, Keys>::index>(values_) = T{};
  }

 private:
  using Keys = typelist::TypeList<Types...>;
  std::tuple<Types...> values_;
};

#endif  // TYPEMAP_HPP