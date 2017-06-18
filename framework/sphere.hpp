
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
	double area() const override;
	
	double volume() const override;
	
	float const& get_radius() const; 
	glm::vec3 const& get_center() const; 
};


#endif