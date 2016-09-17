#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "list.hpp"


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

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}