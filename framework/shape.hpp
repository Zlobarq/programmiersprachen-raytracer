
#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
#include <glm/vec3.hpp>
class Shape
{

public:
	//Constructors
  Shape();//default
  Shape(std::string const& name, Color const& color);//User 
  virtual ~Shape();//Destructor
  //~Shape();//Destructor
  //virtual methoden
  virtual double area() const = 0;
  virtual double volume() const = 0;
  std::string get_name() const; 
  Color get_color() const;
  virtual std::ostream & print (std::ostream & os) const;
private:
std::string m_name;
Color m_color;
};
std::ostream & operator <<(std::ostream & os, Shape const& s);




#endif