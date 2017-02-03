#include "Prepositions.h"


Prepositions::Prepositions(void) :
	Words()
{

}
Prepositions::Prepositions(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Prepositions::~Prepositions(void)
{

}


string Prepositions::getInfinitiveForm()
{
	return "s";
}
string Prepositions::getIngForm()
{
	return "s";
}
string Prepositions::getPassiveForm()
{
	return "s";
}
string Prepositions::getParticipateForm()
{
	return "s";
}
vector<string> Prepositions::getPresentForm()
{
	vector<string> s;
	return s;
}
vector<string> Prepositions::getPastForm()
{
	vector<string> s;
	return s;
}