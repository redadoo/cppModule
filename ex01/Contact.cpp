/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:40:20 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/24 06:27:29 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
