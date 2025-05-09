#include <iostream>
#include <memory>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.emplace_back(new Rectangle(20, 30));
  shapes.emplace_back(new Circle(10));
  shapes.emplace_back(new Triangle(3, 4, 5));

  double area = 0;
  for (const auto& shape : shapes) area += shape->area();

  std::cout << area << std::endl;
  return 0;
}