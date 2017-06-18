
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
class Sphere: public Shape
{
protected:
  glm::vec3 m_center;
  double m_radius;
public:
	Sphere (); // default constructor
	Sphere(std::string const& name, Color const& color,glm::vec3 const& center,double const& radius); //user
	~Sphere();//destructor

	double area() const override;
	double volume() const override;
	std::ostream & print (std::ostream & os) const override;
	
	float const& get_radius() const; 
	glm::vec3 const& get_center() const; 
};


#endif