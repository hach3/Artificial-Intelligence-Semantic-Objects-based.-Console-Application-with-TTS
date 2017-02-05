#include "Language.h"
#include <sstream>
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
	string wordToCompareComposedBy2Words;
	string wordToCompareComposedBy3Words;

		
	for (unsigned int z = 0; z < sentence.size(); z++)
	{			
		for (unsigned int y = 0; y < this->_wordsList.size(); y++)
		{
			switch (this->_wordsList.at(y)->getWordType())
			{
			case VERBS:
				for (unsigned int j = 0; j < this->_wordsList.at(y)->getPastForm().size(); j++)
				{
					if (this->_wordsList.at(y)->getInfinitiveForm() == sentence.at(z) ||
						this->_wordsList.at(y)->getIngForm() == sentence.at(z) ||
						this->_wordsList.at(y)->getParticipateForm() == sentence.at(z) ||
						this->_wordsList.at(y)->getPassiveForm() == sentence.at(z) ||
						this->_wordsList.at(y)->getPastForm().at(j) == sentence.at(z) || 
						this->_wordsList.at(y)->getPresentForm().at(j) == sentence.at(z))
					{
						wnt.word = sentence.at(z);
						wnt.types.push_back(this->_wordsList.at(y)->getType());
						break;
					}
						
				}
				break;
			default:
				if (this->_wordsList.at(y)->getValue() == sentence.at(z))
				{
					wnt.word = sentence.at(z);
					wnt.types.push_back(this->_wordsList.at(y)->getType());
				}
				break;
			}
		}
		if (wnt.types.size() > 0)
		{
			wordNType->push_back(wnt);
			wnt.word = "";
			wnt.types.clear();
		}
		else {
			wnt.word = sentence.at(z);
			wnt.types.push_back(UNDEFINED);
			wordNType->push_back(wnt);
			wnt.word = "";
			wnt.types.clear();
		}
	
	}
	
	
}


