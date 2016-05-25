#ifndef CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"



//4.1
TEST_CASE("Operation_Liste", "[Aufgabe_1]"){
	List<int> l;
	REQUIRE(l.empty()== true);
	REQUIRE(l.size() == 0);
}

//4.2
TEST_CASE("add an element with push_front", "[modifiers]"){
	List<int>list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	REQUIRE(4 == list.front());
	REQUIRE(1 == list.back());
}

TEST_CASE("add an element with push_back", "[modifiers]"){
	List<int>list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	REQUIRE(1 == list.front());
	REQUIRE(4 == list.back());
}

TEST_CASE("add an element with pop_front", "[modifiers]"){
	List<int>list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_front(4);					//ich brauch mindestens 1x pop_front,
	list.pop_front();					// sonst segmantation limit überschritten...why?
	REQUIRE(1 == list.front());
}

TEST_CASE("add an element with pop_back", "[modifiers]"){
	List<int>list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.pop_back();
	REQUIRE(3 == list.back());
}

TEST_CASE("should be empty after clearing", "[modifiers]"){
	List<int>list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.size()==0);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#endif