#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>   
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <limits>

struct Date
{
    int year;
    int month;
    int day;

    bool badData;
    
    Date(const std::string& date);
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
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

    void InitMultiMap(const std::string &filename, char sep, std::multimap<Date, float>& toFill);    
    void SearchExchangeValue(char *filename);

};

#endif