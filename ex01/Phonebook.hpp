/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:23:53 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/24 06:15:09 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

using namespace std;

class Phonebook
{
	private:
	    Contact	contacts[8];
		int amount;
    public:
		Phonebook();
		void	show_command(void);
		void	add_contact(void);
		void	search_contact(void);

};

#endif