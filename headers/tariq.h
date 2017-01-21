#ifndef TARIQ_H
#define TARIQ_H
#include "ai.h"
#include "concepts.h"
#include <iostream>
#include <sstream>
#include "memory.h"

class Tariq : public AI {
public:
	Tariq();
	~Tariq();

	/* Init all the concepts of Tariq*/
	void Initialization();

	/*
	This function gets the user message
	It starts getting the concepts foreach word in the sentence
	Then it calls for the concept related method
	ex:
	startBehavior("hello")
		getConcept("hello") -> does return SALUTATIONS (conceptName)
		startConcept(SALUTATIONS)

	*/
	/*
	StartBehavior get the user msg, extract each word and create a list of conceptsName
	*/
	void startBehavior(std::string);

	/*
	Get the conceptName and start the conceptaction
	*/
	void startConcept(std::vector<Concepts> conceptsIn);

	/*
	Say Hello :)
	*/
	void startConceptSalutations();
	/*
	Say "Dunno about this concept"
	*/
	void noConceptFound();


	
protected:
private:
	/*Function to init the salutation concept*/
	void ConceptSalutations();

	
};
#endif