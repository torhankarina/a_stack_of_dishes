#pragma once
#include <string>

class Dish {
private:
  std::string description;

public:
  Dish() : description("EMPTY") {}
  Dish(std::string description) {
    this->description = description;
  }

  std::string get_description() {
    return this->description;
  }
};