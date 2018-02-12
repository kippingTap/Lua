#pragma once
#include<src\lua.hpp>


 int new_account(lua_State* L);

 int del_account(lua_State* L);

 int accout_getFund(lua_State* L);

 int accout_deposit(lua_State* L);

 int accout_withdrawal(lua_State* L);



static const luaL_Reg accoutLis[] = 
{
	{ "new", new_account },
	{ "delect", del_account },
	{ "getFund", accout_getFund },
	{ "deposit", accout_deposit },
	{ "withdrawal", accout_withdrawal },
	{ NULL, NULL },
};



void lua_openAccout(lua_State* L);