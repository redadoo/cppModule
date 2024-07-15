#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>   
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdlib.h>

struct Date
{
    int year;
    int month;
    int day;

    Date(std::string date);
    ~Date();
};


class BitcoinExchange
{
private:
    std::multimap<Date*, float> database;
    std::multimap<Date*, float> fileValue;

    void InitMultiMap(const std::string &filename, char sep, const std::multimap<Date*, float>& toFill);
    void ProcessData(char *filename);
    void SearchExchangeValue();

public:
    ~BitcoinExchange();
    BitcoinExchange(char *fileName);
};

#endif