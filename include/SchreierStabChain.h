#ifndef SCHREIER_SIMS_ALGORITHM_SCHREIERSTABCHAIN_H
#define SCHREIER_SIMS_ALGORITHM_SCHREIERSTABCHAIN_H

#include "SchreierTree.h"

class SchreierStabChain
{
public:
    SchreierStabChain(size_t n, vector<Permutation> permutations);

    SchreierStabChain(size_t n, std::initializer_list<std::string> strs);

    size_t getSize() const;

    size_t getBaseSize() const;

    bool groupHasPermutation(const Permutation &permutation);

private:
    void build();

    size_t count;
    vector<Permutation> strongGenerators;
    vector<SchreierTree> trees;

    size_t groupSize = 0;
    size_t baseSize = 0;
    vector<size_t> base;
};

#endif //SCHREIER_SIMS_ALGORITHM_SCHREIERSTABCHAIN_H
