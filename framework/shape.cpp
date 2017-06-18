#include "shape.hpp"
//constructors
Shape::Shape(): m_name {"Default Shape"}, m_color {Color(0, 0, 0)} {} //Default

Shape::Shape(std::string const&  name, Color const& color): //User 
	m_name{name},
m_color{color} {}
Shape::~Shape() {} //destuctor
