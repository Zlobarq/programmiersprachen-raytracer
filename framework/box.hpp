
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
class Box: public Shape
{
private:
  glm::vec3 m_min;
  glm::vec3 m_max;
  glm::vec3 seiten=m_max-m_min;
  double x=seiten.x;
  double y=seiten.y;
  double z=seiten.z;
public:
	Box ();
	//paralelepiped
	double area() const override{
	return x*y*2+x*z*2+z*y*2;
	}
	//paralelepiped
	double volume() const override{
	return x*y*z;
	}
	glm::vec3 get_min()
	{
		return m_min;
	}
	glm::vec3 get_max()
	{
		return m_max;
	}	
};
#endif