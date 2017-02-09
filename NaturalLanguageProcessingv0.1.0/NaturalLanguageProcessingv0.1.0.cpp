// NaturalLanguageProcessingv0.0.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Language\Language.h"
#include "Language\Phrase_Structuration.h"
/*
Just wait til the user write a phrase and press enter.
If it does, i send the sentence to the language class and save words and types in a vector

*/
std::vector<std::string> split(const std::string& s);

int main()
{
	Language lang;
	Phrase_Structuration ps;

	string userPhrase;
	vector<string> userVectorPhrase;
	vector<WORD_AND_TYPE> wordNType;
	vector<vector<WORDS_TYPE>> currentPhraseTypes;
	std::vector<std::vector<WORDS_TYPE>> structuresFound;

	/* DEFINED STRUCTURES, THE PLACE GONNA CHANGE BUT HERE FOR TESTS */
	std::vector<std::vector<WORDS_TYPE>> tz;
	/* DAY 1 http://www.english-for-students.com/Frequently-Used-Sentences-1.html*/
	std::vector<WORDS_TYPE> ABC = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
	std::vector<WORDS_TYPE> DEF = { INTERROGATIVE_PRONOUNS, AUXILIARY_VERBS, POSSESSIVE_ADJECTIVES, ABSTRACT_NOUNS };
	std::vector<WORDS_TYPE> GHI = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, ARTICLES_ADJECTIVES, PLACE_ADVERBS, PROPER_NOUNS };
	std::vector<WORDS_TYPE> JKL = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, ACTION_VERBS, ABSTRACT_NOUNS };
	std::vector<WORDS_TYPE> MNO = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, ARTICLES_ADJECTIVES, COMMON_NOUNS };
	std::vector<WORDS_TYPE> PQR = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, POSSESSIVE_ADJECTIVES, COMMON_NOUNS };
	std::vector<WORDS_TYPE> STU = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, POSSESSIVE_ADJECTIVES,  ATTRIBUTIVE_ADJECTIVES, COMMON_NOUNS };

	/* DAY 2 http://www.english-for-students.com/Frequently-Used-Sentences-2.html*/
//	std::vector<WORDS_TYPE> VWX = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
//	std::vector<WORDS_TYPE> YZA = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
//	std::vector<WORDS_TYPE> BCD = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
//	std::vector<WORDS_TYPE> EFG = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
//	std::vector<WORDS_TYPE> HIJ = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };
//	std::vector<WORDS_TYPE> KLM = { SUBJECT_PRONOUNS, AUXILIARY_VERBS, PROPER_NOUNS };


	tz.push_back(ABC);	
	tz.push_back(DEF);
	tz.push_back(GHI);
	tz.push_back(JKL);
	tz.push_back(MNO);
	tz.push_back(PQR);
	tz.push_back(STU);

	



	/* WAITING FOR USER INPUT LOOP */
	bool keepLooping = true;

	cout << "AI is waiting for a talk..." << endl;

	while (keepLooping)
	{
		wordNType.clear();
		userVectorPhrase.clear();
		userPhrase = "";

		getline(cin, userPhrase);

		userVectorPhrase = split(userPhrase);
		cout << endl;
		lang.getWordNTypeInSentence(userVectorPhrase, &wordNType);

		/* DISPLAY THE WORDS AND THEIR INT VALUE (which is the int value enumeration WORDS_TYPE) */
		for (unsigned int i = 0; i < wordNType.size(); i++)
		{

			for (unsigned int y = 0; y < wordNType.at(i).types.size(); y++)
			{
				cout << wordNType.at(i).word << " : " << wordNType.at(i).types.at(y) << endl;
			}

		}
		 ps.getStructure(wordNType, currentPhraseTypes);

		/* COMPARE HERE TO THE DEFINED STRUCTURES AND CHECK IF THE CURRENT STRUCTURES EXISTS */
		
		for (int a = 0; a < currentPhraseTypes.size(); a++)
		{
			for (int i = 0; i < tz.size(); i++)
			{
				if (currentPhraseTypes.at(a) == tz.at(i))
				{
					structuresFound.push_back(tz.at(i));
				}				
			}
		}

		
		/* DISPLAYING FOUND STRUCTURES */
		cout << "FOUND " << structuresFound.size() << " EXISTING STRUCTURES : " << endl;
		for (int i = 0; i < structuresFound.size(); i++)
		{
			cout << "STRUCTURE " << i + 1 << " : ";
			for (int y = 0; y < structuresFound.at(i).size(); y++)
			{
				cout << ps.getWordTypesInString()[structuresFound.at(i).at(y)] << " ";
			}
			cout << endl;
		}
		 
		currentPhraseTypes.clear();
		
		/* Now we have the structures found, we have to check which one is the correct one. For this, we'll create some attributes to the words like bool isPlural, int person, bool isTransitive, etc...*/
		

		structuresFound.clear();
	}
	return 0;
}

/* Extract the word of a string in a vector and return it*/
std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
			j++;

		// if we found some nonwhitespace characters
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}