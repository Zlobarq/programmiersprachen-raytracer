
#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
class Shape
{
protected:
std::string m_name;
Color m_color;
public:
  Shape ();
  Shape(std::string name,Color const& color) : m_name {"Default Shape"}, m_color {Color(0, 0, 0)} {}
  virtual double area() const = 0;
  virtual double volume() const = 0;

};





#endif