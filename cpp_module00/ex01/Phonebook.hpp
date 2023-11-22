/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:23:53 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/22 10:30:23 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"


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