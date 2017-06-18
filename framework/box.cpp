#include "box.hpp"
#include <string>
Box::Box() : Shape(), m_min{0,0,0},m_max{1,1,1} // default constructor
{}
Box::Box(std::string const& name,Color const& color,glm::vec3 const& min,glm::vec3 const& max)://user constructor
Shape(name,color),
m_min{min},
m_max{max}
{}

Box::~Box() {}; //desturctor



glm::vec3 const& Box::get_min() const
{
	return m_min;
}
glm::vec3 const& Box::get_max() const
{
	return m_max;
}	

double Box::area() const
{
	return x*y*2+x*z*2+z*y*2;
}
double Box::volume() const
{
	return x*y*z;
}