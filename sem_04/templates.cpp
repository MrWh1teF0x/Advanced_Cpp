#include <iostream>

template <typename T>
void func(T&& var) {
  std::cout << "template " << var << std::endl;
}

void func(int&& var) { std::cout << "simple " << var << std::endl; }

int main() {
  const int a = 5;

  func(5);
  func(std::move(a));
}