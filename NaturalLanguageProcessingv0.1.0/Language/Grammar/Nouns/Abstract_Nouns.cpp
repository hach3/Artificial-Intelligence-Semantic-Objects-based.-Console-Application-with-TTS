#include "Abstract_Nouns.h"

Abstract_Nouns::Abstract_Nouns(string value, WORDS wordType, WORDS_TYPE type) :
	Nouns(value, wordType, type)
{

}
Abstract_Nouns::Abstract_Nouns(string value, bool isPlural, WORDS wordType, WORDS_TYPE type) :
	Nouns(value, isPlural, wordType, type)
{

}
Abstract_Nouns::~Abstract_Nouns()
{

}
