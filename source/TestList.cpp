#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "List.hpp"



//2.3
TEST_CASE("Operation_Plus", "[Summe]"){

	Vec2 v1;
	Vec2 v2{1.0f, 2.0f};
	Vec2 v3 = Vec2(0.5f,-5.0f);
	REQUIRE(v1.x == Approx(0.0f)); //Abfrage 
	REQUIRE(v1.y == Approx(0.0f)); //Abfrage
	REQUIRE(v2.x == Approx(1.0f)); //Abfrage
	REQUIRE(v2.y == Approx(2.0f)); //Abfrage
	v1+=v2;
	v3+=v2;
	REQUIRE(v1.x == Approx(1.0f)); 
	REQUIRE(v1.y == Approx(2.0f)); 
	REQUIRE(v3.x == Approx(1.5f));
	REQUIRE(v3.y == Approx(-3.0f));
}

TEST_CASE("Operation_Minus", "[Minus]"){
	Vec2 v1;
	Vec2 v2{1.0f, 2.0f};
	Vec2 v3 = Vec2(0.5f,5.0f);
	v1-=v2;
	v3-=v2;
	REQUIRE(v1.x == Approx(-1.0f));
	REQUIRE(v1.y == Approx(-2.0f));
	REQUIRE(v3.x == Approx(-0.5f));
	REQUIRE(v3.y == Approx(3.0f));
}

TEST_CASE("Operation_Multi", "[Multiplikation]"){

	Vec2 v1 = Vec2(2.0f,-1.0f);
	float v2 {1.0f};
	Vec2 v3 = Vec2(0.5f,0.0f);
	v1*=v2;
	v3*=v2;
	REQUIRE(v1.x == Approx(2.0f));
	REQUIRE(v1.y == Approx(-1.0f));
	REQUIRE(v3.x == Approx(0.5f));
	REQUIRE(v3.y == Approx(0.0f));
}

TEST_CASE("Operation_Div", "[Division]"){

	Vec2 v1 = Vec2(-2.0f, 3.0f);
	float v2 {1.0f};
	Vec2 v3 = Vec2(0.5f,0.0f);				
	v1/=v2;								//NULL GEHT NICHT!!!!
	v3/=v2;
	REQUIRE(v1.x == Approx(-2.0f));
	REQUIRE(v1.y == Approx(3.0f));
	REQUIRE(v3.x == Approx(0.5f));
	REQUIRE(v3.y == Approx(0.0f));
}

//2.4 
TEST_CASE("Operation_Addition", "[Addition]"){
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{1.0f, 2.0f};
	Vec2 v4{-1, 0};
	Vec2 v3 = v1+v2;
	Vec2 v5 = v1+v4;
	REQUIRE(v3.x == Approx(2.0f));
	REQUIRE(v3.y == Approx(4.0f));
	REQUIRE(v5.x == Approx(0.0f));
	REQUIRE(v5.y == Approx(2.0f));
}

TEST_CASE("Operation_Sub_2", "[Subtraction_2]"){
	Vec2 v1{1.0f, 2.0f};
	Vec2 v2{1.0f, 2.0f};
	Vec2 v4{-1, 0};
	Vec2 v3 = v1-v2;
	Vec2 v5 = v1-v4;
	REQUIRE(v3.x == Approx(0.0f));
	REQUIRE(v3.y == Approx(0.0f));
	REQUIRE(v5.x == Approx(2.0f));
	REQUIRE(v5.y == Approx(2.0f));
}

TEST_CASE("Operation_Multi_2", "[Multi_2]"){
	Vec2 v1{1.0f, 2.0f};
	float v2{1.0f};
	float v4{0};
	Vec2 v3 = v1*v2;
	Vec2 v5 = v1*v4;
	REQUIRE(v3.x == Approx(1.0f));
	REQUIRE(v3.y == Approx(2.0f));
	REQUIRE(v5.x == Approx(0.0f));
	REQUIRE(v5.y == Approx(0.0f));
}

TEST_CASE("Operation_Division", "[Division_2]"){
	Vec2 v1{1.0f, 2.0f};
	float v2{2.0f};
	Vec2 v3 = v1 / v2;
	REQUIRE(v3.x == Approx(0.5f));
	REQUIRE(v3.y == Approx(1.0f));
}

//2.5
TEST_CASE("Operation_Matrix_Mult", "[Matrix_Mult]"){
	Mat2 m1;
	Mat2 m2{1 ,1 ,1, 1};
	m1*=m2;
	REQUIRE(m1.x1 == Approx(1));
	REQUIRE(m1.x2 == Approx(1));
	REQUIRE(m1.x3 == Approx(1));
	REQUIRE(m1.x4 == Approx(1));
	
}

