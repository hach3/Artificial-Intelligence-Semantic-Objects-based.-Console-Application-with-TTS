#ifndef PLACE_ADVERBS_H
#define PLACE_ADVERBS_H

#include <vector>
#include <string>
/*

*/
typedef struct {
	std::string place;
}PLACE_ADVERBS;

class Place_Adverbs {
public:
	Place_Adverbs();
	~Place_Adverbs();

	void init(void);

	void addPlaceAdj(std::string place);

	bool checkIfPlace(std::string place);
	bool checkIfPlaceInSentence(std::string sentence);
	bool checkIfPlaceInVector(std::vector<std::string> vectorSentence);


protected:
private:
	std::vector<PLACE_ADVERBS> _placeAdverbsList;
};
#endif//PLACE_ADVERBS_H