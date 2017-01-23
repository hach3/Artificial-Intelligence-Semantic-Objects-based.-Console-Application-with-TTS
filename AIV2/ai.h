#ifndef AI_H
#define AI_H

#include <string>
#include <vector>
//We include all the collectioner of concepts and memory
//Memory
#include "CollMemory.h"

//Concepts
#include "CollConceptAux.h"
#include "CollConceptBe.h"
#include "CollConceptComplement.h"
#include "CollConceptComplementChild.h"
#include "CollConceptSubject.h"
#include "CollConceptSubjectChild.h"
#include "CollConceptVerb.h"
#include "CollConceptWH.h"
#include "CollExpression.h"

#define DUNNO "I don\'t know much about that."


class AI {
public:
    AI();
    ~AI();

    /* Init all the concepts of Tariq*/
	void Initialization();

protected:
	//Declaring every collectionners for memory
	CollMemory _souvenirs;

	//And for concepts
	CollConceptAux _conceptAux;
	CollConceptBe _conceptBe;
	CollConceptComplement _conceptComplement;
	CollConceptComplementChild _ConceptComplementChild;
	CollConceptSubject _ConceptSubject;
	CollConceptSubjectChild _ConceptSubjectChild;
	CollConceptVerb _ConceptVerb;
	CollConceptWH _ConceptWH;
	CollConceptExpression _Expression;


	/* Turn a string to uppercase and return it. I use it to turn the userSentence concepts to uppercase to compare them with the AI's concepts*/
	std::string putToUpperCase(std::string s);

	/* Extract the word of a string in a vector and return it*/
	std::vector<std::string> split(const std::string& s);


	std::string sentenceToSay;
private:
   

};


#endif // AI_H

