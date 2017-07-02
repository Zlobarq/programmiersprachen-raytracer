#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <ostream>
#include "color.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "material.hpp"
#include <string>

Material testmat(std::string {"testmaterial"}, Color{0.0,0.0,0.0}, Color{1.0,1.0,1.0}, Color{0.5,0.5,0.5}, 0.5);


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
  REQUIRE(box.get_material().m_name == "no_mat");
  Color boxka = box.get_material().m_ka;
  Color boxkd = box.get_material().m_kd;
  Color boxks = box.get_material().m_ks;
  float boxm = box.get_material().m_m;
  REQUIRE(boxka.r== 0);
  REQUIRE(boxka.g== 0);
  REQUIRE(boxka.b== 0);
  REQUIRE(boxkd.r== 0);
  REQUIRE(boxkd.g== 0);
  REQUIRE(boxkd.b== 0);
  REQUIRE(boxks.r== 0);
  REQUIRE(boxks.g== 0);
  REQUIRE(boxks.b== 0);
  REQUIRE(boxm== 0);
}
TEST_CASE("Default sphere constructor", "[get]")
{
  Sphere sphere;
  REQUIRE(sphere.get_center().x == 0);
  REQUIRE(sphere.get_center().y == 0);
  REQUIRE(sphere.get_center().z == 0);
  REQUIRE(sphere.get_radius() == 1);
  Color sphereka = sphere.get_material().m_ka;
  Color spherekd = sphere.get_material().m_kd;
  Color sphereks = sphere.get_material().m_ks;
  float spherem = sphere.get_material().m_m;
  REQUIRE(sphere.get_name() == "Default Shape");
  REQUIRE(sphere.get_material().m_name == "no_mat");

  REQUIRE(sphereka.r == 0);
  REQUIRE(sphereka.g == 0);
  REQUIRE(sphereka.b == 0);
  REQUIRE(spherekd.r == 0);
  REQUIRE(spherekd.g == 0);
  REQUIRE(spherekd.b == 0);
  REQUIRE(sphereks.r == 0);
  REQUIRE(sphereks.g == 0);
  REQUIRE(sphereks.b == 0);
}

TEST_CASE("User box constructor", "[get]")
{
Box box ("mybox",testmat,glm::vec3{1.0,1.0,1.0},glm::vec3{2.0,2.0,2.0});
  REQUIRE(box.get_min().x == 1);
  REQUIRE(box.get_min().y == 1);
  REQUIRE(box.get_min().z == 1);
  REQUIRE(box.get_max().x == 2);
  REQUIRE(box.get_max().y == 2);
  REQUIRE(box.get_max().z == 2);
  Color boxka = box.get_material().m_ka;
  Color boxkd = box.get_material().m_kd;
  Color boxks = box.get_material().m_ks;
  float boxm = box.get_material().m_m;
  REQUIRE(boxka.r== 0);
  REQUIRE(boxka.g== 0);
  REQUIRE(boxka.b== 0);
  REQUIRE(boxkd.r== 1);
  REQUIRE(boxkd.g== 1);
  REQUIRE(boxkd.b== 1);
  REQUIRE(boxks.r== 0.5);
  REQUIRE(boxks.g== 0.5);
  REQUIRE(boxks.b== 0.5);
  REQUIRE(boxm== 0.5);
  REQUIRE(box.get_material().m_name == "testmaterial");
}
TEST_CASE("User sphere constructor", "[get]")
{
Sphere sphere ("mysphere", testmat,glm::vec3{3.0,3.0,3.0},12.5);
  REQUIRE(sphere.get_center().x == 3);
  REQUIRE(sphere.get_center().y == 3);
  REQUIRE(sphere.get_center().z == 3);
  REQUIRE(sphere.get_radius() == 12.5);
  REQUIRE(sphere.get_name() == "mysphere");
  Color sphereka = sphere.get_material().m_ka;
  Color spherekd = sphere.get_material().m_kd;
  Color sphereks = sphere.get_material().m_ks;
  float spherem = sphere.get_material().m_m;
  REQUIRE(sphereka.r== 0);
  REQUIRE(sphereka.g== 0);
  REQUIRE(sphereka.b== 0);
  REQUIRE(spherekd.r== 1);
  REQUIRE(spherekd.g== 1);
  REQUIRE(spherekd.b== 1);
  REQUIRE(sphereks.r== 0.5);
  REQUIRE(sphereks.g== 0.5);
  REQUIRE(sphereks.b== 0.5);
  REQUIRE(spherem== 0.5);
  REQUIRE(sphere.get_material().m_name == "testmaterial");
}
TEST_CASE("box area and volume", "[boxformula]")
{
  Box box ("mybox",testmat,glm::vec3{2.0,2.0,2.0},glm::vec3{6.0,6.0,6.0});
  REQUIRE(box.volume() == 64.0);
  REQUIRE(box.area() == 96.0);
}
TEST_CASE("sphere area and volume", "[boxformula]")
{
Sphere sphere ("mysphere",testmat,glm::vec3{3.0,3.0,3.0},5);
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

//TEST_CASE("5.7,[staticdynamic]")
//{
//
//std::cout<< "5.7\n";
//std::cout<< "Static type checking means that type checking occurs at compile time."<< 
//"\n No type information is used at runtime in that case.\n ";
//
//std::cout<< "\n Dynamic type checking occurs when type information is used at runtime."<<
//"\n C++ uses a mechanism called RTTI (runtime type information) to implement this.";
//std::cout<< "\n source: https://stackoverflow.com/questions/1347691/static-vs-dynamic-type-checking-in-c\n ";
//
//Color red (255 , 0 , 0);
//glm::vec3 position (0,0,0);
//std::shared_ptr<Sphere> s1 =
//std::make_shared<Sphere>("sphere0",red,position,1.2);
//std::shared_ptr<Shape> s2 =
//std::make_shared<Sphere>("sphere1",red,position,1.2);
//s1->print(std::cout);
//s2->print((std::cout);
//}

TEST_CASE("intersectRaySphere", "[intersect]")
{
  
	glm::vec3 ray_origin{0.0, 0.0, 0.0};
	glm::vec3 ray_direction{0.0, 0.0, 1};
	Ray ray {ray_origin,ray_direction};
	Sphere sphere ("mysphere", testmat,glm::vec3{0.0,0.0,15.0},3.0);

	float distance=0.0;

	bool result=sphere.intersect(ray,distance);

	REQUIRE(result == true);
}
TEST_CASE("intersectRayBox", "[intersect]")
{
	Box box ("mybox",testmat,glm::vec3{0,0,0.5},glm::vec3{0.0,0.0,3.0});

	glm::vec3 ray_origin{0.0, 0.0, 0.0};
	glm::vec3 ray_direction{0.0, 0.0, 1};
	Ray ray {ray_origin,ray_direction};
	float distance =0.0;
	REQUIRE(box.intersect(ray, distance)==true);
}












int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}