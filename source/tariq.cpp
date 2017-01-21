#include "tariq.h"
#include <algorithm>

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
	this->ConceptMe();
	this->ConceptYou();

	this->ConceptName();
	this->ConceptFirstName();


	this->ConceptBe();
	this->ConceptHave();


	this->ConceptWhat();
	this->ConceptWho();
	this->ConceptHow();
	this->ConceptWhere();
	this->ConceptWhy();
	this->ConceptWhen();

	this->InitMemories();
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
	//if salutations => say hello
	/*
	if what is your name => say My Name Is Riahi
	if(concept == what -> add what)
	if(concept == be -> add "how")
	if(concept == you -> add "I" who)
	if(concept == NAME -> add what == conceptNAME)

	select(WHAT where how = be and who = i)
	*/
	std::vector<std::string> conceptsInString;
	for (int p = 0; p < conceptsIn.size(); p++)
	{
		conceptsInString.push_back(conceptsIn.at(p).getConceptName());
	}
	if (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_SALUTATION") != conceptsInString.end())
	{
		// Element in vector.
		this->startConceptSalutations();
		this->_joy++;

		this->_memories.push_back(Memory("You", "JOY++", "said hello to me", DUNNO, DUNNO, DUNNO));
		//this->_memories.at(0).printtheMemory();
	}
	if ((std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_NAME") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_BE") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_WHAT") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_YOU") != conceptsInString.end()))
	{
		// Element in vector.
		this->startConceptName("I", "CONCEPT_NAME");
		this->_joy++;

		this->_memories.push_back(Memory("You", "JOY++", "asked my name", DUNNO, DUNNO, DUNNO));
		//this->_memories.at(0).printtheMemory();
	}
	if ((std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_FIRSTNAME") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_BE") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_WHAT") != conceptsInString.end())
		&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_YOU") != conceptsInString.end()))
	{
		// Element in vector.
		this->startConceptName("I", "CONCEPT_FIRSTNAME");
		this->_joy++;

		this->_memories.push_back(Memory("You", "JOY++", "asked my firstname", DUNNO, DUNNO, DUNNO));
		//this->_memories.at(0).printtheMemory();
	}
	if (this->sentenceToSay == "")
	{
		this->noConceptFound();
	}
	else
	{
		std::cout << this->sentenceToSay << std::endl;
		//reseting the sentence to say
		this->sentenceToSay = "";

	}
	
}


void Tariq::startConceptName(std::string subject, std::string conceptdude)
{
	for (int i = 0; i < this->_memories.size(); i++)
	{
		if (this->_memories.at(i).getWhat() == conceptdude && this->_memories.at(i).getWho() == subject)
		{
			this->sentenceToSay += this->_memories.at(i).getHow();
		}
	}
}
void Tariq::startConceptSalutations()
{

	for (int i = 0; i < this->_memories.size(); i++)
	{
		if (this->_memories.at(i).getWhat() == "CONCEPT_SALUTATION")
		{
			this->sentenceToSay += this->_memories.at(i).getHow();
		}
	}
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
	this->_memories.push_back(Memory("", "CONCEPT_SALUTATION", "Hi", DUNNO, DUNNO, DUNNO));
}

void Tariq::ConceptName()
{
	std::vector<std::string> nameWords;
	nameWords.push_back("NAME");
	
	this->addConcept(Concepts("CONCEPT_NAME", nameWords));
	this->_memories.push_back(Memory("I", "CONCEPT_NAME", "Riahi", DUNNO, DUNNO, DUNNO));

}
void Tariq::ConceptFirstName()
{
	std::vector<std::string> firstnameWords;
	firstnameWords.push_back("FIRSTNAME");

	this->addConcept(Concepts("CONCEPT_FIRSTNAME", firstnameWords));
	this->_memories.push_back(Memory("I", "CONCEPT_FIRSTNAME", "Tariq", DUNNO, DUNNO, DUNNO));
}
void Tariq::ConceptBe()
{
	std::vector<std::string> beWords;
	beWords.push_back("BE");
	beWords.push_back("AM");
	beWords.push_back("ARE");
	beWords.push_back("IS");

	this->addConcept(Concepts("CONCEPT_BE", beWords));
}
void Tariq::ConceptHave()
{
	std::vector<std::string> haveWords;
	haveWords.push_back("HAVE");
	haveWords.push_back("HAS");

	this->addConcept(Concepts("CONCEPT_HAVE", haveWords));
}

void Tariq::ConceptMe()
{
	std::vector<std::string> meWords;
	meWords.push_back("ME");
	meWords.push_back("I");
	meWords.push_back("MY");
	this->addConcept(Concepts("CONCEPT_ME", meWords));
}
void Tariq::ConceptYou()
{
	std::vector<std::string> youWords;
	youWords.push_back("YOU");
	youWords.push_back("YOUR");

	this->addConcept(Concepts("CONCEPT_YOU", youWords));
}
void Tariq::ConceptWhat()
{
	std::vector<std::string> whatWords;
	whatWords.push_back("WHAT");

	this->addConcept(Concepts("CONCEPT_WHAT", whatWords));
}
void Tariq::ConceptWho()
{
	std::vector<std::string> whoWords;
	whoWords.push_back("WHO");

	this->addConcept(Concepts("CONCEPT_WHO", whoWords));
}
void Tariq::ConceptHow()
{
	std::vector<std::string> howWords;
	howWords.push_back("HOW");

	this->addConcept(Concepts("CONCEPT_HOW", howWords));
}
void Tariq::ConceptWhere()
{
	std::vector<std::string> whereWords;
	whereWords.push_back("WHERE");

	this->addConcept(Concepts("CONCEPT_WHERE", whereWords));
}
void Tariq::ConceptWhy()
{
	std::vector<std::string> whyWords;
	whyWords.push_back("WHY");

	this->addConcept(Concepts("CONCEPT_WHY", whyWords));
}
void Tariq::ConceptWhen()
{
	std::vector<std::string> whenWords;
	whenWords.push_back("WHEN");

	this->addConcept(Concepts("CONCEPT_WHEN", whenWords));
}
void Tariq::InitMemories()
{
	this->_memories.push_back(Memory("I", "CONCEPT_FEELING", "Good", DUNNO, DUNNO, DUNNO));
}
