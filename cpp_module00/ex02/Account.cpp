/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:35:20 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/22 11:42:09 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::getTotalAmount(void)
{
    
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::makeDeposit(int deposit)
{
    this->_nbDeposits = deposit;
}
bool Account::makeWithdrawal(int withdrawal)
{
    return false;
}

Account::~Account(void)
{

}

int Account::getNbWithdrawals(void)
{
    return 0;
}

int Account::getNbDeposits(void)
{
    return 0;
}

void Account::displayAccountsInfos(void)
{

}

void Account::displayStatus(void) const
{
    
}

void Account::_displayTimestamp(void)
{
    
}
