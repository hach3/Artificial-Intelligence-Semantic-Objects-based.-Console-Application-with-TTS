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
	vector<WORDS_TYPE> PAuxINGP;
	PAuxINGP.push_back(SUBJECT_PRONOUNS);
	PAuxINGP.push_back(AUXILIARY_VERBS);
	PAuxINGP.push_back(CONFUSING_VERBS);
	PAuxINGP.push_back(INDEFINITE_PRONOUNS);
	this->_phraseTypes.push_back(PAuxINGP);
}
void Phrase_Structuration::initNegations()
{

}


void Phrase_Structuration::getStructure(vector<WORD_AND_TYPE> sentenceTypes)
{
	vector<WORDS_TYPE> phraseWordsTypes;	
	string subject;
	string verb;
	string complement;
	
	for (unsigned int y = 0; y < sentenceTypes.size(); y++)
	{
		phraseWordsTypes.push_back(sentenceTypes.at(y).types.at(0));
		switch (sentenceTypes.at(y).types.at(0))
		{
		case SUBJECT_PRONOUNS:
			subject = sentenceTypes.at(y).word;
			break;
		case CONFUSING_VERBS:
			verb = sentenceTypes.at(y).word;
			break;
		case INDEFINITE_PRONOUNS:
			complement = sentenceTypes.at(y).word;
			break;
		default:
			break;
		}
	}
	for (unsigned int i = 0; i < this->_phraseTypes.size(); i++)
	{
		if (this->_phraseTypes.at(i) == phraseWordsTypes)
		{
			cout << "STRUCTURE FOUND " << endl;
			cout << "SUBJECT : " << subject << endl;
			cout << "VERB : " << verb << endl;
			cout << "COMPLEMENT : " << complement << endl;
		}
	}
	
}