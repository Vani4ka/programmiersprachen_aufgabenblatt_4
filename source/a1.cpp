#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<int> v0(10);
	std::cout<<"size"<<v0.size()<<std::endl;

	for(std::vector<int>::iterator it=v0.begin(); it!= v0.end(); ++it) {
		*it = std::rand();
	}

	std::cout<<"v0 \n"<<std::endl;
	std::copy(std::begin(v0), std::end(v0), std::ostream_iterator<int>(std::cout, "\n"));

	std::list<int> l0(v0.size());
	std::copy(std::begin(v0), std::end(v0), std::begin(l0));

	std::list<int> l1(std::begin(l0), std::end(l0));
	std::reverse(std::begin(l1), std::end(l1));
	std::cout<<"l1 \n"<<std::endl;
	std::copy(std::begin(l1), std::end(l1), std::ostream_iterator<int>(std::cout, "\n"));

	l1.sort();
	std::cout<<"l1 sorted \n"<<std::endl;
	std::copy(l1.begin(), l1.end(),	std::ostream_iterator <int>( std::cout, "\n" ));
	std::generate( std::begin(v0), std::end(v0), std::rand);
	std::cout<<"generated new v0 \n"<<std::endl;
	std::copy(v0.rbegin(),v0.rend(), std::ostream_iterator<int>(std::cout, "\n "));

	return 0;
}