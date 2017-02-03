#include "Verbs.h"

Verbs::Verbs(void) :
	Words()
{

}
Verbs::Verbs(string value, WORDS wordType, WORDS_TYPE type) :
	Words(value, wordType, type)
{
	
}
Verbs::Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm) :
	Words(value, wordType, type),
	_infinitiveForm(infinitiveForm),
	_ingForm(ingForm),
	_passiveForm(passiveForm),
	_participateForm(participateForm)
{

}
Verbs::Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
	string ingForm, string passiveForm, string participateForm,
	vector<string> presentForm, vector<string> pastForm) :
	Words(value, wordType, type),
	_infinitiveForm(infinitiveForm),
	_ingForm(ingForm),
	_passiveForm(passiveForm),
	_participateForm(participateForm),
	_presentTense(presentForm),
	_pastTense(pastForm)
{

}
Verbs::~Verbs(void)
{

}


string Verbs::getInfinitiveForm()
{
	return this->_infinitiveForm;
}
string Verbs::getIngForm()
{
	return this->_ingForm;
}
string Verbs::getPassiveForm()
{
	return this->_passiveForm;
}
string Verbs::getParticipateForm()
{
	return this->_participateForm;
}

vector<string> Verbs::getPresentForm()
{
	return this->_presentTense;
}
vector<string> Verbs::getPastForm()
{
	return this->_pastTense;
}