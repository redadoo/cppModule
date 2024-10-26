#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> 	mstack;
	std::list<int> 		list;

	mstack.push(2135);
	mstack.push(17454);
	list.push_back(2135);
	list.push_back(17454);

	std::cout << "list.back(): " << list.back() << std::endl;
	list.pop_back();
	std::cout << "list.size(): " << list.size() << std::endl;
	

	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	

	list.push_back(39);
	list.push_back(45);
	list.push_back(5737);
	list.push_back(760);


	mstack.push(39);
	mstack.push(45);
	mstack.push(5737);
	mstack.push(760);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int>::iterator it_list = list.begin();
	std::list<int>::iterator ite_list = list.end();
	
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << "list iterator value :" << *it_list << std::endl;
		++it_list;
	}

	++it;
	--it;
	while (it != ite)
	{
		std::cout << "mutant stack iterator value :" << *it << std::endl;
		++it;
	}

	return 0;
}

