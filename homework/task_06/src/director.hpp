#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include <vector>

#include "cp_builder.hpp"

class Director {
 public:
  void SetBuilder(CPBuilder* b) { builder_ = b; }

  void Process(const std::vector<ControlPoint*>& cps) {
    builder_->Reset();
    for (auto cp : cps) {
      builder_->AddCP(*cp);
    }
  }

 private:
  CPBuilder* builder_;
};

#endif  // DIRECTOR_HPP