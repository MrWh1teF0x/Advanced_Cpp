#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "expression.hpp"

class Constant : public Expression {
 public:
  Constant(double val) : value_(val) {}

  double Calculate(const std::map<std::string, double>&) const override {
    return value_;
  }

  std::string Print() const override { return std::to_string(value_); }

  double GetValue() const { return value_; }

 private:
  double value_;
};

#endif  // CONSTANT_HPP