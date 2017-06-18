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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}