TEST_CASE("Operation_Matrix_Mult2", "[Matrix_Mult2]"){
	Mat2 m1{1, 1, 1, 1};
	Mat2 m2{1 ,1 ,1, 1};
	Mat2 m3 = m1*m2;
	REQUIRE(m3.x1 == Approx(2));
	REQUIRE(m3.x2 == Approx(2));
	REQUIRE(m3.x3 == Approx(2));
	REQUIRE(m3.x4 == Approx(2));
	
}

//2.6 Matrix Rotaion fehlt noch!
TEST_CASE("Operation_Matrix_Vec", "[Matrix_Vec]"){
	Mat2 m1;
	Vec2 v1{1 ,1};
	Vec2 v2 = m1*v1;
	REQUIRE(v2.x == Approx(1));
	REQUIRE(v2.y == Approx(1));
}

TEST_CASE("Operation_Inverse", "[Matrix_Iverse]"){
	Mat2 m2{1, 0, 1, 1};
	Mat2 m1 = inverse(m2);

	REQUIRE(m1.x1==Approx(1));
	REQUIRE(m1.x2==Approx(0));
	REQUIRE(m1.x3==Approx(-1));
	REQUIRE(m1.x4==Approx(1));
}

TEST_CASE("Operation_Trans", "[Matrix_Trans]"){
	Mat2 m2{1, 2, 3, 4};
	Mat2 m1 = transpose(m2);
	REQUIRE(m1.x1==Approx(1));
	REQUIRE(m1.x2==Approx(3));
	REQUIRE(m1.x3==Approx(2));
	REQUIRE(m1.x4==Approx(4));
}

TEST_CASE("Operation_Matrix_Rot", "[Matrix_Rot]"){
	Mat2 m1{1, 1, 1, 1};
	Vec2 v1(1, 1);
	Mat2 m_rot = make_rotation_mat2(M_PI);
	v1 = m_rot*v1;
	REQUIRE(v1.x == Approx(-1));
	REQUIRE(v1.y == Approx(-1));
}

//2.8
TEST_CASE("Operation_FLäche", "[Fläche]"){
	float b = Circle().area();
	REQUIRE(b==Approx(9*M_PI));
}

TEST_CASE("Operation_Knechteck1", "[Fläche_Knechteck]"){
	float b = Rectangle().area();
	REQUIRE(b == Approx(6));
}

TEST_CASE("Operation_Get_center", "[Get_Kreismitte]"){
	Vec2 v1{0,0};
	v1 = Circle(Vec2(1,1), 1, Color()).center();
	REQUIRE(v1.x == Approx(1));
	REQUIRE(v1.y == Approx(1));
}

TEST_CASE("Operation_Get_radius", "[Get_radius]"){
	float r{0};
	r = Circle(Vec2(1,1), 1, Color()).radius();
	REQUIRE(r == Approx(1));
}

TEST_CASE("Operation_Get_hight", "[Get_hight]"){
	float r{0};
	r = Rectangle( 1, 1, Color(), Vec2()).hight();
	REQUIRE(r == Approx(1));
}

TEST_CASE("Operation_Get_breite", "[Get_breite]"){
	float r{0};
	r = Rectangle( 1, 1, Color(), Vec2()).breite();
	REQUIRE(r == Approx(1));
}

TEST_CASE("Operation_Get_startpunkt", "[startpunkt]"){
	Vec2 r{0, 0};
	r = Rectangle( 1, 1, Color(), Vec2()).startpunkt();
	REQUIRE(r.x == Approx(0));
	REQUIRE(r.y == Approx(0));
}

//2.9
TEST_CASE("Operation_Umfang", "[Umfang]"){
	float b = Circle().circumference();
	REQUIRE(b == Approx(6*M_PI));
}

TEST_CASE("Operation_Knechteck2", "[Umfang_Knechteck]"){
	float b = Rectangle().circumference();
	REQUIRE(b == Approx(10));
}

//2.13
TEST_CASE("Operation_is_inside_kreis", "[inside_Kreis]"){
	REQUIRE(Circle(Vec2(1,1), 1, Color()).is_inside(Vec2(1,1)) == true );
	REQUIRE(Circle(Vec2(1,1), 1, Color()).is_inside(Vec2(3,3)) == false );
}
TEST_CASE("Operation_is_inside_knechteck", "[inside_Knechteck]"){
	REQUIRE(Rectangle(1, 1, Color(), Vec2()).is_inside(Vec2(1,1)) == true );
	REQUIRE(Rectangle(1, 1, Color(), Vec2()).is_inside(Vec2(3,3)) == false );
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#endif