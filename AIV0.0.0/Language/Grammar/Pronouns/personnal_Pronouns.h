#ifndef PERSONNAL_PRONOUNS_H
#define PERSONNAL_PRONOUNS_H
#include "Pronouns.h"

/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/personal-pronouns
Pronouns are words we use in the place of a full noun.

Subject	Object
I		me
you		you
he		him
she		her
it		it
we		us
you		you
they	them

Subject pronouns are subject of the verb.


Object pronouns are used as :
-Objet of the verb : I can see you; Can you help me ?
-After prepositions : She's waiting for me; Give it to him.

*/

class Personnal_Pronouns : public Pronouns {
public:
	Personnal_Pronouns();
	Personnal_Pronouns(std::string _name, bool isSubject, bool isObject, bool isPlural, int person);
	~Personnal_Pronouns();



	bool isSubject();
	bool isObject();
	bool isPlural();
	int getPerson();

protected:
private:

	bool _isSubject;
	bool _isObject;
	bool _isPlural;
	int _person; // 1er, 2eme, 3eme
	
};
#endif //PERSONNAL_PRONOUNS_H