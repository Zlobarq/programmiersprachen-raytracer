
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
class Box: public Shape
{
protected:
  glm::vec3 m_min;
  glm::vec3 m_max;
  glm::vec3 seiten=m_max-m_min;
  double x=seiten.x;
  double y=seiten.y;
  double z=seiten.z;
public:
	Box (); // default constructor
	Box(std::string const& name,Color const& color,glm::vec3 const& min,glm::vec3 const& max); //user
	~Box(); //destructor
	
	double area() const override;
	double volume() const override;
	std::ostream & print (std::ostream & os) const override;

	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;
};
#endif