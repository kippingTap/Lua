#pragma once


class Account
{
public:
	Account(float fund = 0);
	~Account();
	float getFound()const;
	bool deposit(float howMuch);
	bool withdrawal(float howMuch);

private:
	float m_fund;
};