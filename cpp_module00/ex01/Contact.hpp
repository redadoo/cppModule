/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:31:13 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/24 06:41:02 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <iomanip>

using namespace std;

class Contact
{
	private:
		string first_name;
		string last_name;
		string nickname;
		string number;
		string darkes_secret;
	
	public:
		Contact();
		void new_contact(string list[5]);
		void show_field(void);
		bool is_empty(void);
		void print_search(void);
};

#endif