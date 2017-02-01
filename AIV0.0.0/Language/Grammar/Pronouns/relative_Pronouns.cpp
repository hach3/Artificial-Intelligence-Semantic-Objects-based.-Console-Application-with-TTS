#include "relative_Pronouns.h"



Relative_Pronouns::Relative_Pronouns() : 
	Pronouns()
{

}
Relative_Pronouns::Relative_Pronouns(std::string name, bool isSubject, bool isObject, bool isPossessive) :
	Pronouns(name),
	_isSubject(isSubject),
	_isObject(isObject),
	_isPossessive(isPossessive)
{

}
Relative_Pronouns::~Relative_Pronouns()
{

}

bool Relative_Pronouns::isSubject(void)
{
	return this->_isSubject;
}
bool Relative_Pronouns::isObject(void)
{
	return this->_isObject;
}
bool Relative_Pronouns::isPossessive(void)
{
	return this->_isPossessive;
}