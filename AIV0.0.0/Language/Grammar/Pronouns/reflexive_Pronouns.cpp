#include "reflexive_Pronouns.h"


Reflexive_Pronouns::Reflexive_Pronouns()
{

}
Reflexive_Pronouns::Reflexive_Pronouns(std::string reflexive, bool isPlural, int person) :
	Pronouns(reflexive)
{
	
	this->_isPlural = isPlural;
	this->_person = person;
}
Reflexive_Pronouns::~Reflexive_Pronouns()
{
	delete this;
}



bool Reflexive_Pronouns::isPlural()
{
	return this->_isPlural;
}
int Reflexive_Pronouns::getPerson()
{
	return this->_person;
}
