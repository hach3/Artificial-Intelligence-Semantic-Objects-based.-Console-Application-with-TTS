#include "verbs.h"

Verbs::Verbs()
{

}
Verbs::~Verbs()
{

}

Action_Verb Verbs::getActionVerbs()
{
	return this->_actionVerbs;
}
Auxiliary_Verb Verbs::getAuxiliaryVerbs()
{
	return this->_auxiliaryVerbs;
}
Modal_Verb Verbs::getModalVerbs()
{
	return this->_modalVerbs;
}
Phrasal_Verb Verbs::getPhrasalVerbs()
{
	return this->_phrasalVerbs;
}
Stative_Verb Verbs::getStativeVerbs()
{
	return this->_stativeVerbs;
}
