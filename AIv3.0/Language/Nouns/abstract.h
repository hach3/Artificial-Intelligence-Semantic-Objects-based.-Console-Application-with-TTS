#pragma once
#ifndef ABSTRACT_H
#define ABSTRACT_H

#include "globalNouns.h"

typedef struct {

	std::string _nounSingular;
	std::string _nounPlural;

	/*
	The concept of an abstract noun can be feelings, emotions, ideals, concepts, qualities, characteristics...
	*/
	std::string _concept;

	std::vector<std::string> _relatedWords;

	IS_COUNTABLE _isCountable;

} ABSTRACT_NOUNS;


class Abstract_Noun {
public:
	/* CONSTRUCTOR*/
	Abstract_Noun();
	/* DESTRUCTOR : CLEAR THE VECTOR OF ABSTRACT NOUNS */
	
	~Abstract_Noun();

	/* INITIALISATION */
	void init();

	/* CHECK IF THE NOUN IS ABSTRACT */
	bool isAbstract(std::string noun);
	/* CREATE A NEW ABSTRACT NAME */
	void addAbstactNoun(std::string singular);
	void addAbstractNoun(std::string singular, std::string plural);
	void addAbstractNoun(std::string singular, std::string plural, std::string concept, std::vector<std::string> relatedWords, bool isCountable);
	
	/* RETURN THE CONCEPT OF THE ABSTRACT NOUN */
	std::string getConcept();
	/* CHECK IF A CONCEPT IS INSIDE AN ABSTRACT NAME */
	bool checkIfConceptIn(std::string conceptName);
	void setConcept(std::string singular, std::string concept);

	/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
	std::vector<std::string> getRelatedWords(std::string noun);
	
	void addRelatedWord(std::string noun, std::string relatedWord);

	/* CHECK IF A NOUN IS RELATED TO AN ABSTRACT NOUN */
	bool checkIfRelated(std::string relatedNoun);

	/* RETURN TRUE IF THE NOUN IS COUNTABLE */
	bool isCountable(std::string noun);
	void setCountable(std::string noun, bool isCountable);

protected:
private:
	std::vector<ABSTRACT_NOUNS> _abstractNounsList;
};

#endif //ABSTRACT_H