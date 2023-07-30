/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:17 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/26 23:37:49 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

static string add_space(string str)
{
    while (str.length() < 7)
    {
        str.append(" ");
    }
    return str;
}

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

    x = 0;
    string str;
    cout << "============================================\n";
    cout << "| index |" "firstname|" "lastname |" "nickname |"  << endl;
    while (this->contacts[x].is_empty() != true)
    {
        str = to_string(x);
        str = add_space(str);
        cout << "|" << str << "|";
        this->contacts[x].print_search();
        x++;
        cout << endl;
    }
    cout << endl;
}