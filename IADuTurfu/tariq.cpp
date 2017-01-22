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
	this->_asking = false;
	this->_answering = true;

	this->InitConcepts();
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
	std::vector<std::string> conceptWordsTO;
	bool find;
	for (int i = 0; i < conceptInSentence.size(); i++)
	{
		find = false;
		//std::cout << "Starting checking every word in the sentence : " << conceptInSentence.at(i) << std::endl;
		for (int y = 0; y < this->_concepts.size(); y++)
		{
			
			conceptWordsTO = this->_concepts.at(y).getConceptWords();
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
						this->_relatedWordToConcept.push_back(this->putToUpperCase(conceptInSentence.at(i)));
						//std::cout << "Saving the concept : " << this->_concepts.at(y).getConceptName() << std::endl;
						find = true;
					}
					
				}
			
			}
			
			
		}
		if (find == false)
		{
			this->_wordsNoConceptString.append(this->putToUpperCase(conceptInSentence.at(i)));
		}
	}

	//check all the words that are not in the concept lists


	//
	if (conceptFoundInSentence.size() > 0)
	{
		//std::cout << "Starting the concept : " << std::endl;
		this->startConcept(conceptFoundInSentence);
	}
	else
	{
		this->noConceptFound();
	}
	
	this->_wordsNoConceptString = "";
	
}

