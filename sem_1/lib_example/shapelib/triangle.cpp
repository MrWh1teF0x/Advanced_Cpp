#include "triangle.h"

#include <cmath>

Triangle::Triangle(double a, double b, double c)
    : Shape("tringle"), m_a(a), m_b(b), m_c(c) {}

double Triangle::area() const {
  double p = 0.5 * (m_a + m_b + m_c);
  return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}