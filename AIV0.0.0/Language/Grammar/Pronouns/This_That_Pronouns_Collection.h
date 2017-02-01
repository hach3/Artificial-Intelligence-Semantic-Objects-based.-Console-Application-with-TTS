#ifndef THIS_THAT_PRONOUNS_COLLECTION_H
#define THIS_THAT_PRONOUNS_COLLECTION_H
#include "This_That_Pronouns.h"
#include "Pronouns_Collection.h"

class This_That_Pronouns_Collection : public Pronouns_Collection {
public:
	This_That_Pronouns_Collection();

	~This_That_Pronouns_Collection();

	void init(void);

	void addPronoun(This_That_Pronouns*);

	This_That_Pronouns* getPronoun(std::string name);
	This_That_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<This_That_Pronouns*> _thisThatPronounsList;
};
#endif //THIS_THAT_PRONOUNS_COLLECTION_H