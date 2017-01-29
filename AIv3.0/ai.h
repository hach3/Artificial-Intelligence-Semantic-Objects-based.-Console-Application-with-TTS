#ifndef AI_H
#define AI_H

#include <vector>
#include <string>

#include "Language/nouns.h"
#include "Language/pronouns.h"
#include "Language/verbs.h"

#include "Memory/objects.h"


class AI {
public:
	AI();
	~AI();
protected:
private:
	Nouns _nouns;
	Pronouns _pronouns;
	Verbs _verbs;

	Objects _objects;
};


#endif //AI_H