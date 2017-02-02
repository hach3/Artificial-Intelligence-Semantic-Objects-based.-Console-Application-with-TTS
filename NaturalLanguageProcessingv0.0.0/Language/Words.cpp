#include "Words.h"

Words::Words()
{

}
Words::Words(string value, WORDS_TYPE type) :
	_value(value),
	_type(type)
{
	
}
Words::~Words()
{

}

string Words::getValue(void)
{
	return this->_value;
}

void Words::setValue(string value)
{
	this->_value = value;
}


WORDS_TYPE Words::getType(void)
{
	return this->_type;
}
void Words::setType(WORDS_TYPE type)
{
	this->_type = type;
}