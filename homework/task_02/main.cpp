#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "src/typelist.hpp"

using namespace typelist;

struct Temp1;

template <typename T1, typename T2>
struct Temp2;

int main() {
  using EmptyTypeList = TypeList<>;
  using SimpleTypeList = TypeList<char, double, int>;

  // Тесты для EmptyTypeList

  // size
  static_assert(EmptyTypeList::size() == 0,
                "TEST FAILED: EmptyTypeList::size() == 0");

  // contains
  static_assert(contains<int, EmptyTypeList>::value == false,
                "TEST FAILED: contains<int, EmptyTypeList>::value == false");
  static_assert(contains<double, EmptyTypeList>::value == false,
                "TEST FAILED: contains<double, EmptyTypeList>::value == false");
  static_assert(contains<char, EmptyTypeList>::value == false,
                "TEST FAILED: contains<char, EmptyTypeList>::value == false");

  // push_front
  using EmptyPushedFrontTypeList = push_front<char, EmptyTypeList>::type;
  static_assert(EmptyPushedFrontTypeList::size() == 1,
                "TEST FAILED: EmptyPushedFrontTypeList::size() == 1");
  static_assert(
      contains<char, EmptyPushedFrontTypeList>::value == true,
      "TEST FAILED: contains<char, EmptyPushedFrontTypeList>::value == true");
  static_assert(
      contains<int, EmptyPushedFrontTypeList>::value == false,
      "TEST FAILED: contains<int, EmptyPushedFrontTypeList>::value == false");
  static_assert(
      std::is_same<at<0, EmptyPushedFrontTypeList>::type, char>::value == true,
      "TEST FAILED: std::is_same<at<0, EmptyPushedFrontTypeList>::type, "
      "char>::value == true");

  // push_back
  using EmptyPushedBackTypeList = push_back<int, EmptyTypeList>::type;
  static_assert(EmptyPushedBackTypeList::size() == 1,
                "TEST FAILED: EmptyPushedBackTypeList::size() == 1");
  static_assert(
      contains<int, EmptyPushedBackTypeList>::value == true,
      "TEST FAILED: contains<int, EmptyPushedBackTypeList>::value == true");
  static_assert(
      contains<char, EmptyPushedBackTypeList>::value == false,
      "TEST FAILED: contains<char, EmptyPushedBackTypeList>::value == false");
  static_assert(
      std::is_same<at<0, EmptyPushedBackTypeList>::type, int>::value == true,
      "TEST FAILED: std::is_same<at<0, EmptyPushedBackTypeList>::type, "
      "int>::value == true");

  // Тесты для SimpleTypeList

  // size
  static_assert(SimpleTypeList::size() == 3,
                "TEST FAILED: SimpleTypeList::size() == 3");

  // contains
  static_assert(contains<int, SimpleTypeList>::value == true,
                "TEST FAILED: contains<int, SimpleTypeList>::value == true");
  static_assert(contains<double, SimpleTypeList>::value == true,
                "TEST FAILED: contains<double, SimpleTypeList>::value == true");
  static_assert(contains<char, SimpleTypeList>::value == true,
                "TEST FAILED: contains<char, SimpleTypeList>::value == true");
  static_assert(
      contains<std::string, SimpleTypeList>::value == false,
      "TEST FAILED: contains<std::string, SimpleTypeList>::value == false");
  static_assert(
      contains<EmptyTypeList, SimpleTypeList>::value == false,
      "TEST FAILED: contains<EmptyTypeList, SimpleTypeList>::value == false");

  // at
  static_assert(std::is_same<at<0, SimpleTypeList>::type, char>::value == true,
                "TEST FAILED: std::is_same<at<0, SimpleTypeList>::type, "
                "char>::value == true");
  static_assert(
      std::is_same<at<1, SimpleTypeList>::type, double>::value == true,
      "TEST FAILED: std::is_same<at<1, SimpleTypeList>::type, double>::value "
      "== true");
  static_assert(std::is_same<at<2, SimpleTypeList>::type, int>::value == true,
                "TEST FAILED: std::is_same<at<2, SimpleTypeList>::type, "
                "int>::value == true");
  static_assert(
      std::is_same<at<2, SimpleTypeList>::type, double>::value == false,
      "TEST FAILED: std::is_same<at<2, SimpleTypeList>::type, double>::value "
      "== false");

  // index_of
  static_assert(index_of<int, SimpleTypeList>::index == 2,
                "TEST FAILED: index_of<int, SimpleTypeList>::index == 2");
  static_assert(index_of<char, SimpleTypeList>::index == 0,
                "TEST FAILED: index_of<char, SimpleTypeList>::index == 0");
  static_assert(index_of<double, SimpleTypeList>::index == 1,
                "TEST FAILED: index_of<double, SimpleTypeList>::index == 1");

  // push_front
  using SimplePushedFrontTypeList =
      push_front<std::stack<unsigned long long>, SimpleTypeList>::type;
  static_assert(SimplePushedFrontTypeList::size() == 4,
                "TEST FAILED: SimplePushedFrontTypeList::size() == 4");
  static_assert(contains<std::stack<unsigned long long>,
                         SimplePushedFrontTypeList>::value == true,
                "TEST FAILED: contains<std::stack<unsigned long long>, "
                "SimplePushedFrontTypeList>::value == true");
  static_assert(contains<std::vector<unsigned long long>,
                         SimplePushedFrontTypeList>::value == false,
                "TEST FAILED: contains<std::vector<unsigned long long>, "
                "SimplePushedFrontTypeList>::value == false");
  static_assert(
      std::is_same<at<0, SimplePushedFrontTypeList>::type,
                   std::stack<unsigned long long>>::value == true,
      "TEST FAILED: std::is_same<at<0, SimplePushedFrontTypeList>::type, "
      "std::stack<unsigned long long>>::value == true");

  // push_back
  using SimplePushedBackTypeList =
      push_back<std::vector<std::string>, SimpleTypeList>::type;
  static_assert(SimplePushedBackTypeList::size() == 4,
                "TEST FAILED: SimplePushedBackTypeList::size() == 4");
  static_assert(
      contains<std::vector<std::string>, SimplePushedBackTypeList>::value ==
          true,
      "TEST FAILED: contains<std::vector<std::string>, "
      "SimplePushedBackTypeList>::value == true");
  static_assert(
      contains<std::list<std::string>, SimplePushedBackTypeList>::value ==
          false,
      "TEST FAILED: contains<std::list<std::string>, "
      "SimplePushedBackTypeList>::value == false");
  static_assert(std::is_same<at<3, SimplePushedBackTypeList>::type,
                             std::vector<std::string>>::value == true,
                "std::is_same<at<3, SimplePushedBackTypeList>::type, "
                "std::vector<std::string>>::value == true");

  // Тесты для ComplexTypeList

  std::cout << "All tests were passed successfully!\n";
}