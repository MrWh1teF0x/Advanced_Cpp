#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <map>
#include <string>

class Expression {
 public:
  virtual ~Expression() = default;

  virtual double Calculate(
      const std::map<std::string, double>& context) const = 0;

  virtual std::string Print() const = 0;
};

#endif  // EXPRESSION_HPP