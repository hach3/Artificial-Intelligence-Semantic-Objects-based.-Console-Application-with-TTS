#include "Language.h"

Language::Language()
{
	this->init();
}
Language::~Language()
{

}
void Language::init()
{
	this->initPronouns();
	
}

void Language::addWord(Words* word)
{
	this->_wordsList.push_back(word);
}


void Language::getWordNTypeInSentence(vector<string> sentence, vector<WORD_AND_TYPE>* wordNType)
{
	/*
	Check the phrase, get each word (starting by the composed one)
	Associate each word with its type !
	*/
	WORD_AND_TYPE wnt;
	string wordToCompareComposedBy2Words;
	string wordToCompareComposedBy3Words;
	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		for (unsigned int y = 0; y < this->_wordsList.size(); y++)
		{
			if (i < sentence.size() - 2 && sentence.size() > 2)
			{
				wordToCompareComposedBy3Words = sentence.at(i) + " " + sentence.at(i + 1) + " " + sentence.at(i + 2);

				wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
				if (wordToCompareComposedBy3Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
					i+=2;
				}
				else if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
					i++;
				}
				else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
				}

			}
			else if (i < sentence.size() - 1 && sentence.size() > 1)
			{
				wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
				if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
					i++;
				}
				else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
				{
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
				}
			}
		
			else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
			{
				wnt.word = this->_wordsList.at(y)->getValue();
				wnt.types.push_back(this->_wordsList.at(y)->getType());
				wordNType->push_back(wnt);
			}
	
		wnt.word = "";
		wnt.types.clear();
		}
	}
	
}

void Language::initPronouns()
{
	/* DEMONSTRATIVE PRONOUNS */
	this->addWord(new Demonstrative_Pronouns("THIS", DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THAT", DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THESE", DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THOSE", DEMONSTRATIVE_PRONOUNS));
	/* INDEFINITE PRONOUNS Add : many --- a few.*/
	this->addWord(new Indefinite_Pronouns("SOMEBODY", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("SOMEONE", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("SOMETHING", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYBODY", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYONE", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYTHING", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NO ONE", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NOBODY", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NOTHING", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYBODY", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYONE", INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYTHING", INDEFINITE_PRONOUNS));
	/* INTENSIVE PRONOUNS */
	this->addWord(new Intensive_Pronouns("HIMSELF", INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("HERSELF", INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("OURSELVES", INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("YOURSELF", INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("THEMSELVES", INTENSIVE_PRONOUNS));
	/* INTERROGATIVE PRONOUNS Add : Whatever, whatsoever & stuff */
	this->addWord(new Interrogative_Pronouns("WHAT", INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHICH", INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHO", INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHOM", INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHOSE", INTERROGATIVE_PRONOUNS));
	/* OBJECT PRONOUNS */
	this->addWord(new Object_Pronouns("ME", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("YOU", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("HIM", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("HER", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("IT", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("US", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("YOU", OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("THEM", OBJECT_PRONOUNS));
	/* PERSONAL PRONOUNS AS IT IS A HIDDEN NINJA MOTHER CLASS OF OBJECT PRONOUNS AND SUBJECT PRONOUNS
	this->addWord(new Personal_Pronouns("I", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("YOU", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("HE", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("SHE", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("IT", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("YOU", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("WE", PERSONAL_PRONOUNS));
	this->addWord(new Personal_Pronouns("THEY", PERSONAL_PRONOUNS)); */
	/* POSSESSIVE PRONOUNS */
	this->addWord(new Possessive_Pronouns("MINE", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("MY", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOURS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HIS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HER", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HERS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("ITS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("OUR", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("OURS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOUR", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOURS", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("THEIR", POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("THEIRS", POSSESSIVE_PRONOUNS));
	/* RECIPROCAL PRONOUNS */
	this->addWord(new Reciprocal_Pronouns("ONE ANOTHER", RECIPROCAL_PRONOUNS));
	this->addWord(new Reciprocal_Pronouns("EACH OTHER", RECIPROCAL_PRONOUNS));
	/* REFLEXIVE PRONOUNS */
	this->addWord(new Reflexive_Pronouns("MYSELF", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("YOURSELF", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("HIMSELF", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("HERSELF", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("ITSELF", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("OURSELVES", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("YOURSELVES", REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("THEMSELVES", REFLEXIVE_PRONOUNS));
	/* RELATIVE PRONOUNS*/
	this->addWord(new Relative_Pronouns("WHICH", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("THAT", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOSE", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOEVER", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOMEVER", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHO", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOM", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHAT", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHEN", RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHERE", RELATIVE_PRONOUNS));
	/* SUBJECT PRONOUNS*/
	this->addWord(new Subject_Pronouns("I", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("YOU", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("HE", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("SHE", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("IT", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("WE", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("YOU", SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("THEY", SUBJECT_PRONOUNS));
}