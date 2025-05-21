#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <memory>

#include "../expression.hpp"

class Operator : public Expression {
 public:
  Operator(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
      : left(std::move(l)), right(std::move(r)) {}

 protected:
  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};

#endif  // OPERATOR_HPP