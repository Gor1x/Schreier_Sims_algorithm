#include "SchreierTree.h"

#include <utility>
#include <queue>
#include <iostream>

using std::queue;

SchreierTree::SchreierTree(vector<Permutation> gens, int head) : generators(std::move(gens))
        , head(head)
{
    oppositeGenerators = generators;
    for (auto &perm : oppositeGenerators)
    {
        perm.pow(-1);
    }

    build();
}

void SchreierTree::build()
{
    queue<int> que;
    std::map<int, bool> used;

    que.push(head);
    used[head] = true;

    while (!que.empty())
    {
        int current = que.front();
        que.pop();

        for (size_t i = 0; i < generators.size(); i++)
        {
            auto v = oppositeGenerators[i];
            int next = v.getNext(current);
            if (next == current)
            {
                continue;
            }
            if (used[next])
            {
                continue;
            }

            used[next] = true;
            parentNumber[next] = i;
            que.push(next);
        }
    }
}

void SchreierTree::print()
{
    for (auto &v : parentNumber)
    {
        int vertex = v.first;
        Permutation &perm = generators[v.second];
        int parent = perm.getNext(vertex);

        std::cout << vertex << " ——> " << parent << " | " << perm.toString() << std::endl;
    }
}

Permutation SchreierTree::getWay(int k) const
{
    Permutation answer;
    while (k != head)
    {
        auto &permutation = generators[parentNumber.at(k)];
        answer = permutation * answer;
        k = permutation.getNext(k);
    }
    return answer;
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

SchreierTree::SchreierTree(std::initializer_list<std::string> gens, int head) :
        SchreierTree(getVectorFromList(gens), head) {}
