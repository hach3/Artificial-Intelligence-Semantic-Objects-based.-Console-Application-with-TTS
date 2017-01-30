#include "ai.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <sapi.h>
#include "../stdafx.h"
AI::AI() {

}

AI::~AI()
{

}

void AI::understandSentence(std::string usersentence)
{
	/*
	Only handle "what is your name ?" and "what is your car ?" atm. That means WH + Be + Possessive Adj + noun 
	*/
	/*
	have todo smth more general, but for tests and fun, i've done the think below
	*/
	std::string wh;
	std::string possessiveAdjectif;
	std::string verb;
	std::string noun;

	bool isWH = false;
	std::string newSentence;

	std::string answer;


	std::cout << "Start analyzing sentence...." << std::endl;
	Sleep(2000);
	if (this->_pronouns.getInterrogativePronouns().isInterrogativeInSentence(usersentence, newSentence, wh) == true)
	{
		if (this->_verbs.getAuxiliaryVerbs().isBeInSentence(newSentence, verb) == true)
		{
			if (this->_adjectives.getPossessiveAdjectives().isPossessiveSentence(newSentence, possessiveAdjectif) == true)
			{
				if (this->_nouns.getCommonNouns().isCommonInSentence(newSentence, noun) == true)
				{
					isWH = true;					
					this->_semanticObjects.getIs("MYSELF", noun, wh, answer);
					if (answer != "")
						this->_sentenceToSay = "MY " + noun + " IS " + answer + ".";
					else 
						this->_sentenceToSay = "I DON\'T KNOW.";
				}
			}
			//sinon si on trouve pas d'adj possessif, on check s'il y a un nom : what is human ?
			else if (this->_nouns.getCommonNouns().isCommonInSentence(newSentence, noun) == true)
			{
				isWH = true;		
				this->_semanticObjects.getIsA(noun, answer);
				//Si c'est singulier, il faut rajouter "A" devant, ou du moins l'article qui se trouvait dans la phrase.
				if (answer != "")
					this->_sentenceToSay =   "A " + noun + " IS A " + answer + ".";
				else 
					this->_sentenceToSay = "I DON\'T KNOW.";				
			}
		}
	}
	
	if (this->_sentenceToSay == "")
		this->_sentenceToSay = "I DON\'T KNOW ABOUT THIS CONCEPT.";
	this->saySomething();
}

void AI::saySomething()
{
	std::cout << this->_sentenceToSay << std::endl;
	//Let's convert the string to say in wstring
	std::wstring text(this->_sentenceToSay.begin(), this->_sentenceToSay.end());

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


	this->_sentenceToSay = "";
}

std::string AI::putToUpperCase(std::string userSentence)
{
	std::transform(userSentence.begin(), userSentence.end(), userSentence.begin(), toupper);
	return userSentence;
}
std::string AI::putToLowerCase(std::string sentence)
{
	std::transform(sentence.begin(), sentence.end(), sentence.begin(), tolower);
	return sentence;
}