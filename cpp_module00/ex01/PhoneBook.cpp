/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:21:22 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/20 13:05:19 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

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

void PhoneBook::Search(int index)
{
	if (index < 0 || index > 7)
	{
		std::cout << "error index out of range " << std::endl;
		return ;
	}
	this->contacts[index].displayField(index);
}
