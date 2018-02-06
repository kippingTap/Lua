#include<iostream>
#include<src\lua.hpp>


int main()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	if (L == nullptr)
	{
		std::cerr << "Out of Memory!" << std::endl;
		return -1;
	}

	//call lua trunck from string buffer
	const char* trunck = "local t = os.date(); print(\"system time: \", t)";
	if (luaL_dostring(L, trunck))
	{
		const char* e = lua_tostring(L, -1);
		std::cerr  << __FILE__ << ":" << __LINE__ << "\t" << e << std::endl;
		lua_pop(L, 1);
	}

	//call lua from a file
	if (luaL_loadfile(L, "D:\\Visual Studio Projects\\Lua\\projects\\02_c_call_lua\\test.lua") || lua_pcall(L, 0, 0, 0))
	{
		const char* e = lua_tostring(L, -1);
		std::cerr << __FILE__ << ":" << __LINE__ << "\t" << e << std::endl;
		lua_pop(L, 1);
	}

	lua_close(L);
	system("PAUSE");
	return 0;
}