#include "circle.h"

#include <cmath>

Circle::Circle(double radius) : Shape("circle"), m_radius(radius) {}

double Circle::area() const { return M_PI * m_radius * m_radius; }