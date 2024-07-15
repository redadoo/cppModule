#include "BitcoinExchange.hpp"

void BitcoinExchange::InitMultiMap(const std::string &filename, char sep, const std::multimap<Date*, float>& toFill)
{
	float	value;
	std::string line;
	std::ifstream inputFile(filename.c_str());
	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			if (line == "date,exchange_rate" || line == "date | value")
				continue ;

			std::string::size_type sepPos = line.find(sep);
			
			if (sepPos != std::string::npos)
			{
				std::string key = line.substr(0, sepPos);
				value = std::atof(line.substr(sepPos + 2).c_str());
				key = key.substr(0, key.size() - 1);
				Date *test = new Date(key);
				toFill.insert(std::make_pair(test, value));
			}
			else
			{
				Date *test = new Date(line);
				toFill->insert(std::make_pair(test, -100));
			}
		}
		inputFile.close();
	}
	else
	{
		std::cerr << "Failed to open the file." << std::endl;
	}
}

void BitcoinExchange::SearchExchangeValue()
{
	// std::multimap<std::string, float>::iterator it;
	// std::multimap<std::string, float>::iterator it1;
	// for (it = fileValue.begin(); it != fileValue.end(); ++it)
	// {
	// 	for (it1 = database.begin(); it1 != database.end(); ++it1)
	// 	{
	// 		// if (it1->first.compare(it->first) == 0)
	// 		// {
	// 		// 	std::cout << "wow\n";
	// 		// }
	// 	}
	// }
}

void printData(std::multimap<std::string,float> test)
{
	std::multimap<std::string, float>::iterator it;

	for (it = test.begin(); it != test.end(); ++it)
	{
		std::cout << it->first << "  "  << it->second << "\n";
	}
}

BitcoinExchange::BitcoinExchange(char *filename)
{
	database = InitMultiMap("data.csv", ',');
	fileValue = InitMultiMap(filename, '|');
	SearchExchangeValue();
}

BitcoinExchange::~BitcoinExchange()
{

}

Date::Date(std::string date)
{
    this->year = std::atoi(date.substr(0, date.find_first_of('-')).c_str());
	date.erase(date.begin(), date.begin() + date.find_first_of('-') + 1);
	this->month = std::atoi(date.substr(0, date.find_first_of('-')).c_str());
	date.erase(date.begin(), date.begin() + date.find_first_of('-') + 1);
	this->day = std::atoi(date.substr(0, date.find_first_of('-')).c_str());
}
