#ifndef INDEFINITE_PRONOUNS_H
#define INDEFINITE_PRONOUNS_H

#include "Pronouns.h"

/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/indefinite-pronouns

somebody	someone		something
anybody		anyone		anything
nobody		no one		nothing
everybody	everyone	everything

We use indefinite pronouns to refer to people or things without saying exactly who or what they are. 
We use pronouns ending in -body or -one for people, and pronouns ending in -thing for things:

-We use a singular verb after an indefinite pronoun: Everybody loves Sally.
-When we refer back to an indefinite pronoun we normally use a plural pronoun: Everybody enjoyed the concert. They stood up and clapped.

-We can add -'s to an indefinite pronoun to make a possessive.

-We use indefinite pronouns with no- as the subject in negative clauses (not pronouns with any.) : Nobody came
	We do not use another negative in a clause with nobody, no one or nothing:

-We use else after indefinite pronouns to refer to people or things in addition to the ones we already mentioned : All the family came, but no one else.
*/

class Indefinite_Pronouns : public Pronouns {
public:
	/* Constructor */
	Indefinite_Pronouns(void);
	Indefinite_Pronouns(std::string indefinitePronouns, bool isPeople, bool isThink, double targetRate, bool canBeUseInNegativeForm);
	/* Destructor */
	~Indefinite_Pronouns();
	
	/* Accessors */
	
	bool isPeople(void);
	bool isThing(void);
	double getTargetRate(void);
	bool canBeUseInNegativeForm(void);

	/* Check if else is contain just after the pronoun (something else).. */
	bool checkIfElse(std::string sentence);
	/* Same but put the whole expression (something else) into a string ?*/
	bool checkIfElse(std::string sentence, std::string &expression);

	/* Check if the 's possessive is there, if yes, that means the subject
	or object is the word at the right : somebody's house. We're mainly talking about the house than somebody*/
	bool checkIfSPossessive(std::string sentence);
	bool checkIfSPossessive(std::string sentence, std::string &expression);

protected:
private:
	/* Enable to differency something & somebody for example.*/
	bool _isPeople; //True for somebody, someone..
	bool _isThing; //True for something, anything...
	/* 
	Target Rate creates a ladder that differency the numbers of people or things these pronouns are targetting

	Nobody targetRate is 0.0;
	Somebody targetRate is 0.1 as it targets only one person
	Anybody targetRate is 0.5 as it can be a lonely or multiples targets.
	Everybody targetRate is 1.0 as it target all of the people it's talking about
	*/
	double _targetRate;
	/* 
	In negative sentence, we put no- in front of adverbs (no one, nobody, etc) but it can be used only with nobody, no one or nothing.
	*/
	bool _canBeUseInNegativeForm;
};
#endif //INDEFINITE_PRONOUNS_H