#ifndef INDEFINITE_PRONOUNS_COLLECTION_H
#define INDEFINITE_PRONOUNS_COLLECTION_H
#include "indefinite_Pronouns.h"
#include "Pronouns_Collection.h"

/*
This is a collection that'll pack all the indefinite pronouns. It also has some method like :
-Check if else follows the pronoun (something else) which gives a particular sense to the pronoun
-Check if there're the 's possession
-Check if it's object or subject in the sentence (For that, has to know verbs) -> maybe do it in a mother collection like language.h ?

First:
check if the s possessive is there, that means the group is composed by the pronoun + the noun just after.
else, check if else, that means the group is composed by the pronoun + else : somebody else
Then check if it's object or subject.
*/

class Indefinite_Pronouns_Collection : public Pronouns_Collection {
public:
	Indefinite_Pronouns_Collection(void);
	~Indefinite_Pronouns_Collection(void);

	/* Create the basics indefinite pronouns */
	void init(void);

	/* Add a pronoun in the list */
	void addPronoun(Indefinite_Pronouns* pronoun);

	/* Return the indefinite pronoun */
	Indefinite_Pronouns* getPronoun(std::string pronounName);
	Indefinite_Pronouns* getPronoun(int index);

	


protected:
private:
	std::vector<Indefinite_Pronouns*> _indefinitePronounsList;
};

#endif //INDEFINITE_PRONOUNS_COLLECTION_H