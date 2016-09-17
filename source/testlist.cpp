#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "list.hpp"


TEST_CASE ("describe_list", "[aufgabe1]")
{
	List<int> l{};

	REQUIRE(l.size()==0);
	REQUIRE(l.empty()==true);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}