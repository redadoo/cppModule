#include "BitcoinExchange.hpp"
#include <climits>

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->database = other.database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->database = other.database;
    return *this;
}

BitcoinExchange::BitcoinExchange(char *filename)
{
	InitMultiMap();
	SearchExchangeValue(filename);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::InitMultiMap()
{
	std::ifstream inputFile(DATABASE_FILENAME);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == START_LINE_DATABASE)
			continue ;

		std::string::size_type sepPos = line.find(DATABASE_SEPARATOR);
		if (sepPos != std::string::npos)
		{
			std::string key = line.substr(0, sepPos);
			Date date(key);
			float value = std::atof(line.substr(sepPos + 1).c_str());
			database.insert(std::make_pair(date, value));
		}
		else
		{
			Date date(line);
			date.badData = true;
			database.insert(std::make_pair(date, 0));
		}
	}
	inputFile.close();
}

void BitcoinExchange::SearchExchangeValue(const char *filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line == START_LINE_INPUT)
			continue ;

		size_t sepPos = line.find('|');
		if (sepPos != std::string::npos)
			GetExchange(line, sepPos);
		else
			std::cout << "Error: bad input => " << line << "\n";
	}
}

void BitcoinExchange::GetExchange(const std::string& line , const size_t sepPos)
{
	std::string key = line.substr(0, sepPos);
	Date date(key);

	float value = std::atof(line.substr(sepPos + 1).c_str());

	if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
	{
		std::multimap<Date, float>::iterator it;

		for (it = database.begin(); it != database.end(); it++)
		{
			if (it->first > date)
				break;
		}
		
		if (it != database.begin())
			it--;
		
		if (date.badData == true)
			std::cout << "bad Date format" << std::endl;
		else
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
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
