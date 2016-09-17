#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <algorithm>
#include <vector>

bool is_even (unsigned int number){
    return ((number % 2) == 0);
}

TEST_CASE ("describe_vector","[aufgabe5]")
{

	std::vector<unsigned int> v(100);
	std::generate (v.begin(), v.end(), [](){return std::rand()%100;});
	v.erase(std::remove_if(v.begin(), v.end(), [](unsigned int x){return x%2==1;}),v.end());


	REQUIRE(std::all_of(v.begin(), v.end(), [](unsigned int x){return x%2==0;}));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}