/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:16:29 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/24 06:26:38 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Phonebook.hpp"

using namespace std;

int main(void)
{
    string str = "NULL";
    Phonebook phoneBook;

    while (str != "EXIT")
    {
        phoneBook.show_command();
        cin >> str;
        if (str == "ADD")
            phoneBook.add_contact();
        if (str == "SEARCH")
            phoneBook.search_contact();
    }
    
}
