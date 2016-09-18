#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "list.hpp"

#include <list>


TEST_CASE ("describe_list", "[aufgabe1]")
{
	List<int> l{};

	REQUIRE(l.size()==0);
	REQUIRE(l.empty()==true);
}

TEST_CASE ("addanelementwithpush_front", "[modifiers]")
{
List<int> list;
list.push_front(42);
REQUIRE(42==list.front());
}

TEST_CASE ("addanelementwithpush_back", "[modifiers]")
{
List<int> list;
list.push_back(23);
REQUIRE(23==list.back());
}

TEST_CASE ("addanelementwithpop_front", "[modifiers]")
{
List<int> list;
list.push_back(42);
list.push_back(23);
list.pop_front();
REQUIRE(23==list.front());
}

TEST_CASE ("addanelementwithpop_back", "[modifiers]")
{
List<int> list;
list.push_back(42);
list.push_back(23);
list.pop_back();
REQUIRE(42==list.back());
}

TEST_CASE("should be empty after clearing ", "[modifiers]")
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty());
}

TEST_CASE( " should be an empty range after default construction " , " [ iterators ] " )
{
	List<int> list;
	auto b= list.begin();
	auto e= list.end();
	REQUIRE( b==e );
}

TEST_CASE( " provide acces to the first element with begin " , " [ iterators ] " )
{
	List<int> list;
	list.push_front(42);

	REQUIRE(42== *list.begin());
}

TEST_CASE( " test operator ++ " , " [ iterators ] " )
{
	
	List<int> list;
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	int j=1;
	for(auto i=list.begin(); i!=list.end(); ++i) {
		REQUIRE(*i== j);
		j++;
	}
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}