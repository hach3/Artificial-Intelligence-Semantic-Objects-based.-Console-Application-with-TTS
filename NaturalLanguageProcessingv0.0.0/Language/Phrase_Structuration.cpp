#include "Phrase_Structuration.h"

Phrase_Structuration::Phrase_Structuration()
{
	this->init();
}
Phrase_Structuration::~Phrase_Structuration()
{

}

void Phrase_Structuration::init()
{
	this->initAffirmations();
	this->initNegations();
	this->initQuestions();
}
void Phrase_Structuration::initQuestions()
{
	
}
void Phrase_Structuration::initAffirmations()
{
	vector<WORDS_TYPE> PVA; // Pronoun verb adjective
	PVA.push_back(DEMONSTRATIVE_PRONOUNS);
	PVA.push_back(ACTION_VERBS);
	PVA.push_back(COMPARING_ADJECTIVES);
	this->_phraseTypes.push_back(PVA);
}
void Phrase_Structuration::initNegations()
{

}


void Phrase_Structuration::getStructure(vector<WORD_AND_TYPE> sentenceTypes)
{
	vector<WORDS_TYPE> phraseWordsTypes;
	
	
	for (unsigned int y = 0; y < sentenceTypes.size(); y++)
	{
		phraseWordsTypes.push_back(sentenceTypes.at(y).types.at(0));
	}
	for (unsigned int i = 0; i < this->_phraseTypes.size(); i++)
	{
		if (this->_phraseTypes.at(i) == phraseWordsTypes)
		{
			cout << "STRUCTURE FOUND " << i << " : " << endl;
			for (unsigned int z = 0; z < this->_phraseTypes.at(i).size(); z++)
			{
				cout << this->_phraseTypes.at(i).at(z) << endl;;
			}

		}
	}
}