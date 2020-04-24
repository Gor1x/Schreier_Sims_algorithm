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


void SchreierStabChain::build()
{
    vector<Permutation> currentG = strongGenerators;
    for (int k = 1; currentG.size() > 0 && (currentG.size() > 1 || currentG.back().toString() != "id"); k++)
    {
        std::cout << "new iteration " << std::endl;

        trees.emplace_back(SchreierTree(currentG, base[k]));

        const auto &currentTree = trees.back();
        const auto &orbit = currentTree.getOrbit();

        currentTree.print();


        vector<Permutation> newG = currentG;

        std::map<std::pair<int, int>, Permutation> used;
        for (auto y : orbit)
        {
            for (const auto &perm : currentG)
            {
                auto permutation = currentTree.getWay(perm(y)).inverse() * perm * currentTree.getWay(y);

                if (isGreatForNewG(permutation, used))
                {
                    newG.emplace_back(std::move(permutation));
                }
            }
        }

        currentG.swap(newG);
    }

    size_t pr = 1;
    for (size_t i = 0; i < trees.size(); i++)
        pr *= trees[i].size();
    groupSize = pr;
}

bool SchreierStabChain::isGreatForNewG(Permutation permutation, std::map<std::pair<int, int>, Permutation> &used)
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
            }
        }
    }
    return permutation.toString() != "id";
}

SchreierStabChain::SchreierStabChain(size_t n, std::initializer_list<std::string> list)
        : SchreierStabChain(n, getVectorFromList(list)) {}

size_t SchreierStabChain::getSize()
{
    return groupSize;
}
