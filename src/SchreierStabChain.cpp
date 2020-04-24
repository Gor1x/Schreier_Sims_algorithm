#include "SchreierStabChain.h"

#include <utility>
#include <set>
#include <iostream>

SchreierStabChain::SchreierStabChain(size_t n, vector<Permutation> permutations) : count(n)
        , strongGenerators(std::move(permutations))
{
    base.resize(n + 1);
    for (size_t i = 1; i <= n; i++)
        base[i] = i;

    build();
}

static vector<Permutation> getVectorFromList(const std::initializer_list<std::string> &gens)
{
    vector<Permutation> perms;
    perms.reserve(gens.size());
    for (auto &v : gens)
    {
        perms.emplace_back(v);
    }
    return perms;
}

static void processPermutation(Permutation &permutation,
                               vector<Permutation> &newG,
                               size_t count,
                               std::map<std::pair<int, int>, Permutation> &used)
{
    for (size_t i = 1; i <= count; i++)
    {
        if (permutation(i) == i)
        {
            continue;
        }
        else
        {
            int j = permutation(i);
            auto pair = std::pair<int, int>(i, j);
            if (used.count(pair))
            {
                permutation = permutation.inverse() * used[pair];
            }
            else
            {
                used[pair] = permutation;
                newG.push_back(permutation);
            }
        }
    }
}

void SchreierStabChain::build()
{
    vector<Permutation> currentG = strongGenerators;
    for (int k = 1; currentG.size() > 0; k++)
    {
        trees.emplace_back(SchreierTree(currentG, base[k]));
        trees.back().print();
        std::cout << std::endl;
        const auto &currentTree = trees.back();
        const auto &orbit = currentTree.getOrbit();

        vector<Permutation> newG;

        std::map<std::pair<int, int>, Permutation> used;
        for (auto y : orbit)
        {
            for (const auto &perm : currentG)
            {
                auto permutation = currentTree.getWay(perm(y)).inverse() * perm * currentTree.getWay(y);
                auto str = permutation.toString();
                processPermutation(permutation, newG, count, used);
            }
        }
        currentG.swap(newG);
    }

    size_t pr = 1;
    for (const auto &tree : trees)
        pr *= tree.size();
    groupSize = pr;
}

SchreierStabChain::SchreierStabChain(size_t n, std::initializer_list<std::string> list)
        : SchreierStabChain(n, getVectorFromList(list)) {}

size_t SchreierStabChain::getSize()
{
    return groupSize;
}

bool SchreierStabChain::groupHasPermutation(const Permutation &permutation)
{

}
