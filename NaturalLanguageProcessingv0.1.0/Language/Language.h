#ifndef LANGUAGE_H
#define LANGUAGE_H



/* ADJECTIVES HERE */
#include "Grammar\Adjectives\Articles_Adjectives.h"
#include "Grammar\Adjectives\Attributive_Adjectives.h"
#include "Grammar\Adjectives\Coordinate_Adjectives.h"
#include "Grammar\Adjectives\Demonstrative_Adjectives.h"
#include "Grammar\Adjectives\Indefinite_Adjectives.h"
#include "Grammar\Adjectives\Interrogative_Adjectives.h"
#include "Grammar\Adjectives\Number_Adjectives.h"
#include "Grammar\Adjectives\Possessive_Adjectives.h"

/* ADVERBS HERE */
#include "Grammar\Adverbs\Conjunctive_Adverbs.h"
#include "Grammar\Adverbs\Degree_Adverbs.h"
#include "Grammar\Adverbs\Frequency_Adverbs.h"
#include "Grammar\Adverbs\Manner_Adverbs.h"
#include "Grammar\Adverbs\Place_Adverbs.h"
#include "Grammar\Adverbs\Time_Adverbs.h"

/* CONJUNCTIONS HERE */
#include "Grammar\Conjunctions\Coordinating_Conjunctions.h"
#include "Grammar\Conjunctions\Correlative_Conjunctions.h"
#include "Grammar\Conjunctions\Subordinating_Conjunctions.h"

/* PREPOSITIONS HERE */
#include "Grammar\Prepositions\Place_Prepositions.h"
#include "Grammar\Prepositions\Time_Prepositions.h"

/* NOUNS HERE */
#include "Grammar\Nouns\Abstract_Nouns.h"
#include "Grammar\Nouns\Collective_Nouns.h"
#include "Grammar\Nouns\Common_Nouns.h"
#include "Grammar\Nouns\Compound_Nouns.h"
#include "Grammar\Nouns\Gerund_Nouns.h"
#include "Grammar\Nouns\Proper_Nouns.h"

/* PRONOUNS HERE */
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

/* VERBS HERE */
#include "Grammar\Verbs\Action_Verbs.h"
#include "Grammar\Verbs\Auxiliary_Verbs.h"
#include "Grammar\Verbs\Confusing_Verbs.h"
#include "Grammar\Verbs\Modal_Verbs.h"
#include "Grammar\Verbs\Phrasal_Verbs.h"
#include "Grammar\Verbs\Stative_Verbs.h"



typedef struct {
	string word;
	vector<WORDS_TYPE> types;
} WORD_AND_TYPE;

class Language {
public:
	Language();
	~Language();
	
	void init();
	void initAdjectives();
	void initAdverbs();
	void initConjunctions();
	void initNouns();
	void initPrepositions();
	void initPronouns();
	void initVerbs();
	

	void readFile(string path, vector<string> &save);
	void readVerbsFile(string path, vector<vector<string>> &base, vector<vector<string>> &presentForm, vector<vector<string>> &pastForm);

	void addWord(Words* word);
	void getWordNTypeInSentence(vector<string> sentence, vector<WORD_AND_TYPE>* wordNType);
protected:
private:
	vector<Words *> _wordsList;
};

#endif //LANGUAGE_H
