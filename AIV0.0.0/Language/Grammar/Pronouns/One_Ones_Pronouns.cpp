#include "One_Ones_Pronouns.h"

One_Ones_Pronouns::One_Ones_Pronouns()
{

}

One_Ones_Pronouns::One_Ones_Pronouns(std::string name, bool isPlural) : 
	Pronouns(name),
	_isPlural(isPlural)
{

}

One_Ones_Pronouns::~One_Ones_Pronouns()
{
	delete this;
}


bool One_Ones_Pronouns::isPlural()
{
	return this->_isPlural;
}
