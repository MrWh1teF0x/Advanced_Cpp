#ifndef TYPELIST_HPP
#define TYPELIST_HPP

#include <cstddef>

namespace typelist {

template <typename... Types>
struct TypeList {
  // Получение размера
  static constexpr int Size() { return sizeof...(Types); }
};

// Получение типа по индексу

template <std::size_t Index, typename TList>
struct At;

template <std::size_t Index, typename Head, typename... Types>
struct At<Index, TypeList<Head, Types...>> {
  using type = typename At<Index - 1, TypeList<Types...>>::type;
};

template <typename Head, typename... Types>
struct At<0, TypeList<Head, Types...>> {
  using type = Head;
};

// Проверка наличия типа

template <typename T, typename Head, typename... Types>
struct Contains;

template <typename T, typename Head, typename... Types>
struct Contains<T, TypeList<Head, Types...>> {
  static constexpr bool value =
      std::is_same<T, Head>::value || Contains<T, TypeList<Types...>>::value;
};

template <typename T>
struct Contains<T, TypeList<>> {
  static constexpr bool value = false;
};

// Получение индекса типа

template <typename... Types>
struct IndexOf;

template <typename T, typename... Types>
struct IndexOf<T, TypeList<Types...>> {
  static constexpr size_t index = IndexOf<T, Types...>::index;
};

template <typename T, typename... Types>
struct IndexOf<T, T, Types...> {
  static constexpr size_t index = 0;
};

template <typename T, typename Head, typename... Types>
struct IndexOf<T, Head, Types...> {
  static constexpr size_t index = 1 + IndexOf<T, Types...>::index;
};

template <typename T>
struct IndexOf<T> {
  static_assert(sizeof(T) == 0, "Type doesn't exist in TypeList!");
};

// Добавление в начало

template <typename T, typename TList>
struct PushFront;

template <typename T, typename... Types>
struct PushFront<T, TypeList<Types...>> {
  using type = TypeList<T, Types...>;
};

// Добавление в конец

template <typename T, typename TList>
struct PushBack;

template <typename T, typename... Types>
struct PushBack<T, TypeList<Types...>> {
  using type = TypeList<Types..., T>;
};

}  // namespace typelist

#endif  // TYPELIST_HPP