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
	
	vector<WORDS_TYPE> tmpVector;
	vector<WORDS_TYPE> tmp2Vector;
	string subject;
	string aux;
	string verb;
	string complement;

	/* TRYING NEXT_PERMUTATION TO EXTRACT ALL COMBINATIONS OF PHRASE STRUCTURE */

	//So i've got sentenceTypes which is a vector of vector of int
	

	int finalSize = 1;
	for (auto const &n : sentenceTypes)
	{
		finalSize *= n.types.size();
	}
	vector<vector<WORDS_TYPE>> phraseWordsTypesVector (finalSize);	

	for (int i = 0; i < sentenceTypes.size(); ++i) {
		cout << " Possibility " << endl;
		for (int j = 0; j < finalSize; ++j) {
			phraseWordsTypesVector.at(j).push_back(sentenceTypes.at(i).types.at(j%sentenceTypes.at(i).types.size()));
		}
		cout << endl;
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




