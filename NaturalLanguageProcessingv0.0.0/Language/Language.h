#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Grammar\Pronouns\Reciprocal_Pronouns.h"

typedef struct {
	string word;
	vector<WORDS_TYPE> types;
} WORD_AND_TYPE;

class Language {
public:
	Language();
	~Language();
	
	void init();

	void addWord(Words* word);
	void getWordNTypeInSentence(vector<string> sentence, vector<WORD_AND_TYPE> &wordNType);
protected:
private:
	vector<Words *> _wordsList;
};

#endif //LANGUAGE_H