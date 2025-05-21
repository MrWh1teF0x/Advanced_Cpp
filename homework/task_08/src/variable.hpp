#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <stdexcept>

#include "expression.hpp"

class Variable : public Expression {
 public:
  explicit Variable(const std::string& n) : name_(n) {}

  double Calculate(
      const std::map<std::string, double>& context) const override {
    auto it = context.find(name_);
    if (it == context.end()) {
      throw std::runtime_error("Variable '" + name_ + "' not found in context");
    }
    return it->second;
  }

  std::string Print() const override { return name_; }

  const std::string& getName() const { return name_; }

 private:
  std::string name_;
};

#endif  // EXPRESSION_HPP