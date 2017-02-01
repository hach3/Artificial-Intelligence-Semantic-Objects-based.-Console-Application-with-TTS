#ifndef YOU_THEY_PRONOUNS_COLLECTION_H
#define YOU_THEY_PRONOUNS_COLLECTION_H
#include "You_They_Pronouns.h"
#include "Pronouns_Collection.h"

class You_They_Pronouns_Collection : public Pronouns_Collection {
public:
	You_They_Pronouns_Collection();

	~You_They_Pronouns_Collection();

	void init(void);

	void addPronoun(You_They_Pronouns*);

	You_They_Pronouns* getPronoun(std::string name);
	You_They_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<You_They_Pronouns*> _youTheyPronounsList;
};
#endif //YOU_THEY_PRONOUNS_COLLECTION_H