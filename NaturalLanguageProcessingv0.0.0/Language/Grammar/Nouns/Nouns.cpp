#include "Nouns.h"


Nouns::Nouns(void) :
	Words()
{

}
Nouns::Nouns(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Nouns::~Nouns(void)
{

}


string Nouns::getInfinitiveForm()
{
	return "s";
}
string Nouns::getIngForm()
{
	return "s";
}
string Nouns::getPassiveForm()
{
	return "s";
}
string Nouns::getParticipateForm()
{
	return "s";
}
vector<string> Nouns::getPresentForm()
{
	vector<string> s;
	return s;
}
vector<string> Nouns::getPastForm()
{
	vector<string> s;
	return s;
}