#include "Phrasal_Verbs.h"
Phrasal_Verbs::Phrasal_Verbs() :
	Verbs()
{

}

Phrasal_Verbs::Phrasal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm)
{

}

Phrasal_Verbs::Phrasal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm, presentForm, pastForm)
{

}

Phrasal_Verbs::~Phrasal_Verbs()
{

}