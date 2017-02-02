// NaturalLanguageProcessingv0.0.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Language\Language.h"

int main()
{
	Language lang;
	string userPhrase;
	vector<WORD_AND_TYPE> wordNType;
	bool keepLooping = true;
	cout << "AI is waiting for a talk..." << endl;
	while (keepLooping)
	{
		wordNType.clear();
		userPhrase = "";

		getline(cin, userPhrase);
		lang.getWordNTypeInSentence(userPhrase, wordNType);
		for (unsigned int i = 0; i < wordNType.size(); i++)
		{
			cout << wordNType.at(i).word << " : " << wordNType.at(i).type << endl;
		}

	}
    return 0;
}

