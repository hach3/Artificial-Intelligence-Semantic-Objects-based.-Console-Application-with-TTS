#include "question_Pronouns.h"


Question_Pronouns::Question_Pronouns()
{

}
Question_Pronouns::Question_Pronouns(std::string wh, bool isPeople, bool isPossession, bool isThing, bool isChoose) :
	Pronouns(wh)
{
	
	this->_isPeople = isPeople;
	this->_isPossession = isPossession;
	this->_isThing = isThing;
	this->_isChoose = isChoose;
}
Question_Pronouns::~Question_Pronouns()
{
	delete this;
}


bool Question_Pronouns::isPeople()
{
	return this->_isPeople;
}
bool Question_Pronouns::isPossession()
{
	return this->_isPossession;
}
bool Question_Pronouns::isThing()
{
	return this->_isThing;
}
bool Question_Pronouns::isChoose()
{
	return this->_isChoose;
}
