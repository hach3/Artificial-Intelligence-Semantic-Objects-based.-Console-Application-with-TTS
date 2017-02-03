#include "Pronouns.h"


Pronouns::Pronouns(void) :
	Words()
{

}
Pronouns::Pronouns(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)
	
{

}
Pronouns::~Pronouns(void)
{

}


string Pronouns::getInfinitiveForm()
{
	return "s";
}
string Pronouns::getIngForm()
{
	return "s";
}
string Pronouns::getPassiveForm()
{
	return "s";
}
string Pronouns::getParticipateForm()
{
	return "s";
}
vector<string> Pronouns::getPresentForm()
{
	vector<string> s;
	return s;
}
vector<string> Pronouns::getPastForm()
{
	vector<string> s;
	return s;
}