#ifndef PHRASE_STRUCTURATION_H
#define PHRASE_STRUCTURATION_H

#include "Language.h"

class Phrase_Structuration {
public:
	Phrase_Structuration();
	~Phrase_Structuration();

	void init();
	void initQuestions();
	void initAffirmations();
	void initNegations();
	

	void getStructure(vector<WORD_AND_TYPE> sentenceTypes);
	void printAll(const vector<WORD_AND_TYPE> &allVecs, vector<WORDS_TYPE> &tmpVector, vector<WORDS_TYPE> tmp2Vector, vector<vector<WORDS_TYPE>> &phraseWordsTypesVector, size_t vecIndex, int strSoFar, int nb);
	
protected:
private:
	vector<vector<WORDS_TYPE>> _phraseTypes;
};

#endif //PHRASE_STRUCTURATION_H