/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:48:09 by edoardo           #+#    #+#             */
/*   Updated: 2023/07/28 12:00:55 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

static char* StringToUpeer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;;
    }
    return (str);
}

int main(int argc, char **argv) 
{
    int i;

    i = 1;
    if (argc == 1)
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        while (argv[i] != NULL)
        {
            std::string str(StringToUpeer(argv[i]));
            std::cout << str;
            i++;
        }
        std::cout <<"\n";
    }
    return 0;
}