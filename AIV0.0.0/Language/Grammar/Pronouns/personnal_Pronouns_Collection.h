#ifndef PERSONNAL_PRONOUNS_COLLECTION_H
#define PERSONNAL_PRONOUNS_COLLECTION_H

#include "personnal_Pronouns.h"
#include "Pronouns_Collection.h"

class Personnal_Pronouns_Collection : public Pronouns_Collection {
public:
	Personnal_Pronouns_Collection();
	~Personnal_Pronouns_Collection();

	void init(void);


	void addPronoun(Personnal_Pronouns*);

	Personnal_Pronouns* getPronoun(std::string name);
	Personnal_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<Personnal_Pronouns*> _personnalPronounList;
};

#endif //PERSONNAL_PRONOUNS_COLLECTION_H