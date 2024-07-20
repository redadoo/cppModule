#include "Base.hpp"

int GetRandomInt(int low_dist, int high_dist)
{
    return low_dist + std::rand() % ((high_dist + 1) - low_dist);
}

Base *generate()
{
	int random = GetRandomInt(1,4);
	if (random == 3)
		return new A;
	else if(random == 2)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if(dynamic_cast<B*>(p))
		std::cout << "B\n";
	else
		std::cout << "C\n";
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}
