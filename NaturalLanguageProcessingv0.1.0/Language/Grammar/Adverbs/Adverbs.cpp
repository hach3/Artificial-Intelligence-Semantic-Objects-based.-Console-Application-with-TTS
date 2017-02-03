#include "Adverbs.h"


Adverbs::Adverbs(void) :
	Words()
{

}
Adverbs::Adverbs(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Adverbs::~Adverbs(void)
{
	
}

string Adverbs::getInfinitiveForm()
{
	return "s";
}
string Adverbs::getIngForm()
{
	return "s";
}
string Adverbs::getPassiveForm()
{
	return "a";
}
string Adverbs::getParticipateForm()
{
	return "s";
}
vector<string> Adverbs::getPresentForm()
{
	vector<string> s;
	return s;
}
vector<string> Adverbs::getPastForm()
{
	vector<string> s;
	return s;
}