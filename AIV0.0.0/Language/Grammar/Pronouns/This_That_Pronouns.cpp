#include "This_That_Pronouns.h"

This_That_Pronouns::This_That_Pronouns() : 
	Pronouns()
{

}
This_That_Pronouns::This_That_Pronouns(std::string name, bool isPlural, bool isFar) :
	Pronouns(name),
	_isPlural(isPlural),
	_isFar(isFar)
{

}
This_That_Pronouns::~This_That_Pronouns()
{

}

bool This_That_Pronouns::isPlural(void)
{
	return this->_isPlural;
}
bool This_That_Pronouns::isFar(void)
{
	return this->_isFar;
}