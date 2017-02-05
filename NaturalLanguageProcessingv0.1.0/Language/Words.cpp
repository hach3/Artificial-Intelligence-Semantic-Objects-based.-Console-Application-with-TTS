#include "Words.h"

Words::Words()
{

}
Words::Words(string value, WORDS typeWord, WORDS_TYPE type) :
	_value(value),
	_wordType(typeWord),
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

WORDS Words::getWordType(void)
{
	return this->_wordType;
}
void Words::setWordType(WORDS type)
{
	this->_wordType = type;
}


string Words::getInfinitiveForm()
{
	return "Hello World";
}
string Words::getIngForm()
{
	return "Hello World";
}
string Words::getPassiveForm()
{
	return "Hello World";
}
string Words::getParticipateForm()
{
	return "Hello World";
}
vector<string> Words::getPresentForm()
{
	vector<string> helloWorld;
	return helloWorld;
}
vector<string> Words::getPastForm()
{
	vector<string> helloWorld;
	return helloWorld;
}