#ifndef TYPELIST_HPP
#define TYPELIST_HPP

#include <cstddef>
#include <type_traits>

namespace typelist {

template <typename... Types>
struct TypeList {
  // Получение размера
  static constexpr int size() { return sizeof...(Types); }
};

// Получение типа по индексу

template <std::size_t Index, typename TList>
struct at;

template <std::size_t Index, typename Head, typename... Types>
struct at<Index, TypeList<Head, Types...>> {
  using type = typename at<Index - 1, TypeList<Types...>>::type;
};

template <typename Head, typename... Types>
struct at<0, TypeList<Head, Types...>> {
  using type = Head;
};

// Проверка наличия типа

template <typename T, typename Head, typename... Types>
struct contains;

template <typename T, typename Head, typename... Types>
struct contains<T, TypeList<Head, Types...>> {
  static constexpr bool value =
      std::is_same<T, Head>::value || contains<T, TypeList<Types...>>::value;
};

template <typename T>
struct contains<T, TypeList<>> {
  static constexpr bool value = false;
};

// Получение индекса типа

template <typename... Types>
struct index_of;

template <typename T, typename... Types>
struct index_of<T, TypeList<Types...>> {
  static constexpr size_t index = index_of<T, Types...>::index;
};

template <typename T, typename... Types>
struct index_of<T, T, Types...> {
  static constexpr size_t index = 0;
};

template <typename T, typename Head, typename... Types>
struct index_of<T, Head, Types...> {
  static constexpr size_t index = 1 + index_of<T, Types...>::index;
};

template <typename T>
struct index_of<T> {
  static_assert(sizeof(T) == 0, "Type doesn't exist in TypeList!");
};

// Добавление в начало

template <typename T, typename TList>
struct push_front;

template <typename T, typename... Types>
struct push_front<T, TypeList<Types...>> {
  using type = TypeList<T, Types...>;
};

// Добавление в конец

template <typename T, typename TList>
struct push_back;

template <typename T, typename... Types>
struct push_back<T, TypeList<Types...>> {
  using type = TypeList<Types..., T>;
};

}  // namespace typelist

#endif  // TYPELIST_HPP