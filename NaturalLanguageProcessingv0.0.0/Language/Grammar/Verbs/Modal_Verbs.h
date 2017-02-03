#ifndef MODAL_VERBS_H
#define MODAL_VERBS_H

#include "Verbs.h"

class Modal_Verbs : public Verbs {
public:
	Modal_Verbs();

	Modal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);

	Modal_Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);

	~Modal_Verbs();
private:
};

#endif //MODAL_VERBS_H