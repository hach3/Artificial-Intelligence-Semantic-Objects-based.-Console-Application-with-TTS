#include "adjectives.h"

Adjectives::Adjectives()
{

}
Adjectives::~Adjectives()
{

}

Possessive_Adjectives Adjectives::getPossessiveAdjectives()
{
	return this->_possessiveAdjectives;
}

Demonstrative_Adjectives Adjectives::getDemonstrativeAdjectives()
{
	return this->_demonstrativeAdjectives;
}
Coordinate_Adjectives Adjectives::getCoordinateAdjectives()
{
	return this->_coordinateAdjectives;
}
Article Adjectives::getArticleAdjectives()
{
	return this->_articleAdjectives;
}
Attribute Adjectives::getAttributeAdjectives()
{
	return this->_attributeAdjectives;
}
IndefiniteAdj Adjectives::getIndefiniteAdjectives()
{
	return this->_indefiniteAdjectives;
}
Interrogative_Adjectives Adjectives::getInterrogativeAdjectives()
{
	return this->_interrogativeAdjectives;
}
Numbers Adjectives::getNumberAdjectives()
{
	return this->_numberAdjectives;
}