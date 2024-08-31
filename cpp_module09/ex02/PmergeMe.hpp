#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
private:
    std::string         numbers;
    std::vector<int>    vec;
    std::list<int>      list;

    void FillContainers();
    void SetNumbersString(char **args, int argc);

public:
    PmergeMe(char **args, int argc);
    ~PmergeMe();
};

#endif