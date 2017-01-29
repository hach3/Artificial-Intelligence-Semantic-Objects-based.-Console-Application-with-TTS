#pragma once
#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "Adjectives/possessive.h"

class Adjectives {
public:
	Adjectives();
	~Adjectives();

	Possessive_Adjectives getPossessiveAdjectives();
protected:
private:
	Possessive_Adjectives _possessiveAdjectives;


};


#endif //ADJECTIVES_H