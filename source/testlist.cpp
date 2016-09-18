#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "list.hpp"

#include <vector>
#include <algorithm>

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

TEST_CASE("List != und ==", "[iterators]")
{
	List<int> l1;
	List<int> l2;
	List<int> l3;

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);

	l3.push_back(1);
	l3.push_back(3);
	l3.push_back(5);
	l3.push_back(11);

	REQUIRE(l1==l2);
	REQUIRE(l1!=l3);
}

TEST_CASE ( " copy constructor " , " [ constructor ] " )
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2{list};
	REQUIRE(list == list2);
}

// TEST_CASE("insert", "[insert]")
// {
// 	List<int> l1;
// 	l1.push_back(1);
// 	l1.push_back(2);
// 	l1.push_back(3);
// 	l1.push_back(4);
// 	l1.insert(l1.end(), 10);
// 	std::cout<<l1.size()<<std::endl;

// 	REQUIRE(l1.size()==5);
// }

// TEST_CASE("reverse", "[reverse]")
// {
// 	List<int> list;
// 	list.push_front(1);
// 	list.push_front(2);
// 	list.push_front(3);
// 	list.push_front(4);
// 	// for(auto i=list.begin(); i!=list.end(); ++i) {
// 	// 	std::cout<<*i<<std::endl;
// 	// }
// 	list.reverse();
// 	// for(auto i=list.begin(); i!=list.end(); ++i) {
// 	// 	std::cout<<*i<<std::endl;
// 	// }
// }


TEST_CASE ( " move constructor " , " [ constructor ] " )
{
	List <int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2(std::move(list));
	REQUIRE (0 == list.size());
	REQUIRE (list.empty());
	REQUIRE (4 == list2.size());
}

// TEST_CASE("copy in vector", "[vector]")
// {
// 	std::vector<int> v;
// 	List <int> list;
// 	list.push_front(1);
// 	list.push_front(2);
// 	list.push_front(3);
// 	list.push_front(4);
// 	std::cout<<"here"<<std::endl;
// 	std::copy(list.begin(), list.end(), v.begin());
// 	std::cout<<"there"<<std::endl;
// 	for(auto i=v.begin(); i!=v.end(); ++i) {
// 		std::cout<<*i<<std::endl;
// 	}
// 	REQUIRE(v.size()==4);
// }


int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}