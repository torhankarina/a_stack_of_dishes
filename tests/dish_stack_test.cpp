#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/dish_stack.hpp"
#include "../src/dish.hpp"

TEST_CASE("Initial stack is empty") {
    DishStack stack;
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.peek().get_description() == "EMPTY");
    REQUIRE(stack.pop().get_description() == "EMPTY");
}

TEST_CASE("Push increases size") {
    DishStack stack;
    Dish d1("Dish1");
    Dish d2("Dish2");
    stack.push(d1);
    REQUIRE(stack.size() == 1);
    stack.push(d2);
    REQUIRE(stack.size() == 2);
}

TEST_CASE("Peek returns top element without removing") {
    DishStack stack;
    Dish d1("TopDish");
    stack.push(d1);
    REQUIRE(stack.peek().get_description() == "TopDish");
    REQUIRE(stack.size() == 1); // peek should not remove
}

TEST_CASE("Pop removes and returns top element") {
    DishStack stack;
    Dish d1("Dish1");
    Dish d2("Dish2");
    stack.push(d1);
    stack.push(d2);
    REQUIRE(stack.pop().get_description() == "Dish2");
    REQUIRE(stack.size() == 1);
    REQUIRE(stack.pop().get_description() == "Dish1");
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.pop().get_description() == "EMPTY"); // popping empty stack
}

TEST_CASE("Stack prevents overflow beyond MAX_SIZE") {
    DishStack stack;
    for (int i = 0; i < 100; i++) {
        stack.push(Dish("Dish " + std::to_string(i)));
    }
    REQUIRE(stack.size() == 100);
    stack.push(Dish("Overflow Dish")); // should not increase size
    REQUIRE(stack.size() == 100);
}