#pragma once
#ifndef PROPER_H
#define PROPER_H

#include "globalNouns.h"

typedef struct {

	std::string _singular;
	std::string _plural;
	/*
	France calls for the concept of country, Trump calls for the concept of human, man, dumb, dickhead...
	*/
	std::string _commonNounTarget;
	
	std::vector<std::string> _relatedWords;

	/*
	Concrete nouns call for the five senses. They can be sight, smell, hearing, taste, touched.
	The structure takes a bool (isConcrete), and if it is, it lists all the senses that call
	*/
	IS_CONCRETE _isConcrete;

} PROPER_NOUNS;

class Proper_Noun {
public:
	Proper_Noun();
	Proper_Noun(std::string singular, std::string plural, std::string commonNounTarget, std::vector<std::string> relatedWords, bool isConcrete, std::vector<std::string> senseCalled);
	~Proper_Noun();

	/* CHECK IF THE NOUN IS ABSTRACT */
	bool isProper(std::string noun);
	/* CREATE A NEW ABSTRACT NAME */
	void addProperNoun(std::string singular);
	void addProperNoun(std::string singular, std::string plural);
	void addProperNoun(std::string singular, std::string plural, std::string commonNounTarget);
	void addProperNoun(std::string singular, std::string plural, std::string commonNounTarget, std::vector<std::string> relatedWords, bool isConcrete, std::vector<std::string> senseCalled);

	/*
	RETURN THE COMMON NOUN TARGET
	*/
	std::string getCommonNounTarget(std::string noun);
	void setCommonNounTarget(std::string noun, std::string commonNounTarget);

	/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
	std::vector<std::string> getRelatedWords(std::string noun);
	void addRelatedWord(std::string noun, std::string relatedWord);

	/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
	bool checkIfRelated(std::string relatedNoun);

	/* RETURN TRUE IF THE NOUN IS CONCRETE */
	bool isConcrete(std::string noun);
	void setConcrete(std::string noun, bool isConcrete);
	void setConcrete(std::string noun, bool isConcrete, std::vector<std::string> senseCalled);
	void addSense(std::string noun, std::string senseCalled);
	/* ALSO PUT THE SENSE CALLED IN VECTOR OUTPARAMETERS*/
	bool isConcrete(std::string noun, std::vector<std::string> &senseCalled);

protected:
private:
	std::vector<PROPER_NOUNS> _properNounsList;
};
#endif //PROPER_H