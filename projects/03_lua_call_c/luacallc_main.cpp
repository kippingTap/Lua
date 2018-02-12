#include<iostream>
#include<src\lua.hpp>
#include"myMath.h"
#include"accountBinding.h"



//  c register cfunctions to lua
// lua call c

int main()
{
	
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_openmyMathLibs(L);
	lua_openAccout(L);

	if (L == nullptr)
	{
		std::cerr << "Out of Memory!" << std::endl;
		return -1;
	}

	//call lua from a file
	if (luaL_loadfile(L, "D:\\Visual Studio Projects\\Lua\\projects\\03_lua_call_c\\test.lua") || lua_pcall(L, 0, 0, 0))
	{
		const char* e = lua_tostring(L, -1);
		std::cerr << __FILE__ << ":" << __LINE__ << "\t" << e << std::endl;
		lua_pop(L, 1);
	}


	lua_close(L);
	system("PAUSE");
	return 0;
}