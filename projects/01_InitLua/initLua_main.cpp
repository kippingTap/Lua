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

	//print hello lua
	
	if (luaL_dostring(L, "print(\"hello lua.\")"))
	{
		const char* e = lua_tostring(L, 1);
		std::cout << "[lua error]: " << e << std::endl;
		lua_pop(L, 1);
	}

	//print system time
	if (luaL_dostring(L, "local t = os.date(); print(\"system time: \", t)"))
	{
		const char* e = lua_tostring(L, 1);
		std::cout << "[lua error]: " << e << std::endl;
		lua_pop(L, 1);
	}

	lua_close(L);
	system("PAUSE");
	return 0;
}