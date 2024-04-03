/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:11 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:11 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char**argv)
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (argc == 4)
	{
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		Replacer replacer(filename,s1,s2);
	}
	else
		std::cout << "bad argument number" << std::endl;
}
