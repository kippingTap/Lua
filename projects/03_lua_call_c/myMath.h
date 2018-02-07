#pragma once
#include<src\lua.hpp>



 int mymath_add(lua_State*	L);

 int mymath_sub(lua_State* L);

 int mymath_mul(lua_State* L);

 int mymath_div(lua_State* L);

 int mymath_mod(lua_State* L);


const luaL_Reg myMathFuncs[] =
{
	{ "add", mymath_add },
	{ "sub", mymath_sub },
	{ "mul", mymath_mul },
	{ "div", mymath_div },
	{ "mod", mymath_mod },
	{ NULL, NULL },
};


void lua_openmyMathLibs(lua_State* L);
