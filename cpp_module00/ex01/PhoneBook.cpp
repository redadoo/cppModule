/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:21:22 by edoardo           #+#    #+#             */
/*   Updated: 2024/03/31 14:27:25 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() {}

void PhoneBook::Add(Contact contact)
{
	for (size_t i = 0; i < 8; i++)
	{
		if (this->contacts[i].isEmpty())
		{
			this->contacts[i] = contact;
			return ;
		}
	}
	this->contacts[7] = contact;
}

void PhoneBook::Search(std::string number)
{
	int					index;
	std::stringstream	ss; 

	ss << number;
	ss >> index;
	if (index < 0 || index > 7)
	{
		std::cout << "error index out of range " << std::endl;
		return ;
	}
	this->contacts[index].displayField(index);
}
