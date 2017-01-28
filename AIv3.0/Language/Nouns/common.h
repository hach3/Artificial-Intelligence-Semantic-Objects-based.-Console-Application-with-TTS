#pragma once
#ifndef COMMON_H
#define COMMON_H

#include "globalNouns.h"

typedef struct {

	std::string _nounSingular;
	std::string _nounPlural;

	std::vector<std::string> _relatedWords;


	/*
	Concrete nouns call for the five senses. They can be sight, smell, hearing, taste, touched.
	The structure takes a bool (isConcrete), and if it is, it lists all the senses that call
	*/
	IS_CONCRETE _isConcrete;

	/*
	Check if it's countable, it takes a bool (isCountable)
	*/
	IS_COUNTABLE _isCountable;

} COMMON_NOUNS;



class Common_Noun {
public:
	Common_Noun();
	Common_Noun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled);
	~Common_Noun();
	

	/* CHECK IF THE NOUN IS ABSTRACT */
	bool isCommon(std::string noun);
	/* CREATE A NEW ABSTRACT NAME */
	void addCommonNoun(std::string singular);
	void addCommonNoun(std::string singular, std::string plural);
	void addCommonNoun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled);

	/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
	std::vector<std::string> getRelatedWords(std::string noun);
	/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
	bool checkIfRelated(std::string relatedNoun);
	void addRelatedWord(std::string noun, std::string relatedWord);

	/* RETURN TRUE IF THE NOUN IS COUNTABLE */
	bool isCountable(std::string noun);
	void setCountable(std::string noun, bool isCountable);
	/* RETURN TRUE IF THE NOUN IS CONCRETE */
	bool isConcrete(std::string noun);
	void setConcrete(std::string noun, bool isConcrete);
	void setConcrete(std::string noun, bool isConcrete, std::vector<std::string> senseCalled);
	void addSenseCalled(std::string noun, std::string senseCalled);
	/* ALSO PUT THE SENSE CALLED IN VECTOR OUTPARAMETERS*/
	bool isConcrete(std::string noun, std::vector<std::string> &senseCalled);

protected:
private:
	std::vector<COMMON_NOUNS> _commonNounsList;
};
#endif //COMMON_H