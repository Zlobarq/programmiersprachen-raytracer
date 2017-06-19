#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "box.cpp"
#include "sphere.cpp"
#include "shape.cpp"




TEST_CASE("Default box constructor", "[get]")
{
  Box box;
  REQUIRE(box.get_min().x == 0);
  REQUIRE(box.get_min().y == 0);
  REQUIRE(box.get_min().z == 0);
  REQUIRE(box.get_max().x == 1);
  REQUIRE(box.get_max().y == 1);
  REQUIRE(box.get_max().z == 1);
  REQUIRE(box.get_color().r == 0);
  REQUIRE(box.get_color().g == 0);
  REQUIRE(box.get_color().b == 0);
  REQUIRE(box.get_name() == "Default Shape");
}



TEST_CASE("Default sphere constructor", "[get]")
{
  Sphere sphere;
  REQUIRE(sphere.get_center().x == 0);
  REQUIRE(sphere.get_center().y == 0);
  REQUIRE(sphere.get_center().z == 0);
  REQUIRE(sphere.get_radius() == 1);
  REQUIRE(sphere.get_color().r == 0);
  REQUIRE(sphere.get_color().g == 0);
  REQUIRE(sphere.get_color().b == 0);
  REQUIRE(sphere.get_name() == "Default Shape");
}

TEST_CASE("User box constructor", "[get]")
{
Box box ("mybox",Color{1.0,3.0,5.0},glm::vec3{1.0,1.0,1.0},glm::vec3{2.0,2.0,2.0});
  REQUIRE(box.get_min().x == 1);
  REQUIRE(box.get_min().y == 1);
  REQUIRE(box.get_min().z == 1);
  REQUIRE(box.get_max().x == 2);
  REQUIRE(box.get_max().y == 2);
  REQUIRE(box.get_max().z == 2);
  REQUIRE(box.get_color().r == 1);
  REQUIRE(box.get_color().g == 3);
  REQUIRE(box.get_color().b == 5);
  REQUIRE(box.get_name() == "mybox");
}
TEST_CASE("User sphere constructor", "[get]")
{
Sphere sphere ("mysphere", Color{1.0,3.0,5.0},glm::vec3{3.0,3.0,3.0},12.5);
  REQUIRE(sphere.get_center().x == 3);
  REQUIRE(sphere.get_center().y == 3);
  REQUIRE(sphere.get_center().z == 3);
  REQUIRE(sphere.get_color().r == 1);
  REQUIRE(sphere.get_color().g == 3);
  REQUIRE(sphere.get_color().b == 5);
  REQUIRE(sphere.get_radius() == 12.5);
  REQUIRE(sphere.get_name() == "mysphere");
}
TEST_CASE("box area and volume", "[boxformula]")
{
  Box box ("mybox",Color{1.0,3.0,5.0},glm::vec3{2.0,2.0,2.0},glm::vec3{6.0,6.0,6.0});
  REQUIRE(box.volume() == 64.0);
  REQUIRE(box.area() == 96.0);
}
TEST_CASE("sphere area and volume", "[boxformula]")
{
Sphere sphere ("mysphere", Color{1.0,3.0,5.0},glm::vec3{3.0,3.0,3.0},5);
REQUIRE(sphere.area() == 314.0);
REQUIRE(sphere.volume() == Approx(523.25));
}
TEST_CASE("print figures", "[print]")
{
  Box box;
  Sphere sphere;
  box.print(std::cout);
  sphere.print(std::cout);
}

TEST_CASE("5.7,[staticdynamic]")
{

std::cout<< "5.7\n";
std::cout<< "Static type checking means that type checking occurs at compile time."<< 
"\n No type information is used at runtime in that case.\n ";

std::cout<< "\n Dynamic type checking occurs when type information is used at runtime."<<
"\n C++ uses a mechanism called RTTI (runtime type information) to implement this.";
std::cout<< "\n source: https://stackoverflow.com/questions/1347691/static-vs-dynamic-type-checking-in-c\n ";

Color red (255 , 0 , 0);
glm::vec3 position (0,0,0);
std::shared_ptr<Sphere> s1 =
std::make_shared<Sphere>("sphere0",red,position,1.2);
std::shared_ptr<Shape> s2 =
std::make_shared<Sphere>("sphere1",red,position,1.2);
s1->print(std::cout);
s2->print(std::cout);
}







TEST_CASE("Destructor virtual/nicht virtual", "[destructor]")
{
// NON-VIRTUAL
// ../source/tests.cpp:98:10: NON-VIRTUAL warning: deleting object of polymorphic class 
//type ‘Sphere’ which has non-virtual destructor might cause undefined behavior 
  std::cout<< "5.8\n";
  Color red(250, 0, 0);
  glm::vec3 position(0,0,0);

  Sphere* s1 = new Sphere("sphere0", red,position, 1.2);
  Shape* s2 = new Sphere("sphere1", red,position, 1.2);

  s1->print(std::cout);
  s2->print(std::cout);

  delete s1;
  delete s2;
std::cout<< "\nNON-VIRTUAL\n../source/tests.cpp:98:10: NON-VIRTUAL warning:\ndeleting object of polymorphic class:\ntype ‘Sphere’ which has non-virtual destructor might cause undefined behavior\n";
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}