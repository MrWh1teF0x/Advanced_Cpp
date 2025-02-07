#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
 public:
  Triangle(double a, double b, double c);

  double area() const override;

 private:
  double m_a, m_b, m_c;
};

#endif  // TRIANGLE_H