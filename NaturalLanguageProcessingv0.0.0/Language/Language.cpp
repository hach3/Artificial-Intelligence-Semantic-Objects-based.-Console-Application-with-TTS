#include "Language.h"

Language::Language()
{
	this->init();
}
Language::~Language()
{

}
void Language::init()
{
	this->addWord(new Reciprocal_Pronouns("ONE ANOTHER", RECIPROCAL_PRONOUNS));
	this->addWord(new Reciprocal_Pronouns("EACH OTHER", RECIPROCAL_PRONOUNS));
}

void Language::addWord(Words* word)
{
	this->_wordsList.push_back(word);
}

void Language::getWordNTypeInSentence(string sentence, vector<WORD_AND_TYPE> &wordNType)
{
	/*
	Check the phrase, get each word (starting by the composed one)
	Associate each word with its type !
	*/
	size_t foundAt;
	for (unsigned int i = 0; i < this->_wordsList.size(); i++)
	{
		foundAt = sentence.find(this->_wordsList.at(i)->getValue());
		if (foundAt != string::npos)
		{
			WORD_AND_TYPE wNt;
			wNt.word = this->_wordsList.at(i)->getValue();
			wNt.type = this->_wordsList.at(i)->getType();
			wordNType.push_back(wNt);
		}
	}
}