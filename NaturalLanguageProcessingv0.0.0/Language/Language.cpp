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


void Language::getWordNTypeInSentence(vector<string> sentence, vector<WORD_AND_TYPE> &wordNType)
{
	/*
	Check the phrase, get each word (starting by the composed one)
	Associate each word with its type !
	*/
	WORD_AND_TYPE wnt;
	string wordToCompareComposedBy2Words;
	string wordToCompareComposedBy3Words;
	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		for (unsigned int y = 0; y < this->_wordsList.size(); y++)
		{
			if (i < sentence.size() - 2)
			{
				wordToCompareComposedBy3Words = sentence.at(i) + " " + sentence.at(i + 1) + " " + sentence.at(i + 2);

				wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
				if (wordToCompareComposedBy3Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType.push_back(wnt);
					i+=2;
				}
				else if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType.push_back(wnt);
					i++;
				}
				else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType.push_back(wnt);
				}

			}
			else if (i < sentence.size() - 1)
			{
				wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);

				if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType.push_back(wnt);
					i++;
				}
				else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType.push_back(wnt);
				}
			}
		
			else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
			{
				wnt.word = this->_wordsList.at(y)->getValue();
				wnt.types.push_back(this->_wordsList.at(y)->getType());
				wordNType.push_back(wnt);
			}
	
			
		}
	}
	
}