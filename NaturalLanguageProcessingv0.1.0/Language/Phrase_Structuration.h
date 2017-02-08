#ifndef PHRASE_STRUCTURATION_H
#define PHRASE_STRUCTURATION_H

#include "Language.h"
#include <map>

class Phrase_Structuration {
public:
	Phrase_Structuration();
	~Phrase_Structuration();

	void init();
	void initQuestions();
	void initAffirmations();
	void initNegations();
	

	void getStructure(vector<WORD_AND_TYPE> sentenceTypes, vector<vector<WORDS_TYPE>> &test1);
	map<WORDS_TYPE, string> getWordTypesInString();
	
protected:
private:
	vector<vector<WORDS_TYPE>> _phraseTypes;
	map<WORDS_TYPE, string> wordTypes;
};

#endif //PHRASE_STRUCTURATION_H