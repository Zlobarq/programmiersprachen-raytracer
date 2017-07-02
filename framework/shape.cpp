#include "shape.hpp"
//constructors
Shape::Shape(): m_name {"Default Shape"}, m_material {} {//std::cout<< "shape default constructor\n";
} //Default

Shape::Shape(std::string const&  name, Material const& material): //User 
	m_name{name},
m_material{material} {//std::cout<< "shape user constructor\n";
}
Shape::~Shape() {//std::cout<< "shape destructor\n";
} //destuctor



std::ostream & Shape::print(std::ostream & os) const{
	os << m_name << std::endl << m_material ; 
	return os; 
}

std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}

std::string Shape::get_name() const
{
	return m_name;
}

Material Shape::get_material() const
{
	return m_material;
}