/*
@TODO
Instead of one conceptName, create a list of string to start adding each concepts between them
*/
void Tariq::startConcept(std::vector<Concepts> conceptsIn)
{
	
	std::vector<std::string> conceptsInString;
	std::string getStockingConcept;
	std::string stockingConcept;


	this->_currentConcepts.clear();
	for (int p = 0; p < conceptsIn.size(); p++)
	{
		conceptsInString.push_back(conceptsIn.at(p).getConceptName());
		
	}


	
		//std::cout << "Trying to answer smth" << std::endl;
		for (int z = 0; z < conceptsInString.size(); z++)
		{
			this->_currentConcepts.push_back(conceptsInString.at(z));
			
		}
		if (conceptsInString.size() == 1)
		{
			this->startConceptToDo("", conceptsInString.at(0));
		}

		/* Answer to question "what is [something]" by looking in the memory the "how" is something where WHAT = [concept_something]*/
		else if ((std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_BE") != conceptsInString.end())
			&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_WHAT") != conceptsInString.end())
			&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_YOU") != conceptsInString.end()))
		{
			
			for (int a = 0; a < conceptsInString.size(); a++)
			{
				if (conceptsInString.at(a) != "CONCEPT_BE" && conceptsInString.at(a) != "CONCEPT_WHAT" && conceptsInString.at(a) != "CONCEPT_YOU")
				{
					stockingConcept = conceptsInString.at(a);
				}
			}
			this->startConceptToDo("I", stockingConcept);
		
		}
		else if ((std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_BE") != conceptsInString.end())
			&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_WHAT") != conceptsInString.end())
			&& (std::find(conceptsInString.begin(), conceptsInString.end(), "CONCEPT_ME") != conceptsInString.end()))
		{
			
			for (int a = 0; a < conceptsInString.size(); a++)
			{
				if (conceptsInString.at(a) != "CONCEPT_BE" && conceptsInString.at(a) != "CONCEPT_WHAT" && conceptsInString.at(a) != "CONCEPT_ME")
				{
					stockingConcept = conceptsInString.at(a);
				}
			}
			this->startConceptToDo("You", stockingConcept);
	
		}

		//std::cout << "Trying to ask smth" << std::endl;
		else if ((std::find(this->_currentConcepts.begin(), this->_currentConcepts.end(), "CONCEPT_BE") != this->_currentConcepts.end())
			&& (std::find(this->_currentConcepts.begin(), this->_currentConcepts.end(), "CONCEPT_ME") != this->_currentConcepts.end()))
		{
			//std::cout << "Found a question with be & you" << std::endl;
			for (int e = 0; e < this->_currentConcepts.size(); e++)
			{
				if (this->_currentConcepts.at(e) != "CONCEPT_BE" && this->_currentConcepts.at(e) != "CONCEPT_ME")
				{
					getStockingConcept = this->_currentConcepts.at(e);
			
					
					
				}
			}
			for (int r = 0; r < this->_memories.size(); r++)
			{
				//std::cout << "Checking if i already know the answer ?" << std::endl;
				if (this->_memories.at(r).getWhat() == getStockingConcept && this->_memories.at(r).getWho() == "You")
				{
					this->_memories.erase(this->_memories.begin() + r);
					this->_memories.push_back(Memory("You", getStockingConcept, this->_wordsNoConceptString, DUNNO, DUNNO, DUNNO));
					r = this->_memories.size();
					
				}
			}
			this->startConceptToDo("You", getStockingConcept);
	
		}
	
	
	

	/* Say the default sentence */
	if (this->sentenceToSay == "")
	{
		this->noConceptFound();
	}
	else //Say the sentence
	{
		std::cout << this->sentenceToSay << std::endl;
		//reseting the sentence to say
		this->sentenceToSay = "";
	}
	
}

/* Say the "how" from the memory of a concept...*/
void Tariq::startConceptToDo(std::string subject, std::string conceptdude)
{



	for (int i = 0; i < this->_memories.size(); i++)
	{
		if (this->_memories.at(i).getWhat() == conceptdude && this->_memories.at(i).getWho() == subject)
		{
			this->sentenceToSay += this->_memories.at(i).getHow();
		
		}
		if (this->_memories.at(i).getWhat() == conceptdude && this->_memories.at(i).getWho() == "You" && this->_memories.at(i).getHow() == "")
		{
			this->sentenceToSay += "I don\'t know your name. Can you tell me about ?";
		
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

void Tariq::InitConcepts()
{
	
	/* CONCEPT SALUTATIONS */
	std::vector<std::string> salutationWords;
	salutationWords.push_back("HELLO");
	salutationWords.push_back("HI");
	salutationWords.push_back("BONJOUR");
	salutationWords.push_back("SALUT");
	this->addConcept(Concepts("CONCEPT_SALUTATION", salutationWords));
	this->_memories.push_back(Memory("", "CONCEPT_SALUTATION", "Hi", DUNNO, DUNNO, DUNNO));


	/* CONCEPT NAME*/
	std::vector<std::string> nameWords;
	nameWords.push_back("NAME");

	this->addConcept(Concepts("CONCEPT_NAME", nameWords));
	this->_memories.push_back(Memory("I", "CONCEPT_NAME", "Riahi", DUNNO, DUNNO, DUNNO));
	this->_memories.push_back(Memory("You", "CONCEPT_NAME", "", DUNNO, DUNNO, DUNNO));

	/* CONCEPT FIRSTNAME*/
	std::vector<std::string> firstnameWords;
	firstnameWords.push_back("FIRSTNAME");

	this->addConcept(Concepts("CONCEPT_FIRSTNAME", firstnameWords));
	this->_memories.push_back(Memory("I", "CONCEPT_FIRSTNAME", "Tariq", DUNNO, DUNNO, DUNNO));
	this->_memories.push_back(Memory("You", "CONCEPT_FIRSTNAME", "", DUNNO, DUNNO, DUNNO));

	/* CONCEPT BE*/
	std::vector<std::string> beWords;
	beWords.push_back("BE");
	beWords.push_back("AM");
	beWords.push_back("ARE");
	beWords.push_back("IS");

	this->addConcept(Concepts("CONCEPT_BE", beWords));


	/* CONCEPT HAVE*/
	std::vector<std::string> haveWords;
	haveWords.push_back("HAVE");
	haveWords.push_back("HAS");

	this->addConcept(Concepts("CONCEPT_HAVE", haveWords));

	/* CONCEPT ME*/
	std::vector<std::string> meWords;
	meWords.push_back("ME");
	meWords.push_back("I");
	meWords.push_back("MY");
	this->addConcept(Concepts("CONCEPT_ME", meWords));


	/* CONCEPT YOU*/
	std::vector<std::string> youWords;
	youWords.push_back("YOU");
	youWords.push_back("YOUR");

	this->addConcept(Concepts("CONCEPT_YOU", youWords));


	/* CONCEPT WHAT*/
	std::vector<std::string> whatWords;
	whatWords.push_back("WHAT");

	this->addConcept(Concepts("CONCEPT_WHAT", whatWords));

	/* CONCEPT WHO*/
	std::vector<std::string> whoWords;
	whoWords.push_back("WHO");

	this->addConcept(Concepts("CONCEPT_WHO", whoWords));

	/* CONCEPT HOW*/
	std::vector<std::string> howWords;
	howWords.push_back("HOW");

	this->addConcept(Concepts("CONCEPT_HOW", howWords));

	/* CONCEPT WHERE*/
	std::vector<std::string> whereWords;
	whereWords.push_back("WHERE");

	this->addConcept(Concepts("CONCEPT_WHERE", whereWords));

	/* CONCEPT WHY*/
	std::vector<std::string> whyWords;
	whyWords.push_back("WHY");

	this->addConcept(Concepts("CONCEPT_WHY", whyWords));

	/* CONCEPT WHEN*/
	std::vector<std::string> whenWords;
	whenWords.push_back("WHEN");

	this->addConcept(Concepts("CONCEPT_WHEN", whenWords));
}


