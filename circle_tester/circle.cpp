#include "circle.h"
#include <cmath>
#include <iostream>

using std::ostream;
using std::pow;

// function definitions
double Circle::get_diameter() const { return 2 * radius; }

double Circle::get_circumference() const { return get_diameter() * pi; }

double Circle::get_area() const { return pi * pow(radius, 2.0); }

// operator definitions go here
Circle Circle::operator+(const Circle &other) const {
  return Circle(this->radius + other.get_radius());
}

Circle Circle::operator-(const Circle &other) const {
  return Circle(this->radius - other.get_radius());
}

Circle &Circle::operator++() {
  ++radius;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Circle &circle) {
  os << "radius=" << circle.get_radius()
     << "|diameter=" << circle.get_diameter()
     << "|circumference=" << circle.get_circumference()
     << "|area=" << circle.get_area() << '\n';
  return os;
}
