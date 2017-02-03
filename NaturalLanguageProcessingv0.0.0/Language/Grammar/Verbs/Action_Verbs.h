#ifndef ACTION_VERBS_H
#define ACTION_VERBS_H

#include "Verbs.h"

class Action_Verbs : public Verbs {
public:
	Action_Verbs();

	Action_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Action_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Action_Verbs();
private:
};

#endif //ACTION_VERBS_H