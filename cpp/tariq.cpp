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
	this->_love = 0;
	this->_joy = 50;
	this->_surprise = 0;
	this->_anger = 0;
	this->_sadness = 0;
	this->_fear = 0;


	this->ConceptSalutations();
}


void Tariq::startBehavior(std::string userSentence)
{
	
	//std::cout << "Entering the behavior function" << std::endl;
	std::vector<std::string> conceptInSentence;


	//start extractiong words from the userSentence
	conceptInSentence = this->split(userSentence);
	
	//Si le mot est compris dans les conceptWords d'un des concepts


	/*
	Compare the concepts in conceptInSentence with all the concept in the vector _concepts
	Si un concept est egal, je le rajoute aux concepts en cours, par exemple vector(conceptSalutations)
	Je fais passer les concepts a startConcept 

	
	*/
	std::vector<Concepts> conceptFoundInSentence;
	for (int i = 0; i < conceptInSentence.size(); i++)
	{
		//std::cout << "Starting checking every word in the sentence : " << conceptInSentence.at(i) << std::endl;
		for (int y = 0; y < this->_concepts.size(); y++)
		{
			
			std::vector<std::string> conceptWordsTO = this->_concepts.at(y).getConceptWords();
			//std::cout << "Comparing concepts : " << conceptInSentence.at(i) << std::endl;
			for (int w = 0; w < conceptWordsTO.size(); w++)
			{
				//std::cout << "Comparing concepts to word : " << conceptWordsTO.at(w) << std::endl;
				if (this->putToUpperCase(conceptInSentence.at(i)) == this->putToUpperCase(conceptWordsTO.at(w)))
				{
					//std::cout << "Found a concept : " << conceptInSentence.at(i) << std::endl;
					//On le rajoute dans le vector @CONCEPTS TO HANDLE
					//Le rajouter uniquement s'il y est pas déja
					int totalfound = 0;
					//std::cout << "Starting checking if the concept is already saved : " << conceptInSentence.at(i) << std::endl;
					for (int x = 0; x < conceptFoundInSentence.size(); x++)
					{
						
						if (conceptFoundInSentence.at(x).getConceptName() == this->_concepts.at(y).getConceptName())
						{
							totalfound++;
							//std::cout << "The concept is already saved" << std::endl;
						}
					}
					if (totalfound == 0)
					{
						conceptFoundInSentence.push_back(this->_concepts.at(y));
						//std::cout << "Saving the concept : " << this->_concepts.at(y).getConceptName() << std::endl;
					}
					
				}
			}
			
			
		}
	}
	if (conceptFoundInSentence.size() > 0)
	{
		//std::cout << "Starting the concept : " << std::endl;
		this->startConcept(conceptFoundInSentence);
	}
	else
	{
		this->noConceptFound();
	}
	
	
	
}

/*
@TODO
Instead of one conceptName, create a list of string to start adding each concepts between them
*/
void Tariq::startConcept(std::vector<Concepts> conceptsIn)
{
	for (int i = 0; i < conceptsIn.size(); i++)
	{
		
		if (conceptsIn.at(i).getConceptName() == "CONCEPT_SALUTATION")
		{
			this->startConceptSalutations();
			this->_joy++;
			
			this->_memories.push_back(Memory("You", "said hello to me", "", "", "", ""));
			//this->_memories.at(0).printtheMemory();
		}
	}
	std::cout << this->sentenceToSay << std::endl;
	//reseting the sentence to say
	this->sentenceToSay = "";
}

void Tariq::startConceptSalutations()
{
	this->sentenceToSay += "Hi ";
}

void Tariq::noConceptFound()
{
	this->sentenceToSay += "So many concepts are still unknown to me.";
	std::cout << this->sentenceToSay << std::endl;
	//reseting the sentence to say
	this->sentenceToSay = "";
}




void Tariq::ConceptSalutations()
{
	std::vector<std::string> salutationWords;
	salutationWords.push_back("HELLO");
	salutationWords.push_back("HI");
	salutationWords.push_back("BONJOUR");
	salutationWords.push_back("SALUT");
	this->addConcept(Concepts("CONCEPT_SALUTATION", salutationWords));
	
}

