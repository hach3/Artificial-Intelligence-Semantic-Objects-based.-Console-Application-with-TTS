#pragma once
#ifndef COLLECTIVE_H
#define COLLECTIVE_H

#include "globalNouns.h"

typedef struct {

	std::string _nounSingular;
	std::string _nounPlural;

	/*
	Collective nouns packs nouns into a class. Example : a swarm is a group of insects, crowd is a group of people, staff is a group of worker...
	*/
	std::string _relatedToNoun;


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

} COLLECTIVE_NOUNS;

class Collective_Noun {
public:
	Collective_Noun();
	Collective_Noun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled);
	~Collective_Noun();

	/* CHECK IF THE NOUN IS ABSTRACT */
	bool isCollective(std::string noun);
	/* CREATE A NEW ABSTRACT NAME */
	void addCollectiveNoun(std::string singular);
	void addCollectiveNoun(std::string singular, std::string plural);
	void addCollectiveNoun(std::string singular, std::string plural, std::vector<std::string> relatedWords, bool isCountable, bool isConcrete, std::vector<std::string> senseCalled);

	/* RETURN THE NOUN RELATED TO THE COLLECTIVE NOUN, for example, swarm will return insects */
	std::string getRelatedNoun(std::string noun);
	void addRelatedWord(std::string noun, std::string relatedWord);

	/* RETURN THE RELATED WORDS VECTOR OF A NOUN */
	std::vector<std::string> getRelatedWords(std::string noun);
	/* CHECK IF A NOUN IS RELATED TO A COLLECTIVE NOUN */
	bool checkIfRelated(std::string relatedNoun);

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
	std::vector<COLLECTIVE_NOUNS> _collectiveNounsList;
};
#endif //COLLECTIVE_H