#include <iostream>
#include "src/dish.hpp"
#include "src/dish_stack.hpp"

int main() {
  DishStack stack;

  Dish one_dish("A dish with one fish pattern on it");
  Dish two_dish("A dish with two fish patterns on it");
  Dish red_dish("A dish with a red fish pattern on it");
  Dish blue_dish("A dish with a blue fish pattern on it");

  int stack_size = stack.size();
  std::cout << "Initial size: " << stack_size << "\n";

  stack.push(one_dish);
  stack.push(two_dish);
  stack.push(red_dish);
  stack.push(blue_dish);

  int size_after_pushes = stack.size();
  std::cout << "Size after pushes: " << size_after_pushes << "\n";

  Dish peeked_dish = stack.peek();
  std::cout << "Peeked: " << peeked_dish.get_description() << "\n";

  Dish popped_dish = stack.pop();
  std::cout << "Popped: " << popped_dish.get_description() << "\n";

  Dish another_popped_dish = stack.pop();
  std::cout << "Popped again: " << another_popped_dish.get_description() << "\n";

  int final_size = stack.size();
  std::cout << "Final size: " << final_size << "\n";

  return 0;
}
