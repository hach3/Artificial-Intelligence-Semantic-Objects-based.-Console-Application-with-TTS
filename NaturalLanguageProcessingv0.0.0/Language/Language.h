#ifndef LANGUAGE_H
#define LANGUAGE_H


#include "Grammar\Pronouns\Demonstrative_Pronouns.h"
#include "Grammar\Pronouns\Indefinite_Pronouns.h"
#include "Grammar\Pronouns\Intensive_Pronouns.h"
#include "Grammar\Pronouns\Interrogative_Pronouns.h"
#include "Grammar\Pronouns\Object_Pronouns.h"
#include "Grammar\Pronouns\Personal_Pronouns.h"
#include "Grammar\Pronouns\Possessive_Pronouns.h"
#include "Grammar\Pronouns\Reciprocal_Pronouns.h"
#include "Grammar\Pronouns\Reflexive_Pronouns.h"
#include "Grammar\Pronouns\Relative_Pronouns.h"
#include "Grammar\Pronouns\Subject_Pronouns.h"

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
	void getWordNTypeInSentence(vector<string> sentence, vector<WORD_AND_TYPE>* wordNType);
protected:
private:
	vector<Words *> _wordsList;
};

#endif //LANGUAGE_H