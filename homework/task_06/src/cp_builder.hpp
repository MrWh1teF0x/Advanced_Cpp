#ifndef CP_BUILDER_HPP
#define CP_BUILDER_HPP

#include "control_point.hpp"

class CPBuilder {
 public:
  virtual ~CPBuilder() = default;

  virtual void AddCP(const ControlPoint& cp) = 0;

  virtual void Reset() = 0;
};

#endif  // CP_BUILDER_HPP