#include "person.h"

Person::Person()
{
	this->_name = "You";
}
Person::~Person()
{

}

void Person::setName(std::string name)
{
	this->_name = name;
}
std::string Person::getName()
{
	return this->_name;
}