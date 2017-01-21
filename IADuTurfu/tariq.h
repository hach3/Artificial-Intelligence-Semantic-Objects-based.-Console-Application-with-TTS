#ifndef TARIQ_H
#define TARIQ_H
#include "ai.h"
#include "concepts.h"
#include <iostream>
#include <sstream>
#include "memory.h"

#define DUNNO "I don\'t know much about that."
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

	void startConceptName(std::string subject, std::string conceptdude);
	/*
	Say "Dunno about this concept"
	*/
	void noConceptFound();


	
protected:
private:
	/*Function to init the salutation concept*/
	void ConceptSalutations();
	
	void ConceptMe();
	void ConceptYou();

	void ConceptName();
	void ConceptFirstName();


	void ConceptBe();
	void ConceptHave();


	void ConceptWhat();
	void ConceptWho();
	void ConceptHow();
	void ConceptWhere();
	void ConceptWhy();
	void ConceptWhen();

	void InitMemories();
	
};
#endif