#include "be_Verb.h"

Be_Verb::Be_Verb() : 
	Verbs()
{

}
Be_Verb::Be_Verb(std::string verbalBase, std::string ingForm,
	std::string _pastForm, std::string pastParticipate,
	std::vector<std::string> simplePresent, std::vector<std::string> simplePast) :
	Verbs(verbalBase, ingForm, _pastForm, pastParticipate, simplePresent, simplePast)
{

}
Be_Verb::~Be_Verb()
{

}