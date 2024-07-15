#include "Base.hpp"
#include "AS.hpp"

int GetRandomInt(int low_dist, int high_dist)
{
  	std::srand( ( unsigned int )std::time( NULL ) );
    return low_dist + std::rand() % ( high_dist - low_dist );
}
Base *generate()
{
    AS *a = new AS();

    return dynamic_cast<Base *>(a);
}
