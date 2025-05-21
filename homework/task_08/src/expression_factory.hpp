#ifndef EXPRESSION_FACTORY_HPP
#define EXPRESSION_FACTORY_HPP

#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "constant.hpp"
#include "variable.hpp"

class ExpressionFactory {
 public:
  ExpressionFactory() {
    for (int i = -5; i <= 256; i++)
      constants_[i] = std::make_shared<Constant>(i);
  }

  std::shared_ptr<Constant> CreateConstant(double val) {
    auto it = constants_.find(val);
    if (it != constants_.end()) return it->second;

    auto c = std::make_shared<Constant>(val);
    constants_[val] = c;
    return c;
  }

  std::shared_ptr<Variable> CreateVariable(const std::string& name) {
    auto it = variables_.find(name);
    if (it != variables_.end()) return it->second;

    auto v = std::make_shared<Variable>(name);
    variables_[name] = v;
    return v;
  }

  void RemoveVariable(const std::string& name) { variables_.erase(name); }

  void RemoveConstant(double val) {
    if (val < -5 || val > 256) constants_.erase(val);
  }

 private:
  std::unordered_map<double, std::shared_ptr<Constant>> constants_;
  std::unordered_map<std::string, std::shared_ptr<Variable>> variables_;
};

#endif  // EXPRESSION_FACTORY_HPP