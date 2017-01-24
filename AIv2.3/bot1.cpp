#include "bot1.h"
#include <iostream>
#include <ctime>
#include <sapi.h>
#include "stdafx.h"
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


    /* Si c'est une expression */
    if(this->_Expression.checkIfExist(userSentence))
    {
        this->sentenceToSay = this->_Expression.getAnswer(userSentence);
    }
    /* Si ça commence par un WH*/
	else if (this->_ConceptWH.checkIfExistInVector(wh, conceptInSentence)) // Si c'est WH
	{
		//std::cout << "Found a WH" << std::endl;
		/* Si la question comporte Be */
		if (this->_conceptBe.checkIfExistInVector(be, conceptInSentence)) // Si c'est Be
		{
			//std::cout << "Found BE" << std::endl;
			/* s'il y a un sujet */
			if (this->_ConceptSubject.checkIfExistInVector(subject, conceptInSentence) ||
				this->_ConceptSubjectChild.checkIfExistInVector(subject, conceptInSentence)) // Si c'est SUJET
			{
				//std::cout << "FOUND A SUBJECT" << std::endl;
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


				/* S'il y a un complement ou un complement de sujet */
				if (this->_conceptComplement.checkIfExistByWordInVector(complement, conceptInSentence) ||
					this->_ConceptComplementChild.checkIfExistByWordInVector(complement, conceptInSentence)) // Si c'est COMPLEMENT
				{
					//std::cout << "FOUND A COMPLEMENT" << std::endl;
				

					std::string conceptComplement;
					if (this->_conceptComplement.checkIfExistByWordInVector(conceptInSentence))
					{
						//complement = this->putToUpperCase(this->_conceptComplement.getCurrentConceptWord());
						conceptComplement = this->_conceptComplement.containInto(complement);
						//std::cout << "The complement is master" << std::endl;
					}
					else if (this->_ConceptComplementChild.checkIfExistByWordInVector(conceptInSentence))
					{
						//complement = this->putToUpperCase(this->_ConceptComplementChild.getCurrentConceptWord());
						conceptComplement = this->_ConceptComplementChild.containInto(complement);
						//std::cout << "The complement is slave" << std::endl;
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
						this->sentenceToSay = "I don\'t know...";
					}

				}
				else 
				{
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
    this->sentenceToSay = this->putToLowerCase(this->sentenceToSay);
    std::cout << this->sentenceToSay << std::endl;

	//Let's convert the string to say in wstring
	std::wstring text(this->sentenceToSay.begin(), this->sentenceToSay.end());

	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
	{

	}
	else
	{
		HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
		if (SUCCEEDED(hr))

		{
			
			hr = pVoice->Speak(text.c_str(), 0, NULL);
			pVoice->Release();
			pVoice = NULL;
		}

		::CoUninitialize();
		
	}
	
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