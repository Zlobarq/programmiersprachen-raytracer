#include "shape.hpp"
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include <glm/vec3.hpp>
class Sphere: public Shape
{
public:
	Sphere ();
	double area() const override{
	return 0;
	}
	double volume() const override{
	return 0;
	}
private:
  glm::vec3 m_center;
  double m_radius;
};


#endif