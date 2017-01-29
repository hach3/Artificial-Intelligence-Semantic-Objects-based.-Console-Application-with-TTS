#include "nouns.h"

Nouns::Nouns()
{

}
Nouns::~Nouns()
{

}

Abstract_Noun Nouns::getAbstractNouns()
{
	return this->_abstractNouns;
}
Collective_Noun Nouns::getCollectiveNouns()
{
	return this->_collectiveNouns;
}
Common_Noun Nouns::getCommonNouns()
{
	return this->_commonNouns;
}
Proper_Noun Nouns::getProperNouns()
{
	return this->_properNouns;
}