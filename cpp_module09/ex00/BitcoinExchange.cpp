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

	std::string valueStr = line.substr(sepPos + 1);

	valueStr.erase(0, valueStr.find_first_not_of(" \t"));
	valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

	float value = 0.0;
	std::stringstream ss(valueStr);
	ss >> value;

	if (ss.fail() || !ss.eof())
	{
		std::cout << "Error: invalid float value." << std::endl;
		return;
	}

	try
	{
		if (value < 0)
		{
			throw std::runtime_error("Error: not a positive number.");
		}
		else if (value > 1000)
		{
			throw std::runtime_error("Error: too large a number.");
		}
		else
		{
			std::multimap<Date, float>::iterator it = database.lower_bound(date);
			if (it == database.end() || it->first > date)
			{
				if (it != database.begin())
					--it;
			}

			if (date.badData)
				std::cout << "Error: bad Date format" << std::endl;
			else
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
	}
	catch (const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Date::Date(const std::string &date)
{
	std::stringstream ss(date);
	std::string item;
	std::getline(ss, item, '-');
	year = std::atoi(item.c_str());
	std ::getline(ss, item, '-');
	month = std::atoi(item.c_str());
	std::getline(ss, item, '-');
	day = std::atoi(item.c_str());

	this->badData = !IsValidDate();
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

bool Date::IsValidDate()
{
	if (month < 1 || month > 12) 
		return false; 
	if (day < 1 || day > 31) 
		return false; 

	if (month == 2) 
	{ 
		if (IsLeap()) 
			return (day <= 29); 
		else 
			return (day <= 28); 
	} 

	if (month == 4 || month == 6 || 
		month == 9 || month == 11) 
		return (day <= 30);

	return true;
}

bool Date::IsLeap()
{
	return (((year % 4 == 0)   &&  
		 	(year % 100 != 0)) || 
		 	(year % 400 == 0)); 
}
