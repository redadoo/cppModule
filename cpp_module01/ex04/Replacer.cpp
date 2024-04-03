/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:08 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

bool file_exists (const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

void Replacer::replaceContent()
{	
	std::string newFile = filename + ".replace";
  	std::ifstream inputFile(this->filename.c_str());
	
  	std::ofstream outputFile(newFile.c_str());

	if (inputFile.is_open() && outputFile.is_open()) 
	{
			std::string line; 
			while (std::getline(inputFile, line)) 
			{
				size_t	posS2 = line.find(s1);
				if(posS2 != std::string::npos)
				{
					line.erase(posS2,s1.length());
					line.insert(posS2,s2);
				}
				outputFile << line << "\n"; 
			}
			inputFile.close();
			outputFile.close();
	}
	else {
		std::cerr << "Failed to open the files." << std::endl;  
	}
} 


Replacer::Replacer(std::string _filename,std::string _s1,std::string _s2) : filename(_filename), s1(_s1), s2(_s2)
{
	if(file_exists(filename) && s1 != "" && s2 != "")
		replaceContent();
	else
		std::cerr << "error on opening file check filename \n";
}