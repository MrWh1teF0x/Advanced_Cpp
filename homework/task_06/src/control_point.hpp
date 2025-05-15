#ifndef CONTROL_POINT_HPP
#define CONTROL_POINT_HPP

#include <string>

class ControlPoint {
 public:
  virtual ~ControlPoint() = default;

  virtual std::string GetName() const = 0;

  virtual std::pair<double, double> GetCoords() const = 0;

  virtual double GetPenalty() const = 0;

  virtual bool IsMandatory() const = 0;
};

#endif  // CONTROL_POINT_HPP