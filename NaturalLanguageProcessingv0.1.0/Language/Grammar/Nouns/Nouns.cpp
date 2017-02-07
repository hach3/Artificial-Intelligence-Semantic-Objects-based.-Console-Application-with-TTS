#include "Nouns.h"

Nouns::Nouns(void) :
	Words()
{

}
Nouns::Nouns(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)

{

}
Nouns::Nouns(string value, bool isPlural, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type),
	_isPlural(isPlural)
{

}
Nouns::~Nouns(void)
{

}

bool Nouns::isPlural()
{
	return _isPlural;
}