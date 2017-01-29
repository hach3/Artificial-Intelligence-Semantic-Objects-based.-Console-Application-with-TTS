#ifndef AI_H
#define AI_H

#include <vector>
#include <string>

#include "../Language/adjectives.h"
#include "../Language/nouns.h"
#include "../Language/pronouns.h"
#include "../Language/verbs.h"

#include "../Memory/objects.h"


class AI {
public:
	AI();
	~AI();

	void understandSentence(std::string usersentence);
	
	void saySomething();

	std::string putToUpperCase(std::string userSentence);
	std::string putToLowerCase(std::string sentence);

	
protected:
private:
	Nouns _nouns;
	Pronouns _pronouns;
	Verbs _verbs;

	Objects _objects;

	std::string _sentenceToSay;
};


#endif //AI_H