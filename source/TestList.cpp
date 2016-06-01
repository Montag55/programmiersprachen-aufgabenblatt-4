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
	list.push_back(4);					
	list.pop_front();					
	REQUIRE(2 == list.front());
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

TEST_CASE("should be an empty range after default construction", "[iterators]"){
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b==e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]"){
	List<int> list;
	list.push_front(42);
	REQUIRE(42 == *list.begin());
}

TEST_CASE("Operation_Liste_==", "[4.6]"){
	List<int>list1;
	List<int>list2;
	List<int>list3;
	List<int>list4;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	list2.push_front(1);
	list2.push_front(2);
	list2.push_front(3);
	list2.push_front(4);
	REQUIRE(list2 == list1);
	REQUIRE(list3 == list4);
}

TEST_CASE("Operation_Liste_!=", "[4.6]"){
	List<int>list1;
	List<int>list2;
	List<int>list3;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(2);
	list1.push_front(4);
	list2.push_front(1);
	list2.push_front(2);
	list2.push_front(3);
	list2.push_front(4);
	REQUIRE(list2 != list1);
	REQUIRE(list3 != list1);
}

TEST_CASE("copy constructor", "[constructor]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2{list};
	REQUIRE(list == list2);
}

TEST_CASE("insert", "[operation]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.insert(++list.begin(), 6);
	
	REQUIRE(5 == list.size());
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#endif