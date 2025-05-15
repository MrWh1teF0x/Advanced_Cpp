#ifndef OPTIONAL_CP_HPP
#define OPTIONAL_CP_HPP

#include "control_point.hpp"

class OptionalCP : public ControlPoint {
 public:
  OptionalCP(std::string name, double lat, double lon, double penalty)
      : name_(std::move(name)), coords_(lat, lon), penalty_(penalty) {}

  std::string GetName() const override { return name_; }

  std::pair<double, double> GetCoords() const override { return coords_; }

  double GetPenalty() const override { return penalty_; }

  bool IsMandatory() const override { return false; }

 private:
  std::string name_;
  std::pair<double, double> coords_;
  double penalty_;
};

#endif  // OPTIONAL_CP_HPP