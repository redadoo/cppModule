#include "BitcoinExchange.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	if (argc != 2) return (1);
	BitcoinExchange exchange(argv[1]);
}
