#ifndef AI_H
#define AI_H

#include <iostream>
#include <vector>
#include <string>

#include "../Language/adjectives.h"
#include "../Language/nouns.h"
#include "../Language/pronouns.h"
#include "../Language/verbs.h"

#include "../Memory/LongTermMemory/semanticMemory.h"


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
	Adjectives _adjectives;
	semanticMemory _semanticObjects;

	std::string _sentenceToSay;
};


#endif //AI_H