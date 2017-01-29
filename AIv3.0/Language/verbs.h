#pragma once
#ifndef VERBS_H
#define VERBS_H

#include "Verbs/action.h"
#include "Verbs/auxiliary.h"
#include "Verbs/modal.h"
#include "Verbs/phrasal.h"
#include "Verbs/stative.h"

class Verbs {
public:
	Verbs();
	~Verbs();
protected:
private:
	Action_Verb _actionVerbs;
	Auxiliary_Verb _auxiliaryVerbs;
	Modal_Verb _modalVerbs;
	Phrasal_Verb _phrasalVerbs;
	Stative_Verb _stativeVerbs;

};


#endif //VERBS_H