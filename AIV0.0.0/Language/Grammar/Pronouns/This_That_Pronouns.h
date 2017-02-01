#ifndef THIS_THAT_PRONOUNS_H
#define THIS_THAT_PRONOUNS_H
#include "Pronouns.h"
/*
Source : https://learnenglish.britishcouncil.org/en/english-grammar/pronouns/that-these-and-those

This - These
That - Those

Why do we use this and these?
We use this (singular) and these (plural) as pronouns:
- to talk about people or things near us: This is a nice cup of tea.
- to introduce people: This is Janet.
- to introduce ourselves to begin a conversation on the phone: Hello, this is David, Can I speak to Sally?

Why do we use that and those?
We use that (singular) and those (plural):
- to talk about things that are not near us: What’s that?

- We also use that to refer back to something someone said or did: - Shall we go to the cinema?

this, these, that, those with nouns
We also use this, these, that and those with nouns to show proximity
We use this and these for people or things near us: We have lived in this house for twenty years.
… and that and those for people or things that are not near us: Who are those people?

*/
class This_That_Pronouns : public Pronouns {
public:
	This_That_Pronouns();
	This_That_Pronouns(std::string name, bool isPlural, bool isFar);
	~This_That_Pronouns();

	bool isPlural(void);
	bool isFar(void);

protected:
private:
	bool _isPlural;
	bool _isFar;
};
#endif //THIS_THAT_PRONOUNS_H