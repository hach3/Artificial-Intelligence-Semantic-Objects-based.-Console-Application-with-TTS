#ifndef VERBS_H
#define VERBS_H


#include "..\..\Words.h"

/*
LORD MOTHER OF ALL PRONOUNS
*/


class Verbs : public Words {
public:
	Verbs(void);
	Verbs(string value, WORDS wordType, WORDS_TYPE type);
	Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm);
	Verbs(string value, WORDS wordType, WORDS_TYPE type, string infinitiveForm,
		string ingForm, string passiveForm, string participateForm,
		vector<string> presentForm, vector<string> pastForm);
	~Verbs(void);


	string getInfinitiveForm();
	string getIngForm();
	string getPassiveForm();
	string getParticipateForm();

	vector<string> getPresentForm();
	vector<string> getPastForm();
protected:
	

private:
	/*
	@TODO :
	Add the infinitive form, ing form, passive form, participate form.
	Also add Present Form and Past Form
	
	*/
	string _infinitiveForm;
	string _ingForm;
	string _passiveForm;
	string _participateForm;

	vector<string> _presentTense;
	vector<string> _pastTense;
};

#endif //VERBS_H
