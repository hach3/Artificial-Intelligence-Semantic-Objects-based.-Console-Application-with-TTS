#include "pronouns.h"

Pronouns::Pronouns()
{

}
Pronouns::~Pronouns()
{

}

Demonstrative_Pronoun Pronouns::getDemonstrativePronouns()
{
	return this->_demonstrativePronouns;
}
Indefinite_Pronoun Pronouns::getIndefinitePronouns()
{	
	return this->_indefinitePronouns;
}
Intensive_Pronoun Pronouns::getIntensivePronouns()
{
	return this->_intensivePronouns;
}
Interrogative_Pronoun Pronouns::getInterrogativePronouns()
{
	return this->_interrogativePronouns;
}
Personnal_Pronoun Pronouns::getPersonnalPronouns()
{
	return this->_personnalPronouns;
}
Possessive_Pronoun Pronouns::getPossessivePronouns()
{
	return this->_possessivePronouns;
}
Reciprocal_Pronoun Pronouns::getReciprocalPronouns()
{
	return this->_reciprocalPronouns;
}
Reflexive_Pronoun Pronouns::getReflexivePronouns()
{
	return this->_reflexivePronouns;
}
Relative_Pronoun Pronouns::getRelativePronouns()
{
	return this->_relativePronouns;
}