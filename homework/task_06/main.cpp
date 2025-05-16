#include "src/control_point.hpp"
#include "src/director.hpp"
#include "src/mandatory_cp.hpp"
#include "src/optional_cp.hpp"
#include "src/penalty_sum_builder.hpp"
#include "src/text_list_builder.hpp"

int main() {
  std::vector<ControlPoint*> cps = {
      new MandatoryCP("Start", 55.7558, 37.6173),
      new MandatoryCP("CP1", 55.7600, 37.6200),
      new OptionalCP("CP2", 55.7600, 37.6200, 1.5),
      new OptionalCP("CP3", 55.7600, 37.6200, 1.5),
      new MandatoryCP("CP4", 55.7600, 37.6200),
      new OptionalCP("CP5", 55.7600, 37.6200, 1.5),
      new MandatoryCP("Finish", 55.7650, 37.6250)};

  Director director;

  TextListBuilder text_builder;
  director.SetBuilder(&text_builder);
  director.SetCPs(cps);
  std::cout << "Список КП:\n";
  text_builder.Print();

  PenaltySumBuilder penalty_builder;
  director.SetBuilder(&penalty_builder);
  director.SetCPs(cps);
  std::cout << "\nСуммарный штраф: " << penalty_builder.GetTotal()
            << " часов\n";

  for (auto cp : cps) delete cp;

  return 0;
}