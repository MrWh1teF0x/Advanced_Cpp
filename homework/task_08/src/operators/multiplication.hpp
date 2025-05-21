#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include "operator.hpp"

class Multiplication : public Operator {
 public:
  using Operator::Operator;

  double Calculate(
      const std::map<std::string, double>& context) const override {
    return left->Calculate(context) * right->Calculate(context);
  }

  std::string Print() const override {
    return "(" + left->Print() + " * " + right->Print() + ")";
  }
};

#endif  // MULTIPLICATION_HPP