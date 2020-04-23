#ifndef SCHREIER_SIMS_ALGORITHM_SCHREIERTREE_H
#define SCHREIER_SIMS_ALGORITHM_SCHREIERTREE_H

#include <vector>

#include "Permutation.h"

class SchreierTree
{
    friend class SchreierSimsTest;
public:
    SchreierTree(vector<Permutation> gens, int head);

    SchreierTree(std::initializer_list<std::string> gens, int head);

    void print();

    Permutation getWay(int k) const;

private:
    void build();

    std::map<int, int> parentNumber;
    std::vector<Permutation> generators;
    std::vector<Permutation> oppositeGenerators;
    int head;
};


#endif //SCHREIER_SIMS_ALGORITHM_SCHREIERTREE_H
