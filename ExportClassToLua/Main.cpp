#include <iostream>
#include <Windows.h>
#define Main main

#include "Student.h"
#include "Lua_SDK/LuaBridge/LuaBridge.h"


#pragma comment(lib,"Lua_SDK/Lua_Debug/Lib/Lua.lib")

int To_LuaFunction(lua_State *L)
{
	const char *ptitle = lua_tostring(L,1);
	const char *ptext = lua_tostring(L, 2);
	int btn = lua_tointeger(L, 3);


	int ret = MessageBoxA(NULL, ptitle, ptext, btn);
	lua_settop(L,0);
	lua_pushinteger(L, ret);
	return 1;
}

int Main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L, "CPP_To_Lua", To_LuaFunction);


	luaL_loadfile(L,"Main.lua");
	lua_pcall(L, 0, 0, 0);

	int temp = lua_getglobal(L, "ToCPP_int");

	int luaret = lua_pcall(L, 0, 1, 0);
	if (luaret != LUA_OK)
	{
		
	}
	else
	{
		int ret = lua_tonumber(L,-1);
		std::cout << ret << std::endl;
		lua_getglobal(L, "ToCPP_string");
		lua_pcall(L, 0, 2, 0);
		string s = lua_tostring(L, -2);
		std::cout << s << std::endl;
		lua_getglobal(L, "Main");
		lua_pushnumber(L, 132456);
		lua_pcall(L, 1, 3, 0);
		std::cout << lua_tonumber(L,-3) << std::endl;

		int var = 0;
	}

	//ÇåÕ»
	lua_settop(L, 0);




	lua_close(L);
	L = NULL;




	system("pause");
	return 0;
}
