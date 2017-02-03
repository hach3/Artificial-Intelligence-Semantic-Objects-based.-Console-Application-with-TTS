#ifndef CONFUSING_VERBS_H

#define CONFUSING_VERBS_H

#include "Verbs.h"

class Confusing_Verbs : public Verbs {
public:
	Confusing_Verbs();

	Confusing_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Confusing_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Confusing_Verbs();
private:
};

#endif //CONFUSING_VERBS






