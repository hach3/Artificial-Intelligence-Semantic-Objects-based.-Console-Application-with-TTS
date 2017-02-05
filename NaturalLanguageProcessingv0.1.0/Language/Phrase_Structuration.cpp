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
void Phrase_Structuration::initNegations(){}


void Phrase_Structuration::getStructure(vector<WORD_AND_TYPE> sentenceTypes)
{
	vector<vector<WORDS_TYPE>> phraseWordsTypesVector;
	vector<WORDS_TYPE> tmpVector;
	string subject;
	string aux;
	string verb;
	string complement;
	
	this->printAll(sentenceTypes, &phraseWordsTypesVector, tmpVector, 0, 0);	
	for (unsigned int i = 0; i < phraseWordsTypesVector.size(); i++)
	{		
		if (phraseWordsTypesVector.at(i).size() == sentenceTypes.size())
		{
			cout << "POSSIBLE NUMBER " << i << " : " << endl;
			for (unsigned int y = 0; y < phraseWordsTypesVector.at(i).size(); y++)
			{
				cout << phraseWordsTypesVector.at(i).at(y) << " ";
			}
			cout << endl;
		}
	}
}

void Phrase_Structuration::printAll(const vector<WORD_AND_TYPE> &allVecs, vector<vector<WORDS_TYPE>>* phraseWordsTypesVector, vector<WORDS_TYPE> &tmpVector, size_t vecIndex, int strSoFar)
{
	
	if (vecIndex >= allVecs.size())
	{		
		phraseWordsTypesVector->push_back(tmpVector);
		tmpVector.clear();
		cout << strSoFar << endl;
		return;
	}	
	for (size_t i = 0; i < allVecs[vecIndex].types.size(); i++)
	{		
		tmpVector.push_back(allVecs[vecIndex].types.at(i));
		printAll(allVecs, phraseWordsTypesVector, tmpVector, vecIndex + 1, strSoFar + allVecs[vecIndex].types.at(i));			
	}	
}