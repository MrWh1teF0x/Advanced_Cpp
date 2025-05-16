#ifndef TEXT_LIST_BUILDER_HPP
#define TEXT_LIST_BUILDER_HPP

#include <iostream>
#include <vector>

#include "cp_builder.hpp"

class TextListBuilder : public CPBuilder {
 public:
  void AddCP(const ControlPoint& cp) override {
    auto [lat, lon] = cp.GetCoords();
    std::string penalty = cp.IsMandatory()
                              ? "незачёт СУ"
                              : std::to_string(cp.GetPenalty()) + " часов";

    entries_.push_back(std::to_string(counter_++) + ". " + cp.GetName() +
                       " | " + std::to_string(lat) + ", " +
                       std::to_string(lon) + " | " + penalty);
  }

  void Reset() override {
    entries_.clear();
    counter_ = 1;
  }

  void Print() const {
    for (const auto& entry : entries_) {
      std::cout << entry << std::endl;
    }
  }

 private:
  std::vector<std::string> entries_;
  int counter_ = 1;
};

#endif  // TEXT_LIST_BUILDER_HPP