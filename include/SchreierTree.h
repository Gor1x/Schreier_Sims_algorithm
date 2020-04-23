#ifndef SCHREIER_SIMS_ALGORITHM_SCHREIERTREE_H
#define SCHREIER_SIMS_ALGORITHM_SCHREIERTREE_H

#include <vector>

#include "Permutation.h"

class SchreierTree
{
public:
    SchreierTree(vector<Permutation> gens, int head);

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
