#include "BitcoinExchange.hpp"
#include <climits>

void BitcoinExchange::InitMultiMap(const std::string &filename, char sep,
	std::multimap<Date, float> &toFill)
{
	float	value;

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == "date,exchange_rate" || line == "date | value")
			continue ;
		std::string::size_type sepPos = line.find(sep);
		if (sepPos != std::string::npos)
		{
			std::string key = line.substr(0, sepPos);
			value = std::atof(line.substr(sepPos + 1).c_str());
			Date date(key);
			toFill.insert(std::make_pair(date, value));
		}
		else
		{
			Date date(line);
			date.badData = true;
			toFill.insert(std::make_pair(date, 0));
		}
	}
	inputFile.close();
}

void	printData(std::multimap<Date, float> test)
{
	std::multimap<Date, float>::iterator it;
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << it->first << "  " << it->second << "\n";
}

void BitcoinExchange::SearchExchangeValue(char *filename)
{
	float	value;

	std::multimap<Date, float>::iterator databaseIterator;
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == "date,exchange_rate" || line == "date | value")
			continue ;
		std::string::size_type sepPos = line.find('|');
		if (sepPos != std::string::npos)
		{
			std::string key = line.substr(0, sepPos);
			value = std::atof(line.substr(sepPos + 1).c_str());
			Date date(key);
			databaseIterator = database.begin();
			while (databaseIterator != database.end())
			{
				if (databaseIterator->first > date)
					break ;
				++databaseIterator;
			}
			if (databaseIterator != database.begin())
				databaseIterator--;
			if (value < 0)
			{
				std::cout << "Error: not a positive number."
							<< "\n";
			}
			else if (value > 1000)
			{
				std::cout << "Error: too large a number."
							<< "\n";
			}
			else
			{
				std::cout << date << " => " << value << " = " << value
					* databaseIterator->second << "\n";
			}
		}
		else
		{
			std::cout << "Error: bad input => " << line << "\n";
		}
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(char *filename)
{
	InitMultiMap("data.csv", ',', database);
	SearchExchangeValue(filename);
}

Date::Date(const std::string &date)
{
	std::stringstream ss(date);
	std::string item;
	std::getline(ss, item, '-');
	year = std::atoi(item.c_str());
	std::getline(ss, item, '-');
	month = std::atoi(item.c_str());
	std::getline(ss, item, '-');
	day = std::atoi(item.c_str());
	this->badData = false;
}

std::ostream &operator<<(std::ostream &o, Date const &i)
{
	o << i.year << "-" << i.month << "-" << i.day;
	return (o);
}

bool Date::operator<(const Date &other) const
{
	if (year < other.year)
		return (true);
	if (year > other.year)
		return (false);
	if (month < other.month)
		return (true);
	if (month > other.month)
		return (false);
	return (day < other.day);
}

bool Date::operator>(const Date &other) const
{
	return (other < *this);
}
