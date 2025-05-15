#ifndef MANDATORY_CP_HPP
#define MANDATORY_CP_HPP

#include "control_point.hpp"

class MandatoryCP : public ControlPoint {
 public:
  MandatoryCP(std::string name, double lat, double lon)
      : name_(std::move(name)), coords_(lat, lon) {}

  std::string GetName() const override { return name_; }

  std::pair<double, double> GetCoords() const override { return coords_; }

  double GetPenalty() const override { return 0; }

  bool IsMandatory() const override { return true; }

 private:
  std::string name_;
  std::pair<double, double> coords_;
};

#endif  // MANDATORY_CP_HPP