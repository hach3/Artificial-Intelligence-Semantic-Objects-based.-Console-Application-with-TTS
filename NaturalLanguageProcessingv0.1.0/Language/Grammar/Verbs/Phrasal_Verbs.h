#ifndef PHRASAL_VERBS_H
#define PHRASAL_VERBS_H

#include "Verbs.h"

class Phrasal_Verbs : public Verbs {
public:
	Phrasal_Verbs();

	Phrasal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Phrasal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Phrasal_Verbs();


private:
};

#endif //PHRASAL_VERBS_H
