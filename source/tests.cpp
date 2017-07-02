#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <ostream>
#include "box.cpp"
#include "sphere.cpp"
#include "shape.cpp"
#include <string>

//Material testmat(std::string {"testmaterial"}, Color{0.0,0.0,0.0}, Color{1.0,1.0,1.0}, Color{0.5,0.5,0.5}, 0.5);


TEST_CASE("Default box constructor", "[get]")
{
  Box box;
  REQUIRE(box.get_min().x == 0);
  REQUIRE(box.get_min().y == 0);
  REQUIRE(box.get_min().z == 0);
  REQUIRE(box.get_max().x == 1);
  REQUIRE(box.get_max().y == 1);
  REQUIRE(box.get_max().z == 1);
  REQUIRE(box.get_name() == "Default Shape");
}





int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}