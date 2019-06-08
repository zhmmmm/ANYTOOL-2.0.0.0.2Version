#include "Student.h"



Student::Student()
{
	printf("构造函数调用");
}
Student::~Student()
{
	printf("析构函数调用");
}
string Student::getName()
{
	return this->m_Name;
}
void Student::setName(string Name)
{
	this->m_Name = Name;
}
int Student::getAge()
{
	return this->m_Age;
}
void Student::setAge(int Age)
{
	this->m_Age = Age;
}
void Student::print()
{
	std::cout << "Name = " << this->m_Name << std::endl;
	std::cout << "Age = " << this->m_Age << std::endl;
}

int Student::Tolua_setName(lua_State* L)
{
	this->setName(lua_tostring(L, -1));
	return 0;
}
int Student::Tolua_print(lua_State* L)
{
	Student::print();
	return 10;
}