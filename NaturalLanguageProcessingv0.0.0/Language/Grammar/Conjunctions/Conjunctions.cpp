#include "Conjunctions.h"


Conjunctions::Conjunctions(void) :
	Words()
{

}
Conjunctions::Conjunctions(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Conjunctions::~Conjunctions(void)
{

}


string Conjunctions::getInfinitiveForm()
{
	return "s";
}
string Conjunctions::getIngForm()
{
	return "s";
}
string Conjunctions::getPassiveForm()
{
	return "s";
}
string Conjunctions::getParticipateForm()
{
	return "s";
}
vector<string> Conjunctions::getPresentForm()
{
	vector<string> s;

	return s;
}
vector<string> Conjunctions::getPastForm()
{
	vector<string> s;
	return s;
}