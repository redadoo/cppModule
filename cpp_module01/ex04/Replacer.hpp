#include <string>
#include <iostream>   
#include <fstream>   
#include <string>  

#ifndef REPLACER_H
#define REPLACER_H

class Replacer
{
	private:
 		std::string filename;
		std::string s1;
		std::string s2;   

	public:
		void replaceContent(); 
		Replacer(std::string _filename,std::string _s1,std::string _s2 );
};

#endif