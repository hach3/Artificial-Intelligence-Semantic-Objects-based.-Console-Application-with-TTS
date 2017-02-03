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
	this->initAdjectives();
	this->initVerbs();
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
	WORDS test;
	string wordToCompareComposedBy2Words;
	string wordToCompareComposedBy3Words;
	
	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		//cout << "0" << endl;
		for (unsigned int y = 0; y < this->_wordsList.size(); y++)
		{
			//cout << "1" << endl;
			test = this->_wordsList.at(y)->getWordType();
			switch (test)
			{
			case VERBS:
				//cout << "3" << endl;
				for (unsigned int z = 0; z < this->_wordsList.at(y)->getPresentForm().size(); z++)
				{
					//cout << "4" << endl;
					//cout << this->_wordsList.at(y)->getPresentForm().size() << endl;
					if (i < sentence.size() - 2 && sentence.size() > 2)
					{
						//cout << "5" << endl;
						wordToCompareComposedBy3Words = sentence.at(i) + " " + sentence.at(i + 1) + " " + sentence.at(i + 2);

						wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
						if (wordToCompareComposedBy3Words == this->_wordsList.at(y)->getInfinitiveForm() ||
							wordToCompareComposedBy3Words == this->_wordsList.at(y)->getIngForm() ||
							wordToCompareComposedBy3Words == this->_wordsList.at(y)->getParticipateForm() ||
							wordToCompareComposedBy3Words == this->_wordsList.at(y)->getPassiveForm() ||
							wordToCompareComposedBy3Words == this->_wordsList.at(y)->getPresentForm().at(z) ||
							wordToCompareComposedBy3Words == this->_wordsList.at(y)->getPastForm().at(z))
						{
							//cout << "6" << endl;
							wnt.word = this->_wordsList.at(y)->getValue();
							wnt.types.push_back(this->_wordsList.at(y)->getType());
							wordNType->push_back(wnt);
							i += 2;
							break;
						}
						else if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue() ||
							wordToCompareComposedBy2Words == this->_wordsList.at(y)->getPresentForm().at(z) ||
							wordToCompareComposedBy2Words == this->_wordsList.at(y)->getPastForm().at(z))
						{
							//cout << "7" << endl;
							wnt.word = this->_wordsList.at(y)->getValue();
							wnt.types.push_back(this->_wordsList.at(y)->getType());
							wordNType->push_back(wnt);
							i++;
							break;
						}
						else if (sentence.at(i) == this->_wordsList.at(y)->getValue() ||
							sentence.at(i) == this->_wordsList.at(y)->getPresentForm().at(z) ||
							sentence.at(i) == this->_wordsList.at(y)->getPastForm().at(z))
						{
							//cout << "8" << endl;
							wnt.word = this->_wordsList.at(y)->getValue();
							wnt.types.push_back(this->_wordsList.at(y)->getType());
							wordNType->push_back(wnt);
							break;
						}


					}
					else if (i < sentence.size() - 1 && sentence.size() > 1)
					{
						//cout << "9" << endl;
						wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
						if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue() ||
							wordToCompareComposedBy2Words == this->_wordsList.at(y)->getPresentForm().at(z) ||
							wordToCompareComposedBy2Words == this->_wordsList.at(y)->getPastForm().at(z))
						{
							//cout << "10" << endl;
							wnt.word = this->_wordsList.at(y)->getValue();
							wnt.types.push_back(this->_wordsList.at(y)->getType());
							wordNType->push_back(wnt);
							i++;
							break;
						}
						else if (sentence.at(i) == this->_wordsList.at(y)->getValue() ||
							sentence.at(i) == this->_wordsList.at(y)->getPresentForm().at(z) ||
							sentence.at(i) == this->_wordsList.at(y)->getPastForm().at(z))
						{							
							//cout << "11" << endl;
							wnt.word = this->_wordsList.at(y)->getValue();
							wnt.types.push_back(this->_wordsList.at(y)->getType());
							wordNType->push_back(wnt);
							break;
						}
					}

					else if (sentence.at(i) == this->_wordsList.at(y)->getValue() ||
						sentence.at(i) == this->_wordsList.at(y)->getPresentForm().at(z) ||
						sentence.at(i) == this->_wordsList.at(y)->getPastForm().at(z))
					{
						//cout << "12" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
						break;
					}
					wnt.word = "";
					wnt.types.clear();
					
				}
				break;
			default:
				//cout << "13" << endl;
				if (i < sentence.size() - 2 && sentence.size() > 2)
				{
					//cout << "14" << endl;
					wordToCompareComposedBy3Words = sentence.at(i) + " " + sentence.at(i + 1) + " " + sentence.at(i + 2);

					wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
					if (wordToCompareComposedBy3Words == this->_wordsList.at(y)->getValue())
					{
						//cout << "15" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
						i += 2;
					}
					else if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
					{
						//cout << "16" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
						i++;
					}
					else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
					{
						//cout << "17" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
					}

				}
				else if (i < sentence.size() - 1 && sentence.size() > 1)
				{
					//cout << "18" << endl;
					wordToCompareComposedBy2Words = sentence.at(i) + " " + sentence.at(i + 1);
					if (wordToCompareComposedBy2Words == this->_wordsList.at(y)->getValue())
					{
						//cout << "19" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
						i++;
					}
					else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
					{
						//cout << "20" << endl;
						wnt.word = this->_wordsList.at(y)->getValue();
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						wordNType->push_back(wnt);
					}
				}

				else if (sentence.at(i) == this->_wordsList.at(y)->getValue())
				{
					//cout << "21" << endl;
					wnt.word = this->_wordsList.at(y)->getValue();
					wnt.types.push_back(this->_wordsList.at(y)->getType());
					wordNType->push_back(wnt);
				}
				//cout << "22" << endl;
				wnt.word = "";
				wnt.types.clear();
				break;
			}
			
		}
	}
	
}
void Language::initVerbs()
{
	vector<string> presentForm;
	vector<string> pastForm;	

	/* ACTION VERBS */
	
	//Present form of RUN
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("RUNS");
		else
			presentForm.push_back("RUN");
	}
	//Past form of RUN
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("RAN");
	}
	this->addWord(new Action_Verbs("RUN", VERBS, ACTION_VERBS, "RUN", "RUNNING", "RAN", "RUN", presentForm, pastForm));

	/* AUXILIARY_VERBS*/
	presentForm.clear();
	pastForm.clear();
	//Adding present forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("DOES");
		else
			presentForm.push_back("DO");
	}
	//Adding past forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("DID");
	}
	this->addWord(new Auxiliary_Verbs("DO", VERBS, AUXILIARY_VERBS, "DO", "", "DID", "", presentForm, pastForm));

	/* CONFUSING VERBS */
	presentForm.clear();
	pastForm.clear();
	//Adding present forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("BORROWS");
		else
			presentForm.push_back("BORROW");
	}
	//Adding past forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("BORROWED");
	}
	this->addWord(new Confusing_Verbs("BORROW", VERBS, CONFUSING_VERBS, "BORROW", "BORROWING", "BORROWED", "BORROWED", presentForm, pastForm));
	/* MODAL VERBS */
	presentForm.clear();
	pastForm.clear();
	//Adding present forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("CAN");
		else
			presentForm.push_back("CAN");
	}
	//Adding past forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("");
	}
	this->addWord(new Modal_Verbs("CAN", VERBS, MODAL_VERBS, "CAN", "", "", "", presentForm, pastForm));
	/* PHRASAL VERBS */
	presentForm.clear();
	pastForm.clear();
	//Adding present forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("THINKS UP");
		else
			presentForm.push_back("THINK UP");
	}
	//Adding past forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("");
	}
	this->addWord(new Phrasal_Verbs("THINK UP", VERBS, PHRASAL_VERBS, "THINK UP", "THINKING UP", "THOUGHT UP", "THOUGHT UP", presentForm, pastForm));
	/* STATIVE VERBS */
	presentForm.clear();
	pastForm.clear();
	//Adding present forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 2)
			presentForm.push_back("FEELS");
		else
			presentForm.push_back("FEEL");
	}
	//Adding past forms of DO
	for (unsigned int i = 0; i < 5; i++)
	{
		pastForm.push_back("FELT");
	}
	this->addWord(new Stative_Verbs("FEEL", VERBS, STATIVE_VERBS, "FEEL", "FEELING", "FELT", "FELT", presentForm, pastForm));
	presentForm.clear();
	pastForm.clear();
	
}
void Language::initAdjectives()
{
	/* COMPARING ADJECTIVES */
	this->addWord(new Comparing_Adjectives("LONG", ADJECTIVES, COMPARING_ADJECTIVES));
	/* COMPOUND ADJECTIVES */
	this->addWord(new Comparing_Adjectives("GREEN-EYED", ADJECTIVES, COMPOUND_ADJECTIVES));
	/* DENOMINAL ADJECTIVES */
	this->addWord(new Comparing_Adjectives("BIOLOGICAL", ADJECTIVES, DENOMINAL_ADJECTIVES));
}
void Language::initPronouns()
{
	/* DEMONSTRATIVE PRONOUNS */
	this->addWord(new Demonstrative_Pronouns("THIS", ADJECTIVES, DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THAT", ADJECTIVES, DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THESE", ADJECTIVES, DEMONSTRATIVE_PRONOUNS));
	this->addWord(new Demonstrative_Pronouns("THOSE", ADJECTIVES, DEMONSTRATIVE_PRONOUNS));
	/* INDEFINITE PRONOUNS Add : many --- a few.*/
	this->addWord(new Indefinite_Pronouns("SOMEBODY", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("SOMEONE", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("SOMETHING", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYBODY", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYONE", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("ANYTHING", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NO ONE", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NOBODY", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("NOTHING", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYBODY", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYONE", ADJECTIVES, INDEFINITE_PRONOUNS));
	this->addWord(new Indefinite_Pronouns("EVERYTHING", ADJECTIVES, INDEFINITE_PRONOUNS));
	/* INTENSIVE PRONOUNS */
	this->addWord(new Intensive_Pronouns("HIMSELF", PRONOUNS, INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("HERSELF", PRONOUNS, INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("OURSELVES", PRONOUNS, INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("YOURSELF", PRONOUNS, INTENSIVE_PRONOUNS));
	this->addWord(new Intensive_Pronouns("THEMSELVES", PRONOUNS, INTENSIVE_PRONOUNS));
	/* INTERROGATIVE PRONOUNS Add : Whatever, whatsoever & stuff */
	this->addWord(new Interrogative_Pronouns("WHAT", PRONOUNS, INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHICH", PRONOUNS, INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHO", PRONOUNS, INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHOM", PRONOUNS, INTERROGATIVE_PRONOUNS));
	this->addWord(new Interrogative_Pronouns("WHOSE", PRONOUNS, INTERROGATIVE_PRONOUNS));
	/* OBJECT PRONOUNS */
	this->addWord(new Object_Pronouns("ME", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("YOU", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("HIM", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("HER", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("IT", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("US", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("YOU", PRONOUNS, OBJECT_PRONOUNS));
	this->addWord(new Object_Pronouns("THEM", PRONOUNS, OBJECT_PRONOUNS));
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
	this->addWord(new Possessive_Pronouns("MINE", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("MY", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOURS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HIS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HER", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("HERS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("ITS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("OUR", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("OURS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOUR", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("YOURS", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("THEIR", PRONOUNS, POSSESSIVE_PRONOUNS));
	this->addWord(new Possessive_Pronouns("THEIRS", PRONOUNS, POSSESSIVE_PRONOUNS));
	/* RECIPROCAL PRONOUNS */
	this->addWord(new Reciprocal_Pronouns("ONE ANOTHER", PRONOUNS, RECIPROCAL_PRONOUNS));
	this->addWord(new Reciprocal_Pronouns("EACH OTHER", PRONOUNS, RECIPROCAL_PRONOUNS));
	/* REFLEXIVE PRONOUNS */
	this->addWord(new Reflexive_Pronouns("MYSELF", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("YOURSELF", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("HIMSELF", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("HERSELF", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("ITSELF", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("OURSELVES", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("YOURSELVES", PRONOUNS, REFLEXIVE_PRONOUNS));
	this->addWord(new Reflexive_Pronouns("THEMSELVES", PRONOUNS, REFLEXIVE_PRONOUNS));
	/* RELATIVE PRONOUNS*/
	this->addWord(new Relative_Pronouns("WHICH", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("THAT", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOSE", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOEVER", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOMEVER", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHO", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHOM", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHAT", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHEN", PRONOUNS, RELATIVE_PRONOUNS));
	this->addWord(new Relative_Pronouns("WHERE", PRONOUNS, RELATIVE_PRONOUNS));
	/* SUBJECT PRONOUNS*/
	this->addWord(new Subject_Pronouns("I", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("YOU", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("HE", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("SHE", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("IT", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("WE", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("YOU", PRONOUNS, SUBJECT_PRONOUNS));
	this->addWord(new Subject_Pronouns("THEY", PRONOUNS, SUBJECT_PRONOUNS));
}