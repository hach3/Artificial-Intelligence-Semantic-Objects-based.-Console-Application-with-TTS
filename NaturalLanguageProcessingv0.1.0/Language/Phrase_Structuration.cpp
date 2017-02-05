#include "Phrase_Structuration.h"
#include <algorithm>


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
	vector<WORDS_TYPE> tmp2Vector;
	string subject;
	string aux;
	string verb;
	string complement;

	/* TRYING NEXT_PERMUTATION TO EXTRACT ALL COMBINATIONS OF PHRASE STRUCTURE */

	//So i've got sentenceTypes which is a vector of vector of int

	for (int i = 0; i < sentenceTypes.size(); i++)
	{		
		do {
			cout << "Next permutation " << endl;
			for (int y = 0; y < sentenceTypes.at(i).types.size(); y++)
			{	
				cout << sentenceTypes.at(i).types.at(y) << " ";
			}
			cout << endl;
		} while (next_permutation(sentenceTypes.at(i).types.begin(), sentenceTypes.at(i).types.begin() + sentenceTypes.at(i).types.size()));		
	}


	/*
	
	this->printAll(sentenceTypes, tmpVector, tmp2Vector,phraseWordsTypesVector, 0, 0);
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
	*/
}

void Phrase_Structuration::printAll(const vector<WORD_AND_TYPE> &allVecs, vector<WORDS_TYPE> &tmpVector, vector<WORDS_TYPE> tmp2Vector, vector<vector<WORDS_TYPE>> &phraseWordsTypesVector, size_t vecIndex, int strSoFar)
{
	if (vecIndex >= allVecs.size())
	{
	//	cout << "FINISHED POSSIBILITY : ";
		phraseWordsTypesVector.push_back(tmpVector);
		//phraseWordsTypesVector.push_back(tmp2Vector);
		tmpVector.clear();
		tmp2Vector.clear();
	//	cout << strSoFar << endl;
		return;
	}
	for (size_t i = 0; i < allVecs[vecIndex].types.size(); i++)
	{
		//cout << "Vec : " << vecIndex << endl;		
		tmpVector.push_back(allVecs[vecIndex].types[i]);
		printAll(allVecs, tmpVector, tmp2Vector, phraseWordsTypesVector, vecIndex + 1, strSoFar + allVecs[vecIndex].types[i]);
		
	//	cout << "Vector : " << vecIndex << endl;
	}
	
}
