/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:17 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/24 06:26:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
    this->amount = 0;
}

void	Phonebook::show_command(void)
{
    cout << "# PhoneBook" << endl;
	cout << "# Enter your command [HELP, ADD, SEARCH, EXIT]:" << endl;
}
void	Phonebook::add_contact(void)
{
    string list[5];

    if (this->amount > 7)
        return;
    else
    {
        for (size_t i = 0; i < 4; i++)
        {
            cout << "add fild\n";
            cin >> list[i];
        }
        this->contacts[this->amount].new_contact(list);
        this->amount++;
    }
}
void	Phonebook::search_contact(void)
{
    int x;

    cout << "index of contact\n";
    cin >> x; 
    if (x >= 0 && x <= 7)
        this->contacts[x].show_field();
}