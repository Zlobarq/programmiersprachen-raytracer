#include "sphere.hpp"
#include <string>
Sphere::Sphere() : Shape{},m_center{0,0,0},m_radius{1.0}
  
{}

glm::vec3 const& Sphere::get_center() const{

	return m_center;
}

float const& Sphere::get_radius() const{

	return m_radius;
}

//area
double Sphere::area() const
{
		return 12.56*m_radius*m_radius;
	}

//volume
double Sphere::volume() const
{
		return m_radius*m_radius*m_radius*4.186;
}