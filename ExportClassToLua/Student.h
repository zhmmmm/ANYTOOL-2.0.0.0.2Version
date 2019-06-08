#pragma once
#include <iostream>
#include <string>
#include "Lua_SDK/src/lua.hpp"
using namespace std;


class Student
{
	int m_Age = 0;
	string m_Name;
public:
	Student();
	~Student();
	string getName();
	void setName(string Name);
	int getAge();
	void setAge(int Age);
	void print();

	int Tolua_setName(lua_State* L);
	int Tolua_print(lua_State* L);

};
