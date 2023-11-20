#include "circle.h"
#include <cmath>
#include <iostream>

int main() {
  // print name of program
  std::cout << "Circle Tester\n\n";

  // create and std::cout<<  Circle object
  Circle circle1(20);
  std::cout << "CIRCLE 1:\n";
  std::cout << (circle1);
  std::cout << '\n';

  Circle circle2(10);
  std::cout << "CIRCLE 2:\n";
  std::cout << (circle2);
  std::cout << '\n';

  // test the addition and subtraction operators
  Circle circle3 = circle1 + circle2;
  std::cout << "CIRCLE 3 (CIRCLE 1 + CIRCLE2):\n";
  std::cout << (circle3);
  std::cout << '\n';

  Circle circle4 = circle1 - circle2;
  std::cout << "CIRCLE 4 (CIRCLE 1 - CIRCLE2):\n";
  std::cout << (circle4);
  std::cout << '\n';

  // test the increment operator
  ++circle4;
  std::cout << "CIRCLE 4 after ++:\n";
  std::cout << (circle4);
  std::cout << '\n';
}
