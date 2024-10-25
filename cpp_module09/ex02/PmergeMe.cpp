#include "PmergeMe.hpp"

int PmergeMe::StringToInt(const std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) == 0)
			throw NotDigitFound();
	}
	
	std::stringstream ss(str);
	int number;
	ss >> number;
	if (ss.fail())
		throw std::runtime_error("Invalid string to convert to int");
	if (number < 0)
		throw FoundNegativeNumber();
		
	return number;
}

void PmergeMe::PrintNumbers()
{
	std::vector< int>::iterator it1;
	for (it1 = vec.begin(); it1 != vec.end(); ++it1)
		std::cout << *it1 << " ";
	std::cout << std::endl;	
}


void PmergeMe::MergeInsertionSort(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<int> larger, smaller;

	for (std::size_t i = 0; i < arr.size() / 2; ++i)
	{
		if (arr[2 * i] > arr[2 * i + 1])
		{
			larger.push_back(arr[2 * i]);
			smaller.push_back(arr[2 * i + 1]);
		}
		else
		{
			larger.push_back(arr[2 * i + 1]);
			smaller.push_back(arr[2 * i]);
		}
	}

	if (arr.size() % 2 == 1) {
		smaller.push_back(arr.back());
	}

	MergeInsertionSort(larger);

	arr.clear();
	arr.push_back(smaller[0]);
	arr.insert(arr.end(), larger.begin(), larger.end());

	for (std::size_t i = 1; i < smaller.size(); ++i)
	{
		int pos = std::lower_bound(arr.begin(), arr.end(), smaller[i]) - arr.begin();
		arr.insert(arr.begin() + pos, smaller[i]);
	}
}

void PmergeMe::MergeInsertionSort(std::list<int> &list)
{
	if (list.size() <= 1)
        return;

    std::list<int> larger, smaller;
    std::list<int>::iterator it = list.begin();

    while (it != list.end())
    {
        int first = *it++;
        if (it == list.end())
        {
            smaller.push_back(first);
            break;
        }
        int second = *it++;

        if (first > second)
        {
            larger.push_back(first);
            smaller.push_back(second);
        }
        else
        {
            larger.push_back(second);
            smaller.push_back(first);
        }
    }

    MergeInsertionSort(larger);

    list.clear();
    list.push_back(smaller.front());
    list.insert(list.end(), larger.begin(), larger.end());

    std::list<int>::iterator smaller_it = ++smaller.begin();
    for (; smaller_it != smaller.end(); ++smaller_it)
    {
        std::list<int>::iterator pos = std::find_if(list.begin(), list.end(), 
                        [smaller_it](int x) { return *smaller_it < x; });
        list.insert(pos, *smaller_it);
    }
}

void PmergeMe::Sort()
{
	double time;

	std::cout << "numbers pre sort : ";
	PrintNumbers();

	clock_t start = clock();
	MergeInsertionSort(vec);
	clock_t end = clock();
	
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->vec.size() << " elements with std::vector is : " << time << " s" << std::endl;

	start = clock();
	MergeInsertionSort(list);
	end = clock();
	
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->list.size() << " elements with std::list is : " << time << " s" << std::endl;
}

void PmergeMe::FillContainers(char **args, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		std::string number(args[i]);
		if (number.find(" ") != std::string::npos)
		{
			std::istringstream tokenStream(number);
			std::string token;
			while (std::getline(tokenStream, token, ' '))
			{
				int n = StringToInt(token);
				vec.push_back(n);
				list.push_back(n);
			}
		}
		else
		{
			int n = StringToInt(number);
			vec.push_back(n);
			list.push_back(n);
		}
	}
}

PmergeMe::PmergeMe(char **args, int argc)
{
	FillContainers(args, argc);
	Sort();
}

PmergeMe::~PmergeMe() {}
