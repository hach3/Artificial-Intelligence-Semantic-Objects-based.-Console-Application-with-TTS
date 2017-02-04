#include "Language.h"

#include <fstream>

Language::Language()
{
	this->init();
}
Language::~Language()
{

}


void Language::init()
{
	this->initPrepositions();
	this->initConjunctions();
	this->initPronouns();
	this->initAdjectives();
	this->initVerbs();
	this->initNouns();
	this->initAdverbs();
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


/* ADJECTIVES CREATION */
void Language::initAdjectives()
{
	/* COMPARING ADJECTIVES */
	vector<string> AdjectivesList;
	this->readFile("Adjectives\\Adjectives_Data\\Comparing_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Comparing_Adjectives(AdjectivesList.at(i), ADJECTIVES, COMPARING_ADJECTIVES));
	}
	/* COMPOUND ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Compound_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Compound_Adjectives(AdjectivesList.at(i), ADJECTIVES, COMPOUND_ADJECTIVES));
	}
	/* DENOMINAL ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Denominal_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Denominal_Adjectives(AdjectivesList.at(i), ADJECTIVES, DENOMINAL_ADJECTIVES));
	}
	AdjectivesList.clear();
}

/* ADVERBS CREATION */
void Language::initAdverbs()
{
	/* CONJUNCTIVE ADVERBS */
	vector<string> AdverbsList;
	this->readFile("Adverbs\\Adverbs_Data\\Conjunctive_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Conjunctive_Adverbs(AdverbsList.at(i), ADVERBS, CONJUNCTIVE_ADVERBS));
	}	
	/* DEGREE ADVERBS */
	this->readFile("Adverbs\\Adverbs_Data\\Degree_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Degree_Adverbs(AdverbsList.at(i), ADVERBS, DEGREE_ADVERBS));
	}
	/* FREQUENCY ADVERBS */
	this->readFile("Adverbs\\Adverbs_Data\\Frequency_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Frequency_Adverbs(AdverbsList.at(i), ADVERBS, FREQUENCY_ADVERBS));
	}
	/* MANNER ADVERBS */
	this->readFile("Adverbs\\Adverbs_Data\\Manner_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Manner_Adverbs(AdverbsList.at(i), ADVERBS, MANNER_ADVERBS));
	}
	/* PLACE ADVERBS */
	this->readFile("Adverbs\\Adverbs_Data\\Place_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Place_Adverbs(AdverbsList.at(i), ADVERBS, PLACE_ADVERBS));
	}
	/* TIME ADVERBS */
	this->readFile("Adverbs\\Adverbs_Data\\Time_Adverbs.txt", AdverbsList);
	for (unsigned int i = 0; i < AdverbsList.size(); i++)
	{
		this->addWord(new Time_Adverbs(AdverbsList.at(i), ADVERBS, TIME_ADVERBS));
	}	
	AdverbsList.clear();
}


/* CONJUNCTIONS CREATION */
void Language::initConjunctions()
{
	/* COORDINATING CONJUNCTIONS */
	vector<string> ConjunctionsList;
	this->readFile("Conjunctions\\Conjunctions_Data\\Coordinating_Conjunctions.txt", ConjunctionsList);
	for (unsigned int i = 0; i < ConjunctionsList.size(); i++)
	{
		this->addWord(new Coordinating_Conjunctions(ConjunctionsList.at(i), CONJUNCTIONS, COORDINATING_CONJUNCTIONS));
	}

	/* CORRELATIVE CONJUNCTIONS */
	this->readFile("Conjunctions\\Conjunctions_Data\\Correlative_Conjunctions.txt", ConjunctionsList);
	for (unsigned int i = 0; i < ConjunctionsList.size(); i++)
	{
		this->addWord(new Correlative_Conjunctions(ConjunctionsList.at(i), CONJUNCTIONS, CORRELATIVE_CONJUNCTIONS));
	}
	/* SUBORDINATING CONJUNCTIONS */
	this->readFile("Conjunctions\\Conjunctions_Data\\Subordinating_Conjunctions.txt", ConjunctionsList);
	for (unsigned int i = 0; i < ConjunctionsList.size(); i++)
	{
		this->addWord(new Subordinating_Conjunctions(ConjunctionsList.at(i), CONJUNCTIONS, SUBORDINATING_CONJUNCTIONS));
	}
	ConjunctionsList.clear();
}

/* PREPOSITIONS CREATION */
void Language::initPrepositions()
{
	/* PLACE PREPOSITIONS */
	vector<string> PrepositionsList;
	this->readFile("Prepositions\\Prepositions_Data\\Place_Prepositions.txt", PrepositionsList);
	for (unsigned int i = 0; i < PrepositionsList.size(); i++)
	{
		this->addWord(new Place_Prepositions(PrepositionsList.at(i), PREPOSITIONS, PLACE_PREPOSITION));
	}
	/* TIME PREPOSITIONS */
	this->readFile("Prepositions\\Prepositions_Data\\Time_Prepositions.txt", PrepositionsList);
	for (unsigned int i = 0; i < PrepositionsList.size(); i++)
	{
		this->addWord(new Time_Prepositions(PrepositionsList.at(i), PREPOSITIONS, TIME_PREPOSITION));
	}
	PrepositionsList.clear();
}


/* NOUNS CREATION */
void Language::initNouns()
{
	/* ABSTRACT NOUNS */
	vector<string> NounsList;
	this->readFile("Nouns\\Nouns_Data\\Abstract_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Abstract_Nouns(NounsList.at(i), NOUNS, ABSTRACT_NOUNS));
	}
	/* COLLECTIVE NOUNS */
	this->readFile("Nouns\\Nouns_Data\\Collective_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Collective_Nouns(NounsList.at(i), NOUNS, COLLECTIVE_NOUNS));
	}
	/* COMMON NOUNS */
	this->readFile("Nouns\\Nouns_Data\\Common_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Common_Nouns(NounsList.at(i), NOUNS, COMMON_NOUNS));
	}
	/* COMPOUND NOUNS */
	this->readFile("Nouns\\Nouns_Data\\Compound_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Compound_Nouns(NounsList.at(i), NOUNS, COMPOUND_NOUNS));
	}
	/* GERUND NOUNS */
	this->readFile("Nouns\\Nouns_Data\\Gerund_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Gerund_Nouns(NounsList.at(i), NOUNS, GERUND_NOUNS));
	}
	/* PROPER NOUNS */
	this->readFile("Nouns\\Nouns_Data\\Proper_Nouns.txt", NounsList);
	for (unsigned int i = 0; i < NounsList.size(); i++)
	{
		this->addWord(new Proper_Nouns(NounsList.at(i), NOUNS, PROPER_NOUNS));
	}
	NounsList.clear();
}




void Language::initPronouns()
{
	/* DEMONSTRATIVE PRONOUNS */
	this->addWord(new Demonstrative_Pronouns("THIS", ADJECTIVES, DEMONSTRATIVE_PRONOUNS));

	/* INDEFINITE PRONOUNS Add : many --- a few.*/
	this->addWord(new Indefinite_Pronouns("SOMEBODY", ADJECTIVES, INDEFINITE_PRONOUNS));

	/* INTENSIVE PRONOUNS */
	this->addWord(new Intensive_Pronouns("HIMSELF", PRONOUNS, INTENSIVE_PRONOUNS));

	/* INTERROGATIVE PRONOUNS Add : Whatever, whatsoever & stuff */
	this->addWord(new Interrogative_Pronouns("WHAT", PRONOUNS, INTERROGATIVE_PRONOUNS));

	/* OBJECT PRONOUNS */
	this->addWord(new Object_Pronouns("ME", PRONOUNS, OBJECT_PRONOUNS));

	/* PERSONAL PRONOUNS AS IT IS A HIDDEN NINJA MOTHER CLASS OF OBJECT PRONOUNS AND SUBJECT PRONOUNS
	this->addWord(new Personal_Pronouns("I", PERSONAL_PRONOUNS));
	 */
	/* POSSESSIVE PRONOUNS */
	this->addWord(new Possessive_Pronouns("MINE", PRONOUNS, POSSESSIVE_PRONOUNS));

	/* RECIPROCAL PRONOUNS */
	this->addWord(new Reciprocal_Pronouns("ONE ANOTHER", PRONOUNS, RECIPROCAL_PRONOUNS));

	/* REFLEXIVE PRONOUNS */
	this->addWord(new Reflexive_Pronouns("MYSELF", PRONOUNS, REFLEXIVE_PRONOUNS));

	/* RELATIVE PRONOUNS*/
	this->addWord(new Relative_Pronouns("WHICH", PRONOUNS, RELATIVE_PRONOUNS));

	/* SUBJECT PRONOUNS*/
	this->addWord(new Subject_Pronouns("I", PRONOUNS, SUBJECT_PRONOUNS));

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

void Language::readFile(string path, vector<string> &save)
{
	save.clear();
	string Word;
	ifstream file;

	file.open("C:\\Users\\hach3\\Documents\\Visual Studio 2015\\Projects\\NaturalLanguageProcessingv0.1.0\\NaturalLanguageProcessingv0.1.0\\Language\\Grammar\\" + path);
	if (file.fail())
		cout << "Failed to open file" << endl;

	while (getline(file, Word))
	{
		cout << Word << endl;
		save.push_back(Word);
	}
	file.close();
	
}