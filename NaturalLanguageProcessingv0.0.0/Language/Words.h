#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum WORDS {
	ADJECTIVES,
	ADVERBS,
	NOUNS,
	PRONOUNS,
	VERBS
};
enum WORDS_TYPE {
	DEMONSTRATIVE_PRONOUNS,
	INDEFINITE_PRONOUNS,
	INTENSIVE_PRONOUNS,
	INTERROGATIVE_PRONOUNS,
	OBJECT_PRONOUNS,
	PERSONAL_PRONOUNS,
	POSSESSIVE_PRONOUNS,
	RECIPROCAL_PRONOUNS,
	REFLEXIVE_PRONOUNS,
	RELATIVE_PRONOUNS,
	SUBJECT_PRONOUNS,
	COMPARING_ADJECTIVES,
	COMPOUND_ADJECTIVES,
	DENOMINAL_ADJECTIVES,
	ACTION_VERBS,
	AUXILIARY_VERBS,
	CONFUSING_VERBS,
	MODAL_VERBS,
	PHRASAL_VERBS,
	STATIVE_VERBS
	
	
};

class Words {
public:
	Words();
	Words(string value, WORDS typeWord, WORDS_TYPE type);
	~Words();

	string getValue(void);
	WORDS_TYPE getType(void);
	WORDS getWordType(void);

	/* VIRTUAL METHODS FOR VERBS */
	virtual string getInfinitiveForm() = 0;
	virtual string getIngForm() = 0;
	virtual string getPassiveForm() = 0;
	virtual string getParticipateForm() = 0;
	virtual vector<string> getPresentForm() = 0;
	virtual vector<string> getPastForm() = 0;

protected:
	void setValue(string value);
	void setType(WORDS_TYPE type);
	void setWordType(WORDS type);
private:
	/*
	Value is the basic form of the word
	WORDS_TYPE is DEMONSTRATIVE_PRONOUNS
	WORDS is PRONOUNS
	*/
	string _value;
	WORDS_TYPE _type;
	WORDS _wordType;
};

#endif //WORDS_H