#include "Base.hpp"

int main()
{
	std::srand(std::time(0));

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();
	Base *d = generate();
	Base *e = generate();

	identify(a);
	identify(b);
	identify(c);
	identify(d);
	identify(e);

	std::cout << "\n";
	
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);
	identify(*e);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;

}