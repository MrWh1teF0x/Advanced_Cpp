#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "src/typelist.hpp"

using namespace typelist;

int main() {
  using EmptyTypeList = TypeList<>;
  using SimpleTypeList = TypeList<char, double, int>;

  // Тесты для EmptyTypeList

  // Size
  static_assert(EmptyTypeList::Size() == 0,
                "TEST FAILED: EmptyTypeList::Size() == 0");

  // Contains
  static_assert(Contains<int, EmptyTypeList>::value == false,
                "TEST FAILED: Contains<int, EmptyTypeList>::value == false");
  static_assert(Contains<double, EmptyTypeList>::value == false,
                "TEST FAILED: Contains<double, EmptyTypeList>::value == false");
  static_assert(Contains<char, EmptyTypeList>::value == false,
                "TEST FAILED: Contains<char, EmptyTypeList>::value == false");

  // PushFront
  using EmptyPushedFrontTypeList = PushFront<char, EmptyTypeList>::type;
  static_assert(EmptyPushedFrontTypeList::Size() == 1,
                "TEST FAILED: EmptyPushedFrontTypeList::Size() == 1");
  static_assert(
      Contains<char, EmptyPushedFrontTypeList>::value == true,
      "TEST FAILED: Contains<char, EmptyPushedFrontTypeList>::value == true");
  static_assert(
      Contains<int, EmptyPushedFrontTypeList>::value == false,
      "TEST FAILED: Contains<int, EmptyPushedFrontTypeList>::value == false");
  static_assert(
      std::is_same<At<0, EmptyPushedFrontTypeList>::type, char>::value == true,
      "TEST FAILED: std::is_same<At<0, EmptyPushedFrontTypeList>::type, "
      "char>::value == true");

  // PushBack
  using EmptyPushedBackTypeList = PushBack<int, EmptyTypeList>::type;
  static_assert(EmptyPushedBackTypeList::Size() == 1,
                "TEST FAILED: EmptyPushedBackTypeList::Size() == 1");
  static_assert(
      Contains<int, EmptyPushedBackTypeList>::value == true,
      "TEST FAILED: Contains<int, EmptyPushedBackTypeList>::value == true");
  static_assert(
      Contains<char, EmptyPushedBackTypeList>::value == false,
      "TEST FAILED: Contains<char, EmptyPushedBackTypeList>::value == false");
  static_assert(
      std::is_same<At<0, EmptyPushedBackTypeList>::type, int>::value == true,
      "TEST FAILED: std::is_same<At<0, EmptyPushedBackTypeList>::type, "
      "int>::value == true");

  // Тесты для SimpleTypeList

  // Size
  static_assert(SimpleTypeList::Size() == 3,
                "TEST FAILED: SimpleTypeList::Size() == 3");

  // Contains
  static_assert(Contains<int, SimpleTypeList>::value == true,
                "TEST FAILED: Contains<int, SimpleTypeList>::value == true");
  static_assert(Contains<double, SimpleTypeList>::value == true,
                "TEST FAILED: Contains<double, SimpleTypeList>::value == true");
  static_assert(Contains<char, SimpleTypeList>::value == true,
                "TEST FAILED: Contains<char, SimpleTypeList>::value == true");
  static_assert(
      Contains<std::string, SimpleTypeList>::value == false,
      "TEST FAILED: Contains<std::string, SimpleTypeList>::value == false");
  static_assert(
      Contains<EmptyTypeList, SimpleTypeList>::value == false,
      "TEST FAILED: Contains<EmptyTypeList, SimpleTypeList>::value == false");

  // At
  static_assert(std::is_same<At<0, SimpleTypeList>::type, char>::value == true,
                "TEST FAILED: std::is_same<At<0, SimpleTypeList>::type, "
                "char>::value == true");
  static_assert(
      std::is_same<At<1, SimpleTypeList>::type, double>::value == true,
      "TEST FAILED: std::is_same<At<1, SimpleTypeList>::type, double>::value "
      "== true");
  static_assert(std::is_same<At<2, SimpleTypeList>::type, int>::value == true,
                "TEST FAILED: std::is_same<At<2, SimpleTypeList>::type, "
                "int>::value == true");
  static_assert(
      std::is_same<At<2, SimpleTypeList>::type, double>::value == false,
      "TEST FAILED: std::is_same<At<2, SimpleTypeList>::type, double>::value "
      "== false");

  // IndexOf
  static_assert(IndexOf<int, SimpleTypeList>::index == 2,
                "TEST FAILED: IndexOf<int, SimpleTypeList>::index == 2");
  static_assert(IndexOf<char, SimpleTypeList>::index == 0,
                "TEST FAILED: IndexOf<char, SimpleTypeList>::index == 0");
  static_assert(IndexOf<double, SimpleTypeList>::index == 1,
                "TEST FAILED: IndexOf<double, SimpleTypeList>::index == 1");

  // PushFront
  using SimplePushedFrontTypeList =
      PushFront<std::stack<unsigned long long>, SimpleTypeList>::type;
  static_assert(SimplePushedFrontTypeList::Size() == 4,
                "TEST FAILED: SimplePushedFrontTypeList::Size() == 4");
  static_assert(Contains<std::stack<unsigned long long>,
                         SimplePushedFrontTypeList>::value == true,
                "TEST FAILED: Contains<std::stack<unsigned long long>, "
                "SimplePushedFrontTypeList>::value == true");
  static_assert(Contains<std::vector<unsigned long long>,
                         SimplePushedFrontTypeList>::value == false,
                "TEST FAILED: Contains<std::vector<unsigned long long>, "
                "SimplePushedFrontTypeList>::value == false");
  static_assert(
      std::is_same<At<0, SimplePushedFrontTypeList>::type,
                   std::stack<unsigned long long>>::value == true,
      "TEST FAILED: std::is_same<At<0, SimplePushedFrontTypeList>::type, "
      "std::stack<unsigned long long>>::value == true");

  // PushBack
  using SimplePushedBackTypeList =
      PushBack<std::vector<std::string>, SimpleTypeList>::type;
  static_assert(SimplePushedBackTypeList::Size() == 4,
                "TEST FAILED: SimplePushedBackTypeList::Size() == 4");
  static_assert(
      Contains<std::vector<std::string>, SimplePushedBackTypeList>::value ==
          true,
      "TEST FAILED: Contains<std::vector<std::string>, "
      "SimplePushedBackTypeList>::value == true");
  static_assert(
      Contains<std::list<std::string>, SimplePushedBackTypeList>::value ==
          false,
      "TEST FAILED: Contains<std::list<std::string>, "
      "SimplePushedBackTypeList>::value == false");
  static_assert(std::is_same<At<3, SimplePushedBackTypeList>::type,
                             std::vector<std::string>>::value == true,
                "std::is_same<At<3, SimplePushedBackTypeList>::type, "
                "std::vector<std::string>>::value == true");

  // Тесты для ComplexTypeList

  std::cout << "All tests were passed successfully!\n";
}