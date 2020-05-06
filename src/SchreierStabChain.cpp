#include "SchreierStabChain.h"

#include <utility>
#include <set>
#include <iostream>

SchreierStabChain::SchreierStabChain(size_t n, vector<Permutation> permutations) : count(n)
        , strongGenerators(std::move(permutations))
{
    base.push_back(0);
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
        base.push_back(k);
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
                //Здесь нужно учитывать, что "ребра" в образующих шраера в другую сторону, то есть получающиеся
                //перестановки надо развернуть.

                auto permutation = currentTree.getWay(perm.getNext(y)) * perm * currentTree.getWay(y).inverse();

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
    baseSize = base.size();
}

SchreierStabChain::SchreierStabChain(size_t n, std::initializer_list<std::string> list)
        : SchreierStabChain(n, getVectorFromList(list)) {}

size_t SchreierStabChain::getSize() const
{
    return groupSize;
}


bool SchreierStabChain::hasPermutation(Permutation permutation)
{
    for (size_t i = 1; i < baseSize; i++)
    {
        auto next = permutation.getNext(i);
        if (!trees[i - 1].contains(next))
        {
            return false;
        }
        permutation = trees[i - 1].getWay(next) * permutation;
    }
    return permutation.toString() == "id";
}


size_t SchreierStabChain::getBaseSize() const
{
    return baseSize;
}

bool SchreierStabChain::hasPermutation(const std::string &permutation)
{
    if (permutation == "id")
    {
        return true;
    }
    return hasPermutation(Permutation(permutation));
}

void SchreierStabChain::printAllGroup() const
{
    printing(0, Permutation());
}

void SchreierStabChain::printing(size_t lvl, Permutation permutation) const
{
    if (lvl == baseSize - 1)
    {
        std::cout << permutation.toString() << "\n";
        return;
    }
    for (const auto &treePermutation : trees[lvl].getTreePermutations())
    {
        printing(lvl + 1, treePermutation * permutation);
    }
}
