#ifndef STATIVE_VERBS_H
#define STATIVE_VERBS_H

#include "Verbs.h"

class Stative_Verbs : public Verbs {
public:
	Stative_Verbs();

	Stative_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Stative_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Stative_Verbs();
private:
};

#endif //STATIVE_VERBS_H