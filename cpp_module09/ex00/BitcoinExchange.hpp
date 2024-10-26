#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>   
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <limits>

#define START_LINE_INPUT "date | value"
#define START_LINE_DATABASE "date,exchange_rate"
#define DATABASE_FILENAME "data.csv"
#define DATABASE_SEPARATOR ','

struct Date
{
    int year;
    int month;
    int day;

    bool badData;
    
    Date(const std::string& date);
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    bool IsValidDate();
    bool IsLeap();
};

std::ostream & operator<<( std::ostream & o, Date const & i );


class BitcoinExchange
{
public:
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    BitcoinExchange(char *fileName);

private:
    std::multimap<Date, float> database;

    void InitMultiMap();    
    void SearchExchangeValue(const char *filename);
    void GetExchange(const std::string& line, const size_t sepPos);

};

#endif