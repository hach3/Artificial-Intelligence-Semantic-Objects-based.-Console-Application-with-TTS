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
	
	std::string wh;
	std::string possessiveAdjectif;
	std::string verb;
	std::string noun;

	bool isWH = false;
	std::string newSentence;
	std::cout << "Start analyzing sentence." << std::endl;
	if (this->_pronouns.getInterrogativePronouns().isInterrogativeInSentence(usersentence, newSentence, wh) == true)
	{
	//	std::cout << "Found an interrogative pronoun" << std::endl;
		//Si on trouve be dans la nouvelle sentence
		if (this->_verbs.getAuxiliaryVerbs().isBeInSentence(newSentence, verb) == true)
		{
		//	std::cout << "Found be" << std::endl;
			//Si on trouve un adjectif possessif
			if (this->_adjectives.getPossessiveAdjectives().isPossessiveSentence(newSentence, possessiveAdjectif) == true)
			{
			//	std::cout << "Found a possessive adjective" << std::endl;
				//Si on trouve un nom
				if (this->_nouns.getCommonNouns().isCommonInSentence(newSentence, noun) == true)
				{
					//std::cout << "Found an common noun" << std::endl;
					isWH = true;
					//this->_sentenceToSay = wh + " " + verb + " " + possessiveAdjectif + " " + noun + "?";
					//this->saySomething();
				}
			}
				
		}
	}
	/*
	have todo smth more general, but for tests and fun, i've done the think below
	*/
	std::string answer;
	answer = this->_objects.getWHAnswer("MYSELF", "IS", noun, wh);
	this->_sentenceToSay = "MY " + noun + " IS " + answer + ".";
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