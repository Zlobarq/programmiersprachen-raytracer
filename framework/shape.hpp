
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
  ~Shape();//Destructor
  //virtual methoden
  virtual double area() const = 0;
  virtual double volume() const = 0;
  virtual std::string get_name() const; 
  virtual Color get_color() const;
  virtual std::ostream & print (std::ostream & os) const;
protected:
std::string m_name;
Color m_color;
};
std::ostream & operator <<(std::ostream & os, Shape const& s);




#endif