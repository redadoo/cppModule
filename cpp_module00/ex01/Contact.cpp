/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:20 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/28 12:00:58 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static string Replace(string str)
{
    string s;
    int i = 0;
    if (str.length() < 10)
        return str;
    while (i < 8)
    {
        s += (str.at(i));
        i++;
    }
    s.append(".");
    return s;
}

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->number = "";
    this->darkes_secret = "";
}

void Contact::new_contact(string list[5])
{
    this->first_name = list[0];
    this->last_name = list[1];
    this->nickname = list[2];
    this->number = list[3];
    this->darkes_secret = list[4];
}

void Contact::show_field(void)
{
    cout << this->first_name << endl;
    cout << this->last_name << endl;
    cout << this->nickname << endl;
    cout << this->darkes_secret << endl;
}
bool Contact::is_empty(void)
{
    if (this->first_name == "")
        return (true);
    return (false);
}


static string add_space(string str)
{
    while (str.length() < 9)
    {
        str.append(" ");
    }
    return str;
}

void Contact::print_search(void)
{
    string value;

    value = this->first_name;
    value = add_space(value);
    value = Replace(value);
    cout << value  << "|";
    value = this->last_name;
    value = add_space(value);
    value = Replace(value);
    cout <<  value << "|";
    value = this->nickname;
    value = add_space(value);
    value = Replace(value);
    cout <<  value << "|";
}
