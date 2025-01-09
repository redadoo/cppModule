#include "PmergeMe.hpp"

const unsigned long long PmergeMe::jacobsthal_diff[] = {
	2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
	2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
	1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
	178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
	11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
	366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
	11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
	375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
	6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
	96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
	1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

PmergeMe::PmergeMe(char **args, int argc)
{
	FillContainers(args, argc);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::FillContainers(char **args, int argc)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string number(args[i]);
		std::istringstream tokenStream(number);
		std::string token;

		while (std::getline(tokenStream, token, ' '))
		{
			int n = StringToInt(token);
			this->vect.push_back(n);
			this->deq.push_back(n);
		}
	}
}

void PmergeMe::Sort()
{
	std::cout << "before: ";
	PrintVector();
	std::clock_t startVector2 = std::clock();
	SortVector();
	std::clock_t endVector2 = std::clock();
	double vectorTime2 = 1000000.0 * (endVector2 - startVector2) / CLOCKS_PER_SEC;
	std::cout << "after: ";
	PrintVector();
	std::cout << "Time taken by fordJohnson sort (std::vector): " << vectorTime2 << " microseconds\n\n\n";
}

void PmergeMe::SortVector()
{
	int pairSize = 1;
	int oddSize = 0;
	
	while (static_cast<size_t>(pairSize * 2) < vect.size())
	{
		oddSize = SortVectorPairs(pairSize);
		pairSize *= 2;
	}

	MergeInsertion(pairSize, oddSize);
}

void PmergeMe::PrintVector() const
{
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
}

int PmergeMe::SortVectorPairs(int pairSize)
{
	int dist = 0;
	
	typedef typename  std::vector<unsigned int> vector;

	for (vector::iterator it = vect.begin(); it != vect.end();)
	{
		vector::iterator secondPairStartIter = it;

		dist = std::distance(it, vect.end()); 
		if (dist < pairSize * 2)
			break;

		std::advance(secondPairStartIter, pairSize);

		IteratorGroup<vector> firstPair(it, pairSize - 1);;
		IteratorGroup<vector> secondPair(secondPairStartIter, pairSize - 1);
		
		if (firstPair > secondPair)
			IteratorGroup<vector>::SwapIteratorGroup(firstPair, secondPair);

		int moveIt = pairSize + pairSize; 
		dist = std::distance(it, vect.end()); 
		if (dist < moveIt)
			break;

		std::advance(it, moveIt);
	}
	return dist;
}

void PmergeMe::MergeInsertion(int pairSize, int oddSize)
{
	typedef typename  std::vector<unsigned int> vector;

	IteratorGroup<vector> remained(vect.begin() + ((vect.size()) - oddSize), oddSize - 1);
	IteratorGroup<vector> tmp(vect.begin(), (vect.size() - 1) - oddSize);
	pairSize /= 2;
	std::vector<unsigned int>tmp2;
	while (pairSize > 0)
	{
		std::vector<IteratorGroup<vector> > main;
		IteratorGroup<vector>::FillVectorOfGroup(
			tmp,
			main,
			pairSize
		);
		std::vector<IteratorGroup<vector> > pend;

		if (main.size() >= 2)
		{
			for (size_t i = 2; i < main.size(); i++)
			{
				if (i + 1 < main.size() && main[i] < main[i + 1])
				{
					pend.push_back(main[i]);
					main.erase(main.begin() + i);
				}
			}

			if (pend.size() == 1)
			{
				for (size_t i = 0; i < main.size(); i++)
				{
					if (main[i] > pend[0])
					{
						main.insert(main.begin() + i, pend[0]);
						break;
					}
				}
			}
			else if(pend.size() > 0)
			{
				int indexJacob = 0;

				while (pend.size() > 0)
				{
					if (indexJacob < 0 || indexJacob > 63)
						break;

					unsigned long long  index = jacobsthal_diff[indexJacob] - 1;

					for (size_t i = 0; i < main.size(); i++)
					{
						if (pend.size() == 0)
							break;

						if (index <= pend.size() && main[i] > pend[index])
						{
							if (pend.size() == 1)
							{
								main.insert(main.begin() + i, pend[0]);
								pend.erase(pend.begin());
							}
							else
							{
								main.insert(main.begin() + i, pend[index]);
								pend.erase(pend.begin() + index);
							}
							index--;
							i = -1;
						}
					}
					indexJacob++;
				}
			}

			if(static_cast<size_t>(pairSize) <= remained.size + 1)
			{
				IteratorGroup<vector> odd(remained.start, pairSize - 1);
				for (size_t i = 0; i < main.size(); i++)
				{
					if (main[i] > odd)
					{
						main.insert(main.begin() + i, odd);
						remained.start = remained.start + pairSize;
						remained.size = remained.size - pairSize;
						break;
					}
				}
			}
		}
		
		tmp2.clear();
		for (size_t i = 0; i < main.size(); i++)
			tmp2.insert(tmp2.end(), main[i].start, main[i].start + (main[i].size + 1));

		vect = tmp2;
		tmp.start = vect.begin();
		tmp.size = vect.size() - 1;
		pairSize /= 2;
	}

}

int PmergeMe::StringToInt(const std::string &str) const
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]))
			throw NotDigitFound();
	}

	int number;
	std::istringstream ss(str);
	ss >> number;

	if (ss.fail())
		throw std::runtime_error("Invalid string to convert to int");
	if (number < 0)
		throw FoundNegativeNumber();

	return number;
}
