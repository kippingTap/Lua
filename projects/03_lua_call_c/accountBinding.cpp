#include"accountBinding.h"
#include"account.h"
#include<memory>

int new_account(lua_State* L)
{
	float fund = -1;
	bool argVail = false;
	fund = luaL_optnumber(L, 1, -1);
	if (fund == -1)
	{
		fund = 0;
		argVail = true;
	}
	
	if (lua_isnumber(L, 1))
	{
		fund = lua_tonumber(L, 1);
		argVail = true;
	}
	luaL_argcheck(L, argVail, 1, "invalid arg, number expected.");
	
	void* p = lua_newuserdata(L, sizeof(Account));
	Account* paccount = new (p) Account(fund);
	return 1;
}


int del_account(lua_State* L)
{
	Account* paccount = (Account*)lua_touserdata(L, 1);
	luaL_argcheck(L, paccount != nullptr, 1, "invaild arg, Account expectd.");
	paccount->~Account();
	return 0;
}


int accout_getFund(lua_State* L)
{
	Account* paccount = (Account*)lua_touserdata(L, 1);
	luaL_argcheck(L, paccount != nullptr, 1, "invaild arg, Account expectd.");
	lua_pushnumber(L, paccount->getFound());
	return 1;
}


int accout_deposit(lua_State* L)
{
	Account* paccount = (Account*)lua_touserdata(L, 1);
	float howMuch = lua_tonumber(L, 2);
	luaL_argcheck(L, paccount != nullptr, 1, "invaild arg, Account expectd.");
	luaL_checknumber(L, 2);

	bool success = paccount->deposit(howMuch);
	lua_pushboolean(L, success);
	return 1;
}


int accout_withdrawal(lua_State* L)
{
	Account* paccount = (Account*)lua_touserdata(L, 1);
	float howMuch = lua_tonumber(L, 2);
	luaL_argcheck(L, paccount != nullptr, 1, "invaild arg, Account expectd.");
	luaL_checknumber(L, 2);

	bool success = paccount->withdrawal(howMuch);
	lua_pushboolean(L, success);
	return 1;
}


void lua_openAccout(lua_State* L)
{
	luaL_newlib(L, accoutLis);
	lua_setglobal(L, "Account");
}


