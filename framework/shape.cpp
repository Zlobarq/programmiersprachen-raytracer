#include "shape.hpp"
//constructors
Shape::Shape(): m_name {"Default Shape"}, m_color {Color(0, 0, 0)} {std::cout<< "shape default constructor\n";} //Default

Shape::Shape(std::string const&  name, Color const& color): //User 
	m_name{name},
m_color{color} {std::cout<< "shape user constructor\n";}
Shape::~Shape() {std::cout<< "shape destructor\n";} //destuctor



std::ostream & Shape::print(std::ostream & os) const{
	os << m_name << std::endl << m_color ; 
	return os; 
}

std::ostream & operator <<(std::ostream & os, Shape const& s){
	return s.print(os);
}

std::string Shape::get_name() const
{
	return m_name;
}

Color Shape::get_color() const
{
	return m_color;
}