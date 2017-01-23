#ifndef COLLCONCEPTWH_H
#define COLLCONCEPTWH_H

#include "CollConcept.h"

class CollConceptWH : public CollConcept {
public:
    CollConceptWH();
    ~CollConceptWH();

    void Init();

    /* Check if the wh exists by checking the name in the whwords vector */
    bool checkIfExist(std::string wh_name);
	bool checkIfWordIsWH(std::string wh_word);
    void deleteAll();

    void addConceptWH(std::string parent, std::string whname, std::vector<std::string> whwords);
    void deleteConceptWH(std::string wh);

    std::string getName(std::string whWord);

    std::vector<std::string> getConceptWordsByName(std::string wh_name);

	

protected:
private:
    std::vector<CONCEPT_WH> _whWords;

};


#endif // COLLCONCEPTWH_H
