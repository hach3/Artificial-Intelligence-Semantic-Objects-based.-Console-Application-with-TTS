#include "bot1.h"
#include <iostream>

Bot1::Bot1()
{

}

Bot1::~Bot1()
{

}
/*
StartBehavior get the user msg, extract each word and create a list of conceptsName
*/
void Bot1::startBehavior(std::string userSentence)
{
	std::vector<std::string> conceptInSentence;

	//Spliting the user sentence into a vector
	conceptInSentence = this->split(userSentence);

	/*
	If it's a question
	that means the first word is either have, either aux, either WH
	let's start with WH
	Si le premier mot est un WH, on recupere le concept en question.
		concept = "CONCEPT_WHAT"; row what
		Si le second mot est is
			concept="CONCEPT_BE"; //concept_verb

	if le premier mot est un WH
		concept1 = CONCEPT_WHAT
		concept2 = CONCEPT_BE
		concept3 = CONCEPT_SUBJECT_CHILD
		concept4 = CONCEPT_NAME

	*/
	for (int a = 0; a < conceptInSentence.size(); a++)
	{
		conceptInSentence.at(a) = this->putToUpperCase(conceptInSentence.at(a));
	}

	if (this->_ConceptWH.checkIfWordIsWH(conceptInSentence.at(0))) // Si c'est WH
	{
		//std::cout << "Found a WH" << std::endl;
		if (this->_conceptBe.checkIfExist(conceptInSentence.at(1))) // Si c'est Be
		{
			//std::cout << "Found BE" << std::endl;
			if (this->_ConceptSubject.checkIfExist(conceptInSentence.at(2)) || 
				this->_ConceptSubjectChild.checkIfExist(conceptInSentence.at(2))) // Si c'est SUJET
			{
				//std::cout << "FOUND A SUBJECT" << std::endl;
				if (this->_conceptComplement.checkIfExistByWord(conceptInSentence.at(3)) ||
					this->_ConceptComplementChild.checkIfExistByWord(conceptInSentence.at(3))) // Si c'est COMPLEMENT
				{
					//std::cout << "FOUND A COMPLEMENT" << std::endl;
					std::string wh = this->putToUpperCase(conceptInSentence.at(0));
					std::string be = this->putToUpperCase(conceptInSentence.at(1));
					std::string subject = this->putToUpperCase(conceptInSentence.at(2));
					std::string complement = this->putToUpperCase(conceptInSentence.at(3));

					std::string conceptWH = this->_ConceptWH.getName(wh);
					std::string conceptBe = "CONCEPT_BE";
					std::string conceptSubject;
					if (this->_ConceptSubject.checkIfExist(conceptInSentence.at(2)))
					{
						conceptSubject = this->_ConceptSubject.getSubjectByName(subject);
					}
					else if (this->_ConceptSubjectChild.checkIfExist(conceptInSentence.at(2)))
					{
						conceptSubject = this->_ConceptSubjectChild.getSubjectForMemory(subject);
					}

					std::string conceptComplement;
					if (this->_conceptComplement.checkIfExistByWord(conceptInSentence.at(3)))
					{
						conceptComplement = this->_conceptComplement.containInto(complement);
						//std::cout << "The complement is master" << std::endl;
					}
					else if (this->_ConceptComplementChild.checkIfExistByWord(conceptInSentence.at(3)))
					{
						conceptComplement = this->_ConceptComplementChild.containInto(complement);
						//std::cout << "The complement is slave" << std::endl;
					}
					
					std::string whValueInMemory;

					conceptSubject = this->putToUpperCase(conceptSubject);
					conceptBe = this->putToUpperCase(conceptBe);
					conceptComplement = this->putToUpperCase(conceptComplement);
					wh = this->putToUpperCase(wh);
					//std::cout << "Looking in the memory for :" << conceptSubject << std::endl;
					//std::cout << "Subject :" << conceptSubject << std::endl;
					//std::cout << "conceptBe" << conceptBe << std::endl;
					//std::cout << "conceptComplement :" << conceptComplement << std::endl;
					//std::cout << "wh :" << wh << std::endl;
					whValueInMemory = this->_souvenirs.getWHValue(conceptSubject, conceptBe, conceptComplement, wh);


					
					/*
					Now that i got the wh value, have to build the answer

					subject + complement + be + whatValue
					if subject = I || You, on met You || I
					Below is a temporary algorithm, it will be handle by classes next
					*/
					std::string subjectAnswer;
					if (subject == "I")
					{
						subjectAnswer = "You";
					}
					else if (subject == "YOU")
					{
						subjectAnswer = "I";
					}
					if (subject == "YOUR")
					{
						subjectAnswer = "My";
					}
					else if (subject == "MY")
					{
						subjectAnswer = "Your";
					}
					std::string verbAnswer;
					if (be == "ARE")
					{
						verbAnswer = "am";
					}
					else if (be == "AM")
					{
						verbAnswer = "are";
					}
					else {
						verbAnswer = be;
					}
					if (whValueInMemory != "")
					{
						this->sentenceToSay = subjectAnswer + " " + complement + " " + be + " " + whValueInMemory;
					}
					else {
						this->sentenceToSay = "I don\'t know...";
					}
					
				}
			}
		}
	}
	if (this->sentenceToSay == "")
	{
		this->sentenceToSay = "So many concepts are still unknown to me...";
	}

	std::cout << this->sentenceToSay << std::endl;
}

