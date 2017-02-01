#ifndef REFLEXIVE_PRONOUNS_H
#define REFLEXIVE_PRONOUNS_H
#include "Pronouns.h"
/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/reflexive-pronouns


The reflexive pronouns are:

Singular:	myself - yourself - himself - herself - itself
Plural:	ourselves - yourselves - themselves

When we use a reflexive pronoun
We use a reflexive pronoun:

• as a direct object when the object is the same as the subject of the verb: I am teaching myself to play the piano.

• as indirect object when the indirect object is the same as the subject of the verb: We’ve brought ourselves something to eat.

• as the object of a preposition when the object refers to the subject of the clause: They had to cook for themselves.

Warning
But we use personal pronouns, not reflexives, after prepositions of place... He had a suitcase beside him.

and after with when it means "accompanied by": She had a few friends with her.

We use a reflexive pronoun...

• with the preposition by when we want to show that someone did something alone and/or without any help: He lived by himself in an enormous house.

• to emphasise the person or thing we are referring to: Kendal itself is quite a small town.
We often put the reflexive pronoun at the end of the clause when we are using it for emphasis: I baked the bread myself.
*/

class Reflexive_Pronouns : public Pronouns {
public:
	Reflexive_Pronouns();
	Reflexive_Pronouns(std::string reflexive, bool isPlural, int person);
	~Reflexive_Pronouns();

	bool isPlural();
	int getPerson();
protected:
private:

	bool _isPlural;
	int _person; // 1er, 2eme, 3eme
};
#endif //REFLEXIVE_PRONOUNS_H