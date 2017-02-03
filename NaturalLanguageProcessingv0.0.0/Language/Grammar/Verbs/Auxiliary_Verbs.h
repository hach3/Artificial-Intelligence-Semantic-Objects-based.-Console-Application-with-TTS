#ifndef AUXILIARY_VERBS_H

#define AUXILIARY_VERBS_H

#include "Verbs.h"

class Auxiliary_Verbs : public Verbs {
public:
	Auxiliary_Verbs();

	Auxiliary_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Auxiliary_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Auxiliary_Verbs();
private:
};

#endif //AUXILIARY_VERBS_H