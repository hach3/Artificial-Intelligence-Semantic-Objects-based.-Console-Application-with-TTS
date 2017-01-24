#include "bot1.h"
#include <iostream>

//#include "voce.h"
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
    this->sentenceToSay = "";
	userSentence = this->putToUpperCase(userSentence);

	std::vector<std::string> conceptInSentence;
	//Spliting the user sentence into a vector
	conceptInSentence = this->split(userSentence);


	std::string wh;
	std::string be;
	std::string subject;
	std::string complement;


   
    /* Si ça commence par un WH*/
	if (this->checkIfQuestionWHBeSC(wh, be, subject, complement, conceptInSentence))
	{
		std::string conceptSubject;
		if (this->_ConceptSubject.checkIfExistInVector(conceptInSentence)){
			conceptSubject = this->_ConceptSubject.getSubjectForMemory(subject);
		}
		else if (this->_ConceptSubjectChild.checkIfExistInVector(conceptInSentence)){
			conceptSubject = this->_ConceptSubjectChild.getSubjectForMemory(subject);
		}
		conceptSubject = this->putToUpperCase(conceptSubject);
		
		std::string conceptComplement;
		if (this->_conceptComplement.checkIfExistByWordInVector(conceptInSentence))
		{
			conceptComplement = this->_conceptComplement.containInto(complement);
		}
		else if (this->_ConceptComplementChild.checkIfExistByWordInVector(conceptInSentence))
		{
			conceptComplement = this->_ConceptComplementChild.containInto(complement);
		}
		std::string whValueInMemory;
		conceptComplement = this->putToUpperCase(conceptComplement);
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue(conceptSubject, "CONCEPT_BE", conceptComplement, wh);

		std::string subjectAnswer;
		subjectAnswer = this->getRealSubject(subject);
		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);

		if (whValueInMemory != "")
		{
			this->sentenceToSay = subjectAnswer
				+ " "
				+ this->putToLowerCase(complement)
				+ " "
				+ be
				+ " "
				+ whValueInMemory;
		}
		else {
			this->sentenceToSay = DUNNO;
		}
	}
	/*Si c'est Who are you / how are you (WH BE Subject)*/
	else if (this->checkIfQuestionWHBeS(wh, be, subject, conceptInSentence))
	{
		std::string conceptSubject;
		if (this->_ConceptSubject.checkIfExistInVector(conceptInSentence))
		{
			//subject = this->putToUpperCase(this->_ConceptSubject.getCurrentConceptWord());
			conceptSubject = this->_ConceptSubject.getSubjectForMemory(subject);
		}
		else if (this->_ConceptSubjectChild.checkIfExistInVector(conceptInSentence))
		{
			//subject = this->putToUpperCase(this->_ConceptSubjectChild.getCurrentConceptWord());
			conceptSubject = this->_ConceptSubjectChild.getSubjectForMemory(subject);
		}

		conceptSubject = this->putToUpperCase(conceptSubject);

		//std::cout << "HAVENT FOUND COMPLEMENT" << std::endl;
		std::string whValueInMemory;
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue(conceptSubject, "CONCEPT_BE", "", wh);

		std::string subjectAnswer;
		subjectAnswer = this->getRealSubject(subject);
		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);

		if (whValueInMemory != "")
		{
			this->sentenceToSay = subjectAnswer
				+ " "
				+ verbAnswer
				+ " "
				+ whValueInMemory;
		}
		else {
			this->sentenceToSay = DUNNO;
		}
	}
	/* WH S C : what is love ?*/
	else if (this->checkIfQuestionWHBeC(wh, be, complement, conceptInSentence))
	{
		std::string conceptComplement;
		if (this->_conceptComplement.checkIfExistByWordInVector(conceptInSentence))
		{
			conceptComplement = this->_conceptComplement.containInto(complement);
		}
		else if (this->_ConceptComplementChild.checkIfExistByWordInVector(conceptInSentence))
		{
			conceptComplement = this->_ConceptComplementChild.containInto(complement);
		}
		std::string whValueInMemory;
		conceptComplement = this->putToUpperCase(conceptComplement);
		wh = this->putToUpperCase(wh);
		whValueInMemory = this->_souvenirs.getWHValue("", "CONCEPT_BE", conceptComplement, wh);

		std::string verbAnswer;
		verbAnswer = this->getRealBe(be);

		if (whValueInMemory != "")
		{
			this->sentenceToSay = complement
				+ " "
				+ be
				+ " "
				+ whValueInMemory;
		}
		else {
			this->sentenceToSay = DUNNO;
		}

	}
	/* Si c'est une expression */
	else if (this->_Expression.checkIfExist(userSentence))
	{
		this->sentenceToSay = this->_Expression.getAnswer(userSentence);
	}

	
	this->saySomething();
}

std::string Bot1::getRealSubject(std::string subject)

{
    std::string subjectAnswer = subject;
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
    return subjectAnswer;

}
std::string Bot1::getRealBe(std::string be)
{
    std::string verbAnswer = be;
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
    return verbAnswer;

}
