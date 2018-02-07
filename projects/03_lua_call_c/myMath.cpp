#pragma once
#include"myMath.h"
#include<iostream>


 int mymath_add(lua_State*	L)
{
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float result = x + y;
	lua_pushnumber(L, result);
	return 1;
}

 int mymath_sub(lua_State* L)
{
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float result = x - y;
	lua_pushnumber(L, result);
	return 1;
}

 int mymath_mul(lua_State* L)
{
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float result = x * y;
	lua_pushnumber(L, result);
	return 1;
}

 int mymath_div(lua_State* L)
{
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	if (y == 0)
	{
		std::cerr << "can't divided by 0." << std::endl;
		return 0;
	}
	
	float result = x / y;
	lua_pushnumber(L, result);
	return 1;
}



 int mymath_mod(lua_State* L)
{
	int x = luaL_checkinteger(L, 1);
	int y = luaL_checkinteger(L, 2);
	int result = x % y;
	lua_pushnumber(L, result);
	return 1; 
}



void lua_openmyMathLibs(lua_State* L)
{
	luaL_newlib(L, myMathFuncs);
	lua_setglobal(L, "mylib");
}