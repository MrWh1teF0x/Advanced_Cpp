#ifndef PENALTY_SUM_BUILDER_HPP
#define PENALTY_SUM_BUILDER_HPP

#include "cp_builder.hpp"

class PenaltySumBuilder : public CPBuilder {
 public:
  void AddCP(const ControlPoint& cp) override {
    if (!cp.IsMandatory()) {
      total_penalty_ += cp.GetPenalty();
    }
  }

  void Reset() override { total_penalty_ = 0; }

  double GetTotal() const { return total_penalty_; }

 private:
  double total_penalty_ = 0;
};

#endif  // PENALTY_SUM_BUILDER_HPP