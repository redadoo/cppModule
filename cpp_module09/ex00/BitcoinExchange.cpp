#include "BitcoinExchange.hpp"

std::multimap<std::string,
	float> BitcoinExchange::InitMultiMap(const std::string filename, char sep)
{
	float	value;

	std::string line;
	std::ifstream inputFile(filename.c_str());
	std::multimap<std::string, float> toFill;
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
				value = std::atof(line.substr(sepPos + 1).c_str());
				key = key.substr(0, key.size() - 1);
				toFill.insert(std::make_pair(key, value));
			}
			else
				toFill.insert(std::make_pair(line, -100));
		}
		inputFile.close();
	}
	else
	{
		std::cerr << "Failed to open the file." << std::endl;
	}
	return (toFill);
}

void BitcoinExchange::SearchExchangeValue()
{
	std::multimap<std::string, float>::iterator it;
	std::multimap<std::string, float>::iterator it1;
	for (it = fileValue.begin(); it != fileValue.end(); ++it)
	{
		for (it1 = database.begin(); it1 != database.end(); ++it1)
		{
			if (it1->first.compare(it->first) == 0)
			{
				std::cout << "wow\n";
			}
		}
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
    std::string tmp;
    this->year = std::atof(date.substr(0,date.find('-')).c_str());

}
