#include <iostream>
#include "dish_stack.hpp"

DishStack::DishStack() : top_index(-1) {}

void DishStack::push(const Dish& d) {
   if (top_index >= MAX_SIZE - 1) {
      std::cout << "Stack is full, cannot push.\n";
      return;
   }
   top_index++;
   data[top_index] = d;
}

Dish DishStack::pop() {
   if (top_index < 0) {
      std::cout << "Stack is empty, cannot pop.\n";
      return Dish("EMPTY");
   }
   Dish result = data[top_index];
   top_index--;
   return result;
}

Dish DishStack::peek() {
   if (top_index < 0) {
      std::cout << "Stack is empty, nothing to peek.\n";
      return Dish("EMPTY");
   }
   return data[top_index];
}

int DishStack::size() {
   return top_index + 1;
}