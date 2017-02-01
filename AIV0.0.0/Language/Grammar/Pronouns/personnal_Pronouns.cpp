#include "personnal_Pronouns.h"

Personnal_Pronouns::Personnal_Pronouns()
{

}
Personnal_Pronouns::Personnal_Pronouns(std::string _name, bool isSubject, bool isObject, bool isPlural, int person) : 
	Pronouns(_name)
{

	this->_isSubject = isSubject;
	this->_isObject = isObject;
	this->_isPlural = isPlural;
	this->_person = person;
}
Personnal_Pronouns::~Personnal_Pronouns()
{
	delete this;
}


bool Personnal_Pronouns::isSubject()
{
	return this->_isSubject;
}
bool Personnal_Pronouns::isObject()
{
	return this->_isObject;
}
bool Personnal_Pronouns::isPlural()
{
	return this->_isPlural;
}
int Personnal_Pronouns::getPerson()
{
	return this->_person;
}
