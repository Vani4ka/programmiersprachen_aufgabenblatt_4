#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <algorithm>
#include <vector>
#include "circle.hpp"
#include "vec2.hpp"

template<typename T>
void swap_circles(T& t1, T& t2) {
	T temp{t1};
	t1=t2;
	t2=temp;
};

TEST_CASE ("describe_circles","[aufgabe7]")
{
	std::vector<Circle> circles;
	circles.push_back({{10.0f,10.0f},5.0f});
	circles.push_back({{10.0f,10.0f},8.0f});
	circles.push_back({{10.0f,10.0f},2.0f});
	circles.push_back({{10.0f,10.0f},14.0f});
	circles.push_back({{10.0f,10.0f},9.0f});
	circles.push_back({{10.0f,10.0f},5.0f});

	std::sort(circles.begin(), circles.end());

	REQUIRE(std::is_sorted(circles.begin(),circles.end()));
}

TEST_CASE ("describe_swap", "[aufgabe8]")
{
	Circle c7{{10.0f,10.0f},5.0f};
	Circle c8{{16.0f,16.0f},8.0f};

	swap_circles(c7, c8);

	REQUIRE(c7.getRadius()==8.0f);
	REQUIRE(c8.getRadius()==5.0f);
}

TEST_CASE("describe_lambda","[aufgabe9]")
{
	std::vector<Circle> circles;
	circles.push_back({{10.0f,10.0f},5.0f});
	circles.push_back({{10.0f,10.0f},8.0f});
	circles.push_back({{10.0f,10.0f},2.0f});
	circles.push_back({{10.0f,10.0f},14.0f});
	circles.push_back({{10.0f,10.0f},9.0f});
	circles.push_back({{10.0f,10.0f},5.0f});

	std::sort(circles.begin(), circles.end(),[](Circle const& c1, Circle const& c2){return c1.getRadius()<c2.getRadius();});

	REQUIRE(std::is_sorted(circles.begin(),circles.end()));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}