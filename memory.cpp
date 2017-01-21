#include "memory.h"
#include <iostream>
Memory::Memory()
{

}

Memory::Memory(std::string who, std::string what,std::string how, std::string why, std::string where, std::string when)
{
	this->_who = who;
	this->_what = what;
	this->_why = why;
	this->_where = where;
	this->_when = when;
	this->_how = how;
}

Memory::~Memory()
{

}

std::string Memory::getWho()
{
	return this->_who;
}
std::string Memory::getWhat()
{
	return this->_what;
}
std::string Memory::getWhy()
{
	return this->_why;
}
std::string Memory::getWhere()
{
	return this->_where;
}
std::string Memory::getWhen()
{
	return this->_when;
}

std::string Memory::getHow()
{
	return this->_how;
}

void Memory::printtheMemory()
{ 
	std::cout << this->_who << " " << this->_what << " " << this->_why << " " << this->_where << " " << this->_when << std::endl;
}

void Memory::explainHow()
{
	std::cout << this->_how << std::endl;
}