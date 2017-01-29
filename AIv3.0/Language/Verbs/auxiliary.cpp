#include "auxiliary.h"


Auxiliary_Verb::Auxiliary_Verb()
{
	this->init();
}
Auxiliary_Verb::~Auxiliary_Verb()
{
	this->_auxiliaryVerbsList.clear();
}

void Auxiliary_Verb::init()
{
	std::vector<std::string> presentFormBe;
	presentFormBe.push_back("AM");
	presentFormBe.push_back("ARE");
	presentFormBe.push_back("IS");
	presentFormBe.push_back("ARE");
	presentFormBe.push_back("ARE");
	presentFormBe.push_back("ARE");
	this->addAuxiliary("BE", presentFormBe);

	std::vector<std::string> presentFormDo;
	presentFormDo.push_back("DO");
	presentFormDo.push_back("DO");
	presentFormDo.push_back("DOES");
	presentFormDo.push_back("DO");
	presentFormDo.push_back("DO");
	presentFormDo.push_back("DO");
	this->addAuxiliary("DO", presentFormDo);

	std::vector<std::string> presentFormHave;
	presentFormHave.push_back("HAVE");
	presentFormHave.push_back("HAVE");
	presentFormHave.push_back("HAS");
	presentFormHave.push_back("HAVE");
	presentFormHave.push_back("HAVE");
	presentFormHave.push_back("HAVE");
	this->addAuxiliary("HAVE", presentFormHave);
}

bool Auxiliary_Verb::isAuxiliary(std::string word)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == word)
		{
			found = true;
			break;
		}
		for (unsigned int y = 0; y < this->_auxiliaryVerbsList.size(); y++)
		{
			if (this->_auxiliaryVerbsList.at(i).presentForm.at(y) == word)
			{
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return found;
}

void Auxiliary_Verb::addAuxiliary(std::string infinitiveForm)
{
	std::vector<std::string> presentForm;
	AUXILIARY_VERB auxiliary = { infinitiveForm, presentForm };
	this->_auxiliaryVerbsList.push_back(auxiliary);

}
void Auxiliary_Verb::addAuxiliary(std::string infinitiveForm, std::vector<std::string> presentForm)
{
	AUXILIARY_VERB auxiliary = { infinitiveForm, presentForm };
	this->_auxiliaryVerbsList.push_back(auxiliary);
}

std::string Auxiliary_Verb::getAuxiliaryAtPerson(std::string auxiliary, int person)
{
	bool found = false;
	std::string auxiliaryAtPerson;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == auxiliary)
		{
			auxiliaryAtPerson = this->_auxiliaryVerbsList.at(i).presentForm.at(person - 1);
			found = true;
			break;
		}
		for (unsigned int y = 0; y < this->_auxiliaryVerbsList.at(i).presentForm.size(); y++)
		{
			if (this->_auxiliaryVerbsList.at(i).presentForm.at(y) == auxiliary)
			{
				auxiliaryAtPerson = this->_auxiliaryVerbsList.at(i).presentForm.at(person - 1);
				found = true;
				break;
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return auxiliaryAtPerson;
}
void Auxiliary_Verb::setPresentForm(std::string auxiliary, std::vector<std::string> presentForm)
{
	bool found = false;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == auxiliary)
		{
			this->_auxiliaryVerbsList.at(i).presentForm = presentForm;
			found = true;
			break;
		}
	}
}

bool Auxiliary_Verb::isBe(std::string word)
{
	bool found = false;
	bool isBe = false;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == "BE")
		{
			if (this->_auxiliaryVerbsList.at(i).infinitiveForm == word)
			{
				isBe = true;
				found = true;
				break;
			}
			for (unsigned int y = 0; y < this->_auxiliaryVerbsList.at(i).presentForm.size(); y++)
			{
				if (this->_auxiliaryVerbsList.at(i).presentForm.at(y) == word)
				{
					isBe = true;
					found = true;
					break;
				}
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return isBe;
}
bool Auxiliary_Verb::isBeInSentence(std::string sentence, std::string &verb)
{
	bool found = false;
	std::size_t foundAt;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		foundAt = sentence.find(this->_auxiliaryVerbsList.at(i).infinitiveForm);
		if (foundAt != std::string::npos)
		{
			found = true;
			verb = this->_auxiliaryVerbsList.at(i).infinitiveForm;
			break;
		}
		for (unsigned int y = 0; y < this->_auxiliaryVerbsList.at(i).presentForm.size(); y++)
		{
			foundAt = sentence.find(this->_auxiliaryVerbsList.at(i).presentForm.at(y));
			if (foundAt != std::string::npos)
			{
				found = true;
				verb = this->_auxiliaryVerbsList.at(i).presentForm.at(y);
				break;
			}
		}
		if (found == true)
		{
			break;
		}

	}
	return found;
}
bool Auxiliary_Verb::isHave(std::string word)
{
	bool found = false;
	bool isHave = false;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == "HAVE")
		{
			if (this->_auxiliaryVerbsList.at(i).infinitiveForm == word)
			{
				isHave = true;
				found = true;
				break;
			}
			for (unsigned int y = 0; y < this->_auxiliaryVerbsList.at(i).presentForm.size(); y++)
			{
				if (this->_auxiliaryVerbsList.at(i).presentForm.at(y) == word)
				{
					isHave = true;
					found = true;
					break;
				}
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return isHave;
}
bool Auxiliary_Verb::isDo(std::string word)
{
	bool found = false;
	bool isDo = false;
	for (unsigned int i = 0; i < this->_auxiliaryVerbsList.size(); i++)
	{
		if (this->_auxiliaryVerbsList.at(i).infinitiveForm == "DO")
		{
			if (this->_auxiliaryVerbsList.at(i).infinitiveForm == word)
			{
				isDo = true;
				found = true;
				break;
			}
			for (unsigned int y = 0; y < this->_auxiliaryVerbsList.at(i).presentForm.size(); y++)
			{
				if (this->_auxiliaryVerbsList.at(i).presentForm.at(y) == word)
				{
					isDo = true;
					found = true;
					break;
				}
			}
		}
		if (found == true)
		{
			break;
		}
	}
	return isDo;
}