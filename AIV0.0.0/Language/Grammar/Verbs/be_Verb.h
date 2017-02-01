#ifndef BE_VERB_H
#define BE_VERB_H
#include "Verbs.h"

class Be_Verb : public Verbs {
public:
	Be_Verb();
	Be_Verb(std::string verbalBase, std::string ingForm,
		std::string _pastForm, std::string pastParticipate,
		std::vector<std::string> simplePresent, std::vector<std::string> simplePast);
	~Be_Verb();
protected:
private:
};

#endif //BE_VERB_H