#include "Auxiliary_Verbs.h"
Auxiliary_Verbs::Auxiliary_Verbs() :
	Verbs()
{

}

Auxiliary_Verbs::Auxiliary_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm)
{

}

Auxiliary_Verbs::Auxiliary_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm, presentForm, pastForm)
{

}

Auxiliary_Verbs::~Auxiliary_Verbs()
{

}
