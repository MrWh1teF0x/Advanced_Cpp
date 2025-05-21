#include <iostream>
#include <map>

#include "src/expression.hpp"
#include "src/expression_factory.hpp"
#include "src/operators/addition.hpp"
#include "src/operators/division.hpp"
#include "src/operators/multiplication.hpp"
#include "src/operators/subtraction.hpp"

int main() {
  ExpressionFactory factory;

  std::map<std::string, double> context;

  auto c1 = factory.CreateConstant(34);
  auto c2 = factory.CreateConstant(8);
  auto c3 = factory.CreateConstant(11);

  auto x = factory.CreateVariable("x");
  auto y = factory.CreateVariable("y");

  context["x"] = 5;
  context["y"] = 13;
  context["z"] = 18;
  context["w"] = 12;

  auto expr1 = std::make_shared<Addition>(c1, x);

  std::cout << "Expression 1: " << expr1->Print() << " = "
            << expr1->Calculate(context) << '\n';

  auto expr2 = std::make_shared<Subtraction>(expr1, c2);

  std::cout << "Expression 2: " << expr2->Print() << " = "
            << expr2->Calculate(context) << '\n';

  auto expr3 = std::make_shared<Multiplication>(expr2, y);

  std::cout << "Expression 3: " << expr3->Print() << " = "
            << expr3->Calculate(context) << '\n';

  auto expr4 = std::make_shared<Division>(expr3, c3);

  std::cout << "Expression 4: " << expr4->Print() << " = "
            << expr4->Calculate(context) << '\n';

  return 0;
}
