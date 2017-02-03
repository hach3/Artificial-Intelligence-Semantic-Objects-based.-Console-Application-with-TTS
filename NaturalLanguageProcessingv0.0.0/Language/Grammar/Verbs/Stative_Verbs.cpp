#include "Stative_Verbs.h"
Stative_Verbs::Stative_Verbs() :
	Verbs()
{

}

Stative_Verbs::Stative_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm)
{

}

Stative_Verbs::Stative_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm, presentForm, pastForm)
{

}

Stative_Verbs::~Stative_Verbs()
{

}