
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
class Sphere: public Shape
{
private:
  glm::vec3 m_center;
  double m_radius;
public:
	Sphere ();
	double area() const override{
	return 12.56*m_radius*m_radius;
	}
	double volume() const override{
	return m_radius*m_radius*m_radius*4.186;
	}
	float get_radius() {return m_radius;}
	glm::vec3 get_center() {return m_center;}
};


#endif