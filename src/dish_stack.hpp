#pragma once
#include "dish.hpp"

class DishStack {
private:
    static const int MAX_SIZE = 100;
    Dish data[MAX_SIZE];
    int top_index;

public:
    DishStack();
    void push(const Dish& d);
    Dish pop();
    Dish peek();
    int size();
};