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
	vector<vector<WORDS_TYPE>> phraseWordsTypesVector;
	string subject;
	string aux;
	string verb;
	string complement;
	int nbPossibilities = 1;

	int maxLength = 0;
	vector<int> vectorLengths;
	int size = vectorLengths.size();
	for (unsigned int i = 0; i < sentenceTypes.size(); i++)
	{
		vectorLengths.push_back(sentenceTypes.at(i).types.size());
		if (maxLength < sentenceTypes.at(i).types.size())
		{
			maxLength = sentenceTypes.at(i).types.size();
		}
	}


	for (unsigned int i = 0; i < maxLength; i++)
	{
		for (unsigned int y = 0; y < sentenceTypes.size(); y++)
		{
			if (sentenceTypes.at(y).types.size() < maxLength)
			{
				if(sentenceTypes.at(y).types.size() > 0)
					phraseWordsTypes.push_back(sentenceTypes.at(y).types.at(0));
			}
			else
			{
				phraseWordsTypes.push_back(sentenceTypes.at(y).types.at(i));
			}
		}
		phraseWordsTypesVector.push_back(phraseWordsTypes);
		phraseWordsTypes.clear();
	}

	for (unsigned int i = 0; i < phraseWordsTypesVector.size(); i++)
	{
		cout << "POSSIBLE NUMBER " << i << " : " << endl;
		for (unsigned int y = 0; y < phraseWordsTypesVector.at(i).size(); y++)
		{
			 cout << phraseWordsTypesVector.at(i).at(y) << " ";
		}
		cout << endl;
		
	}
	
	
	
}

