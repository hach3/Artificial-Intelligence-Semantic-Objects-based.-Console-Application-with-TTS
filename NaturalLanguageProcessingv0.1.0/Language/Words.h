#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum WORDS {
	ADJECTIVES,
	ADVERBS,
	CONJUNCTIONS,
	NOUNS,
	PREPOSITIONS,
	PRONOUNS,
	VERBS
};

enum WORDS_TYPE {
	COMPARING_ADJECTIVES,
	COMPOUND_ADJECTIVES,
	DENOMINAL_ADJECTIVES,
	CONJUNCTIVE_ADVERBS,
	DEGREE_ADVERBS,
	FREQUENCY_ADVERBS,
	MANNER_ADVERBS,
	PLACE_ADVERBS,
	TIME_ADVERBS,
	COORDINATING_CONJUNCTIONS,
	CORRELATIVE_CONJUNCTIONS,
	SUBORDINATING_CONJUNCTIONS,
	ABSTRACT_NOUNS,
	COLLECTIVE_NOUNS,
	COMMON_NOUNS,
	COMPOUND_NOUNS,
	GERUND_NOUNS,
	PROPER_NOUNS,
	TIME_PREPOSITION,
	PLACE_PREPOSITION,
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
