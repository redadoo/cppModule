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
    std::multimap<std::string, float> database;
    std::multimap<std::string, float> fileValue;

    std::multimap<std::string, float> InitMultiMap(std::string filename, char sep);
    void ProcessData(char *filename);
    void SearchExchangeValue();
public:
    ~BitcoinExchange();
    BitcoinExchange(char *fileName);
};

#endif