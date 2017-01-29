#pragma once
#ifndef PRONOUNS_H
#define PRONOUNS_H

#include "Pronouns/demonstrative.h"
#include "Pronouns/indefinite.h"
#include "Pronouns/intensive.h"
#include "Pronouns/interrogative.h"
#include "Pronouns/personnal.h"
#include "Pronouns/possessive.h"
#include "Pronouns/reciprocal.h"
#include "Pronouns/reflexive.h"
#include "Pronouns/relative.h"

class Pronouns {
public:
	Pronouns();
	~Pronouns();
protected:
private:
	Demonstrative_Pronoun _demonstrativePronouns;
	Indefinite_Pronoun _indefinitePronouns;
	Intensive_Pronoun _intensivePronouns;
	Interrogative_Pronoun _interrogativePronouns;
	Personnal_Pronoun _personnalPronouns;
	Possessive_Pronoun _possessivePronouns;
	Reciprocal_Pronoun _reciprocalPronouns;
	Reflexive_Pronoun _reflexivePronouns;
	Relative_Pronoun _relativePronouns;
	
};


#endif //PRONOUNS_H