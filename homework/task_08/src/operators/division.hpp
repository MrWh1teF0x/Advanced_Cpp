#ifndef DIVISION_HPP
#define DIVISION_HPP

#include <stdexcept>

#include "operator.hpp"

class Division : public Operator {
 public:
  using Operator::Operator;

  double Calculate(
      const std::map<std::string, double>& context) const override {
    double denom = right->Calculate(context);
    if (denom == 0) throw std::invalid_argument("Division by zero!");

    return left->Calculate(context) / denom;
  }

  std::string Print() const override {
    return "(" + left->Print() + " / " + right->Print() + ")";
  }
};

#endif  // DIVISION_HPP