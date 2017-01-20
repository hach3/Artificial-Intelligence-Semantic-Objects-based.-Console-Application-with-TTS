#include "tariq.h"


Tariq::Tariq() : 
	AI("Tariq")
{
	this->Initialization();
}

Tariq::~Tariq()
{

}

void Tariq::Initialization()
{
	
	this->ConceptSalutations();
	this->addConcept(this->_conceptSalutations);

}


void Tariq::startBehavior(std::string userSentence)
{
	
	//std::cout << "Entering the behavior function" << std::endl;
	std::vector<std::string> conceptInSentence;
	std::vector<std::string> conceptSalutationWords = this->_conceptSalutations.getConceptWords();


	//start extractiong words from the userSentence
	conceptInSentence = this->split(userSentence);
	int conceptFound = 0;
	
	//Si le mot est compris dans les conceptWords d'un des concepts

	for (unsigned int i = 0; i < conceptInSentence.size(); i++)
	{
		
			std::string uppercase = this->putToUpperCase(conceptInSentence.at(i));
			//std::cout << "Checking the word of the sentence : " << uppercase << std::endl;
			for (unsigned int y = 0; y < conceptSalutationWords.size(); y++)
			{
				
				std::string uppercase2 = this->putToUpperCase(conceptSalutationWords.at(y));
				//std::cout << "Checking the word of the concept : " << uppercase2 << std::endl;
				if (uppercase == uppercase2)
				{
					//std::cout << "Concept : "<< uppercase2 << " found" << std::endl;
					//On appelle la fonction startConcept en y faisant passer le conceptName
					this->startConcept(this->_conceptSalutations.getConceptName());
					y = conceptSalutationWords.size(); //stop the loop
					conceptFound++;
				}
			}
	}
	if (conceptFound == 0)
	{
		this->noConceptFound();
	}

}

/*
@TODO
Instead of one conceptName, create a list of string to start adding each concepts between them
*/
void Tariq::startConcept(std::string conceptName)
{
	if (conceptName == "CONCEPT_SALUTATION")
	{
		this->startConceptSalutations();
	}
}
void Tariq::startConceptSalutations()
{
	std::cout << "Hello" << std::endl;
}

void Tariq::noConceptFound()
{
	std::cout << "I don't know about this/these concept/s" << std::endl;
}




void Tariq::ConceptSalutations()
{
	std::vector<std::string> salutationWords;
	salutationWords.push_back("HELLO");
	salutationWords.push_back("HI");
	this->_conceptSalutations = Concepts("CONCEPT_SALUTATION", salutationWords);
	
}

