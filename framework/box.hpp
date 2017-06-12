#include "shape.hpp"
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include <glm/vec3.hpp>
class Box: public Shape
{
public:
	Box ();
	//paralelepiped
	double area() const override{
	return 0;
	}
	//paralelepiped
	double volume() const override{
	return 0;
	}
private:
  glm::vec3 m_min;
  glm::vec3 m_max;
};
#endif