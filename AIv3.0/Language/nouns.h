#pragma once
#ifndef NOUNS_H
#define NOUNS_H

#include "Nouns/abstract.h"
#include "Nouns/collective.h"
#include "Nouns/common.h"
#include "Nouns/proper.h"

class Nouns {
public:
	Nouns();
	~Nouns();
protected:
private:
	Abstract_Noun _abstractNouns;
	Collective_Noun _collectiveNouns;
	Common_Noun _commonNouns;
	Proper_Noun _properNouns;

};


#endif //NOUNS_H