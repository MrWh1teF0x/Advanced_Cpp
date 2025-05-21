#include <cassert>

#include "src/array.hpp"
#include "src/hash_table.hpp"
#include "src/set.hpp"
#include "src/storage_interface.hpp"

int main() {
  Set A;
  for (int i = 1; i <= 18; i++) A.Add(i);

  assert(A.Contains(1) == true);
  assert(A.Contains(18) == true);
  assert(A.Contains(19) == false);

  for (int i = 13; i <= 18; i++) A.Remove(i);

  assert(A.Contains(12) == true);
  assert(A.Contains(13) == false);
  assert(A.Contains(18) == false);

  std::cout << "Множество A: ";
  A.Print();

  Set B;
  B.Add(5);
  B.Add(10);
  B.Add(15);

  std::cout << "Множество B: ";
  B.Print();

  auto C = A.UnionWith(B);
  std::cout << "Объединение A и B: ";
  C.Print();

  auto D = A.IntersectionWith(B);
  std::cout << "Пересечение A и B: ";
  D.Print();

  return 0;
}
