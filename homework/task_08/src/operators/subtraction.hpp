#ifndef SUBTRACTION_HPP
#define SUBTRACTION_HPP

#include "operator.hpp"

class Subtraction : public Operator {
 public:
  using Operator::Operator;

  double Calculate(
      const std::map<std::string, double>& context) const override {
    return left->Calculate(context) - right->Calculate(context);
  }

  std::string Print() const override {
    return "(" + left->Print() + " - " + right->Print() + ")";
  }
};

#endif  // SUBTRACTION_HPP