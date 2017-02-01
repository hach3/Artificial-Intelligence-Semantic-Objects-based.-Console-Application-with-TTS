#include "indefinite_Pronouns.h"


/* Constructor */
Indefinite_Pronouns::Indefinite_Pronouns(void)
{

}

Indefinite_Pronouns::Indefinite_Pronouns(std::string indefinitePronouns, bool isPeople, bool isThink, double targetRate, bool canBeUseInNegativeForm) :
	Pronouns(indefinitePronouns),
	_isPeople(isPeople),
	_isThing(isThink),
	_targetRate(targetRate),
	_canBeUseInNegativeForm(canBeUseInNegativeForm)
{

}
/* Destructor */
Indefinite_Pronouns::~Indefinite_Pronouns()
{
	delete this;
}

/* Accessors */


bool Indefinite_Pronouns::isPeople(void)
{
	return this->_isPeople;
}

bool Indefinite_Pronouns::isThing(void)
{
	return this->_isThing;
}


double Indefinite_Pronouns::getTargetRate(void)
{
	return this->_targetRate;
}


bool Indefinite_Pronouns::canBeUseInNegativeForm(void)
{
	return this->_canBeUseInNegativeForm;
}


