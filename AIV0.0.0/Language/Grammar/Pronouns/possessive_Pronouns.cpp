#include "possessive_Pronouns.h"

Possessive_Pronouns::Possessive_Pronouns()
{

}
Possessive_Pronouns::Possessive_Pronouns(std::string possessive, bool isPlural, int person) :
	Pronouns(possessive)
{
	
	this->_isPlural = isPlural;
	this->_person = person;
}
Possessive_Pronouns::~Possessive_Pronouns()
{
	delete this;
}



bool Possessive_Pronouns::isPlural()
{
	return this->_isPlural;
}
int Possessive_Pronouns::getPerson()
{
	return this->_person;
}