/* ADJECTIVES CREATION */
void Language::initAdjectives()
{
	/* ARTICLES ADJECTIVES */
	vector<string> AdjectivesList;
	this->readFile("Adjectives\\Adjectives_Data\\Articles_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Articles_Adjectives(AdjectivesList.at(i), ADJECTIVES, ARTICLES_ADJECTIVES));
	}
	/* ATTRIBUTIVE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Attributive_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Attributive_Adjectives(AdjectivesList.at(i), ADJECTIVES, ATTRIBUTIVE_ADJECTIVES));
	}
	/* COORDINATE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Coordinate_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Coordinate_Adjectives(AdjectivesList.at(i), ADJECTIVES, COORDINATE_ADJECTIVES));
	}
	/* DEMONSTRATIVE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Demonstrative_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Demonstrative_Adjectives(AdjectivesList.at(i), ADJECTIVES, DEMONSTRATIVE_ADJECTIVES));
	}
	/* INDEFINITE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Indefinite_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Indefinite_Adjectives(AdjectivesList.at(i), ADJECTIVES, INDEFINITE_ADJECTIVES));
	}
	/* INTERROGATIVE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Interrogative_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Interrogative_Adjectives(AdjectivesList.at(i), ADJECTIVES, INTERROGATIVE_ADJECTIVES));
	}
	/* NUMBER ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Number_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Number_Adjectives(AdjectivesList.at(i), ADJECTIVES, NUMBER_ADJECTIVES));
	}
	/* POSSESSIVE ADJECTIVES */
	this->readFile("Adjectives\\Adjectives_Data\\Possessive_Adjectives.txt", AdjectivesList);
	for (unsigned int i = 0; i < AdjectivesList.size(); i++)
	{
		this->addWord(new Possessive_Adjectives(AdjectivesList.at(i), ADJECTIVES, POSSESSIVE_ADJECTIVES));
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
	vector<string> PronounsList;
	this->readFile("Pronouns\\Pronouns_Data\\Demonstrative_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Demonstrative_Pronouns(PronounsList.at(i), PRONOUNS, DEMONSTRATIVE_PRONOUNS));
	}
	/* INDEFINITE PRONOUNS Add : many --- a few.*/
	this->readFile("Pronouns\\Pronouns_Data\\Indefinite_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Indefinite_Pronouns(PronounsList.at(i), PRONOUNS, INDEFINITE_PRONOUNS));
	}
	/* INTENSIVE PRONOUNS */
	this->readFile("Pronouns\\Pronouns_Data\\Intensive_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Intensive_Pronouns(PronounsList.at(i), PRONOUNS, INTENSIVE_PRONOUNS));
	}
	/* INTERROGATIVE PRONOUNS Add : Whatever, whatsoever & stuff */
	this->readFile("Pronouns\\Pronouns_Data\\Interrogative_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Interrogative_Pronouns(PronounsList.at(i), PRONOUNS, INTERROGATIVE_PRONOUNS));
	}
	/* OBJECT PRONOUNS */
	this->readFile("Pronouns\\Pronouns_Data\\Object_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Object_Pronouns(PronounsList.at(i), PRONOUNS, OBJECT_PRONOUNS));
	}
	/* PERSONAL PRONOUNS AS IT IS A HIDDEN NINJA MOTHER CLASS OF OBJECT PRONOUNS AND SUBJECT PRONOUNS
	this->addWord(new Personal_Pronouns("I", PERSONAL_PRONOUNS));
	 */
	/* POSSESSIVE PRONOUNS */
	this->readFile("Pronouns\\Pronouns_Data\\Possessive_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Possessive_Pronouns(PronounsList.at(i), PRONOUNS, POSSESSIVE_PRONOUNS));
	}
	/* RECIPROCAL PRONOUNS */
	this->readFile("Pronouns\\Pronouns_Data\\Reciprocal_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Reciprocal_Pronouns(PronounsList.at(i), PRONOUNS, RECIPROCAL_PRONOUNS));
	}
	/* REFLEXIVE PRONOUNS */
	this->readFile("Pronouns\\Pronouns_Data\\Reflexive_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Reflexive_Pronouns(PronounsList.at(i), PRONOUNS, REFLEXIVE_PRONOUNS));
	}
	/* RELATIVE PRONOUNS*/
	this->readFile("Pronouns\\Pronouns_Data\\Relative_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Relative_Pronouns(PronounsList.at(i), PRONOUNS, RELATIVE_PRONOUNS));
	}
	/* SUBJECT PRONOUNS*/
	this->readFile("Pronouns\\Pronouns_Data\\Subject_Pronouns.txt", PronounsList);
	for (unsigned int i = 0; i < PronounsList.size(); i++)
	{
		this->addWord(new Subject_Pronouns(PronounsList.at(i), PRONOUNS, SUBJECT_PRONOUNS));
	}
	PronounsList.clear();
}


void Language::initVerbs()
{
	vector<vector<string>> base;
	vector<vector<string>> presentForm;
	vector<vector<string>> pastForm;

	/* ACTION VERBS */
	this->readVerbsFile("Verbs\\Verbs_Data\\Action_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{		
		this->addWord(new Action_Verbs(base.at(i).at(0), VERBS, ACTION_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	/* AUXILIARY_VERBS*/
	this->readVerbsFile("Verbs\\Verbs_Data\\Auxiliary_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{
		this->addWord(new Auxiliary_Verbs(base.at(i).at(0), VERBS, AUXILIARY_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	/* CONFUSING VERBS */
	this->readVerbsFile("Verbs\\Verbs_Data\\Confusing_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{
		this->addWord(new Confusing_Verbs(base.at(i).at(0), VERBS, CONFUSING_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	/* MODAL VERBS */
	this->readVerbsFile("Verbs\\Verbs_Data\\Modal_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{
		this->addWord(new Modal_Verbs(base.at(i).at(0), VERBS, MODAL_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	/* PHRASAL VERBS */
	this->readVerbsFile("Verbs\\Verbs_Data\\Phrasal_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{
		this->addWord(new Phrasal_Verbs(base.at(i).at(0), VERBS, PHRASAL_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	/* STATIVE VERBS */
	this->readVerbsFile("Verbs\\Verbs_Data\\Stative_Verbs.txt", base, presentForm, pastForm);
	for (unsigned int i = 0; i < base.size(); i++)
	{
		this->addWord(new Stative_Verbs(base.at(i).at(0), VERBS, STATIVE_VERBS, base.at(i).at(1), base.at(i).at(2), base.at(i).at(3), base.at(i).at(4), presentForm.at(i), pastForm.at(i)));
	}
	base.clear();
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

void Language::readVerbsFile(string path, vector<vector<string>> &base, vector<vector<string>> &presentForm, vector<vector<string>> &pastForm)
{
	base.clear();
	presentForm.clear();
	pastForm.clear();

	vector<string> baseL;
	vector<string> presentFormL;
	vector<string> pastFormL;

	string Word;
	ifstream file;
	int totalLine = 0;
	int line = 0;
	int Count = 0;

	file.open("C:\\Users\\hach3\\Documents\\Visual Studio 2015\\Projects\\NaturalLanguageProcessingv0.1.0\\NaturalLanguageProcessingv0.1.0\\Language\\Grammar\\" + path);
	if (file.fail())
		cout << "Failed to open file" << endl;

	while (file >> Word)
	{
		switch (line)
		{
		case 0:
			if (Word != ";")
			{
				baseL.push_back(Word);			
				cout << Word << endl;
			}
			else {
				base.push_back(baseL);
				line++;
				baseL.clear();
			}
			break;
		case 1:
			if (Word != ";")
			{
				presentFormL.push_back(Word);
				cout << Word << endl;
			}
			else {
				presentForm.push_back(presentFormL);
				line++;
				presentFormL.clear();
			}
			break;
		case 2:
			if (Word != ";")
			{
				pastFormL.push_back(Word);
				cout << Word << endl;
			}
			else {
				pastForm.push_back(pastFormL);
				line = 0;
				pastFormL.clear();
			}
			break;
			
		}
	}
	pastFormL.clear();
	presentFormL.clear();
	baseL.clear();
	file.close();

}