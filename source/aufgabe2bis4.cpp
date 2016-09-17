#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <set>
#include <map>

bool contains(unsigned int n, std::list<unsigned int> l) {
	for (auto i = l.begin(); i != l.end(); ++i) {
		if (*i==n)
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	std::list<unsigned int> l;
	for(int i=0; i<=100; ++i) {
		l.push_back(std::rand()%100);
	}

	std::vector<unsigned int> v(l.size());
	std::copy(l.begin(), l.end(), v.begin());

	std::cout<<"v: "<<std::endl;
	for(auto i=v.begin(); i!=v.end(); ++i){
		std::cout<<*i<<std::endl;
	}

	std::cout<<"l: "<<std::endl;
	for(auto i=l.begin(); i!=l.end(); ++i){
		std::cout<<*i<<std::endl;
	}

	std::cout<<"Aufgabe 3: alle Zahlen, die nicht in der Liste sind:"<<std::endl;

	std::vector<unsigned int> nums;
	for (int i = 0; i <=100; ++i) {
		nums.push_back(i);
	}


	for (int i = 0; i < nums.size(); ++i)
	{
		if (!contains(nums[i], l))
		{

			std::cout<<nums[i]<<std::endl;
		}
	}

	std::map<unsigned int, int> frequency;
	std::pair<unsigned int, int> pair;
	int freq = 1;


	for(auto it=l.begin(); it!=l.end(); ++it) {

		if(frequency.find(*it)==frequency.end()) {
			frequency.insert(std::pair<unsigned int, int>(*it, freq));
		}
		else {
			auto i=frequency.find(*it);
			i->second+=1;
		}
	}

	std::cout<<"Number"<<" : "<<"Frequency"<<std::endl;

	for (auto const& num : frequency)
	{
		std::cout<<num.first<<"  :  "<<num.second<<std::endl;
	}

	return 0;
}

