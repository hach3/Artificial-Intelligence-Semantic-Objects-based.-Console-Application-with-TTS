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

	this->wordTypes[ARTICLES_ADJECTIVES] = "ARTICLES_ADJECTIVES";
	this->wordTypes[POSSESSIVE_ADJECTIVES] = "POSSESSIVE_ADJECTIVES";
	this->wordTypes[DEMONSTRATIVE_ADJECTIVES] = "DEMONSTRATIVE_ADJECTIVES";
	this->wordTypes[COORDINATE_ADJECTIVES] = "COORDINATE_ADJECTIVES";
	this->wordTypes[NUMBER_ADJECTIVES] = "NUMBER_ADJECTIVES";
	this->wordTypes[INTERROGATIVE_ADJECTIVES] = "INTERROGATIVE_ADJECTIVES";
	this->wordTypes[INDEFINITE_ADJECTIVES] = "INDEFINITE_ADJECTIVES";
	this->wordTypes[ATTRIBUTIVE_ADJECTIVES] = "ATTRIBUTIVE_ADJECTIVES";
	this->wordTypes[CONJUNCTIVE_ADVERBS] = "CONJUNCTIVE_ADVERBS";
	this->wordTypes[FREQUENCY_ADVERBS] = "FREQUENCY_ADVERBS";
	this->wordTypes[DEGREE_ADVERBS] = "DEGREE_ADVERBS";
	this->wordTypes[MANNER_ADVERBS] = "MANNER_ADVERBS";
	this->wordTypes[PLACE_ADVERBS] = "PLACE_ADVERBS";
	this->wordTypes[TIME_ADVERBS] = "TIME_ADVERBS";
	this->wordTypes[COORDINATING_CONJUNCTIONS] = "COORDINATING_CONJUNCTIONS";
	this->wordTypes[CORRELATIVE_CONJUNCTIONS] = "CORRELATIVE_CONJUNCTIONS";
	this->wordTypes[SUBORDINATING_CONJUNCTIONS] = "SUBORDINATING_CONJUNCTIONS";
	this->wordTypes[ABSTRACT_NOUNS] = "ABSTRACT_NOUNS";
	this->wordTypes[COLLECTIVE_NOUNS] = "COLLECTIVE_NOUNS";
	this->wordTypes[COMMON_NOUNS] = "COMMON_NOUNS";
	this->wordTypes[COMPOUND_NOUNS] = "COMPOUND_NOUNS";
	this->wordTypes[GERUND_NOUNS] = "GERUND_NOUNS";
	this->wordTypes[PROPER_NOUNS] = "PROPER_NOUNS";
	this->wordTypes[TIME_PREPOSITION] = "TIME_PREPOSITION";
	this->wordTypes[PLACE_PREPOSITION] = "PLACE_PREPOSITION";
	this->wordTypes[DEMONSTRATIVE_PRONOUNS] = "DEMONSTRATIVE_PRONOUNS";
	this->wordTypes[INDEFINITE_PRONOUNS] = "INDEFINITE_PRONOUNS";
	this->wordTypes[INTENSIVE_PRONOUNS] = "INTENSIVE_PRONOUNS";
	this->wordTypes[INTERROGATIVE_PRONOUNS] = "INTERROGATIVE_PRONOUNS";
	this->wordTypes[OBJECT_PRONOUNS] = "OBJECT_PRONOUNS";
	this->wordTypes[PERSONAL_PRONOUNS] = "PERSONAL_PRONOUNS";
	this->wordTypes[POSSESSIVE_PRONOUNS] = "POSSESSIVE_PRONOUNS";
	this->wordTypes[RECIPROCAL_PRONOUNS] = "RECIPROCAL_PRONOUNS";
	this->wordTypes[REFLEXIVE_PRONOUNS] = "REFLEXIVE_PRONOUNS";
	this->wordTypes[RELATIVE_PRONOUNS] = "RELATIVE_PRONOUNS";
	this->wordTypes[SUBJECT_PRONOUNS] = "SUBJECT_PRONOUNS";
	this->wordTypes[ACTION_VERBS] = "ACTION_VERBS";
	this->wordTypes[AUXILIARY_VERBS] = "AUXILIARY_VERBS";
	this->wordTypes[CONFUSING_VERBS] = "CONFUSING_VERBS";
	this->wordTypes[MODAL_VERBS] = "MODAL_VERBS";
	this->wordTypes[PHRASAL_VERBS] = "PHRASAL_VERBS";
	this->wordTypes[STATIVE_VERBS] = "STATIVE_VERBS";
	this->wordTypes[UNDEFINED] = "UNDEFINED";
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

	int finalSize = 1;
	
	for (auto const &n : sentenceTypes)
	{
		finalSize *= n.types.size();
	}
	vector<vector<WORDS_TYPE>> phraseWordsTypesVector (finalSize);	

	for (int i = 0; i < sentenceTypes.size(); ++i) {
		for (int j = 0; j < finalSize; ++j) {
			phraseWordsTypesVector.at(j).push_back(sentenceTypes.at(i).types.at(j%sentenceTypes.at(i).types.size()));
		}
	}
	

	for (unsigned int i = 0; i < phraseWordsTypesVector.size(); i++)
	{		
		
		cout << "POSSIBLE NUMBER " << i << " : " << endl;
		for (unsigned int y = 0; y < phraseWordsTypesVector.at(i).size(); y++)
		{
			cout << phraseWordsTypesVector.at(i).at(y) << " ";
		}
		cout << " = ";
		for (unsigned int y = 0; y < phraseWordsTypesVector.at(i).size(); y++)
		{
			cout << this->wordTypes[phraseWordsTypesVector.at(i).at(y)]  << " ";
		}
		cout << endl;
		cout << endl;
	}
	
}




