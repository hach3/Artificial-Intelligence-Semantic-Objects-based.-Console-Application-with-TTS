#include "Pronouns.h"

Pronouns::Pronouns()
{

}
Pronouns::Pronouns(std::string name)
{
	this->_name = name;
}
Pronouns::~Pronouns()
{

}

std::string Pronouns::getName(void)
{
	return this->_name;
}

bool Pronouns::isPronounInSentence(std::string sentence, std::string &pronoun)
{
	bool found = false;
	size_t foundAt;

	foundAt = sentence.find(this->getName());
	if (foundAt != std::string::npos)
	{
		pronoun = this->getName();
		found = true;
	}
	return found;
}
bool Pronouns::isPronounInSentence(std::vector<std::string> vectorSentence, std::string &pronoun)
{
	bool found = false;

	for (unsigned int y = 0; y < vectorSentence.size(); y++)
	{
		if (this->getName() == vectorSentence.at(y))
		{
			found = true;
			pronoun = this->getName();
		}
	}

	return found;
}