#include "Confusing_Verbs.h"
Confusing_Verbs::Confusing_Verbs() :
	Verbs()
{

}

Confusing_Verbs::Confusing_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm)
{

}

Confusing_Verbs::Confusing_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm, presentForm, pastForm)
{

}

Confusing_Verbs::~Confusing_Verbs()
{

}