#pragma once
#ifndef ADJECTIVES_H
#define ADJECTIVES_H

#include "Adjectives/article.h"
#include "Adjectives/attribute.h"
#include "Adjectives/coordinate.h"
#include "Adjectives/demonstrativeAdjectives.h"
#include "Adjectives/indefinite.h"
#include "Adjectives/interrogativeAdjectives.h"
#include "Adjectives/numbers.h"
#include "Adjectives/possessiveAdjectives.h"

class Adjectives {
public:
	Adjectives();
	~Adjectives();

	Possessive_Adjectives getPossessiveAdjectives();
	Demonstrative_Adjectives getDemonstrativeAdjectives();
	Coordinate_Adjectives getCoordinateAdjectives();
	Article getArticleAdjectives();
	Attribute getAttributeAdjectives();
	IndefiniteAdj getIndefiniteAdjectives();
	Interrogative_Adjectives getInterrogativeAdjectives();
	Numbers getNumberAdjectives();
protected:
private:
	Possessive_Adjectives _possessiveAdjectives;
	Demonstrative_Adjectives _demonstrativeAdjectives;
	Coordinate_Adjectives _coordinateAdjectives;
	Article _articleAdjectives;
	Attribute _attributeAdjectives;
	IndefiniteAdj _indefiniteAdjectives;
	Interrogative_Adjectives _interrogativeAdjectives;
	Numbers _numberAdjectives;


};


#endif //ADJECTIVES_H