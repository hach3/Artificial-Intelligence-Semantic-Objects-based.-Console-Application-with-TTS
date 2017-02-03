#include "Adjectives.h"



Adjectives::Adjectives(void) :
	Words()
{

}
Adjectives::Adjectives(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Adjectives::~Adjectives(void)
{

}


string Adjectives::getInfinitiveForm()
{
	return "s";
}
string Adjectives::getIngForm()
{
	return "s";
}
string Adjectives::getPassiveForm()
{
	return "s";
}
string Adjectives::getParticipateForm()
{
	return "s";
}
vector<string> Adjectives::getPresentForm()
{
	vector<string> s;
	return s;
}
vector<string> Adjectives::getPastForm()
{
	vector<string> s;
	return s;
}