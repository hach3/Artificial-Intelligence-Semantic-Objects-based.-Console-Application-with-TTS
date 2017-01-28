#pragma once
#ifndef GLOBALNOUNS_H
#define GLOBALNOUNS_H

#include <vector>
#include <string>

typedef struct {
	bool _isConcrete;
	std::vector<std::string> _sensesCalled;

} IS_CONCRETE;

typedef struct {
	bool _isCountable;

} IS_COUNTABLE;

#endif //GLOBALNOUNS_H