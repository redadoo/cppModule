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

void binaryInsertion(std::vector<int> &main_chain, int element) {
    int low = 0, high = main_chain.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (main_chain[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    main_chain.insert(main_chain.begin() + low, element);
}

void PmergeMe::MergeInsertionSort(std::vector<int> &arr)
{
	   // Base case
    if (arr.size() <= 1) return;

    // Step 1: Pairing and initial sorting
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> remaining;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    if (arr.size() % 2 != 0) {
        remaining.push_back(arr.back());
    }

    // Step 2: Recursive sorting of main chain
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].second);
    }
    MergeInsertionSort(main_chain);

    // Step 3: Insert smaller elements in an optimal order
    static const int insertion_order[] = {1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6};
    std::vector<int> smaller_elements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smaller_elements.push_back(pairs[i].first);
    }
    if (!remaining.empty()) {
        smaller_elements.push_back(remaining[0]);
    }

    for (size_t i = 0; i < smaller_elements.size(); ++i) {
        binaryInsertion(main_chain, smaller_elements[insertion_order[i] - 1]);
    }

    // Step 4: Copy the sorted main chain back to the original array
    arr = main_chain;
}

void PmergeMe::MergeInsertionSort(std::list<int> &list)
{
	(void)list;
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
	std::cout << std::fixed << std::setprecision(10) << "Time to process a range of " << this->vec.size() << " elements with std::vector: " << time << " s" << std::endl;
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
}

PmergeMe::~PmergeMe() {}
