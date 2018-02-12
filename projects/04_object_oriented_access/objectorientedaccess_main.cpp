#include<src\lua.hpp>
#include<iostream>



int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if(luaL_dofile(L,"D:\\Visual Studio Projects\\Lua\\script\\init.lua"))
	{
		const char* e = lua_tostring(L, -1);
		std::cerr << e << std::endl;
		lua_pop(L, 1);
	}

	lua_close(L);
	system("PAUSE");
	return 0;
}