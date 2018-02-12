#include"account.h"
#include<iostream>
Account::Account(float fund)
	:m_fund(fund)
{
	std::cout << "Account constructor~~" << std::endl;
}

Account::~Account()
{
	m_fund = 0;
	std::cout << "Account destructor~~" << std::endl;
}

float Account::getFound()const
{
	return m_fund;
}

bool Account::deposit(float howMuch)
{
	if (false)
		return false;
	m_fund += howMuch;
	return true;
}

bool Account::withdrawal(float howMuch)
{
	if (howMuch > m_fund)
	{
		std::cerr << "error: not enough money." << std::endl;
		return false;
	}
	m_fund -= howMuch;
	return true;
}