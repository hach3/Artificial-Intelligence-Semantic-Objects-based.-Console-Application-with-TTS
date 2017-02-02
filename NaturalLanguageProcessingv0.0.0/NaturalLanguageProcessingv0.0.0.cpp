// NaturalLanguageProcessingv0.0.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Language\Language.h"
/*
Just wait til the user write a phrase and press enter. 
If it does, i send the sentence to the language class and save words and types in a vector

*/
std::vector<std::string> split(const std::string& s);

int main()
{
	Language lang;
	string userPhrase;
	vector<string> userVectorPhrase;
	vector<WORD_AND_TYPE> wordNType;
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
		for (unsigned int i = 0; i < wordNType.size(); i++)
		{
		
			for (unsigned int y = 0; y < wordNType.at(i).types.size(); y++)
			{				
				cout << wordNType.at(i).word << " : " << wordNType.at(i).types.at(y) << endl;
			}

		}
	
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