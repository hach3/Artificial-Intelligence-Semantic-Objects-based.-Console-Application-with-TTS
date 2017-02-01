#ifndef ONE_ONES_PRONOUNS_COLLECTION_H
#define ONE_ONES_PRONOUNS_COLLECTION_H

#include "One_Ones_Pronouns.h"
#include "Pronouns_Collection.h"

class One_Ones_Pronouns_Collection : public Pronouns_Collection {
public:
	One_Ones_Pronouns_Collection();
	~One_Ones_Pronouns_Collection();

	void init(void);

	void addPronoun(One_Ones_Pronouns*);

	One_Ones_Pronouns* getPronoun(std::string name);
	One_Ones_Pronouns* getPronoun(int index);


protected:
private:
	std::vector<One_Ones_Pronouns*> _onePronounsList;
};
#endif //ONE_ONES_PRONOUNS_COLLECTION_H