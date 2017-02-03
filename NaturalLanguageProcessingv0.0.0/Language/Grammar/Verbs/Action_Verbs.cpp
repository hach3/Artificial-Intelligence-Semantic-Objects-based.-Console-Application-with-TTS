#include "Action_Verbs.h"
Action_Verbs::Action_Verbs() :
	Verbs()
{

}

Action_Verbs::Action_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm)
{

}

Action_Verbs::Action_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Verbs(value, wordType, type, infinitiveForm, ingForm, passiveForm, participateForm, presentForm, pastForm)
{

}

Action_Verbs::~Action_Verbs()
{

}