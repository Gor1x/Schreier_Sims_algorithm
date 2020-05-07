#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"
#include "SchreierStabChain.h"

using namespace std;

static Permutation firstTypeShuffle(size_t sz = 54)
{
    size_t half = sz / 2;
    std::vector<int> perm(sz + 1, -1);
    for (size_t i = 1; i <= half; i++)
    {
        perm[i] = 1 + 2 * (i - 1); //1 3 5 ... 2k+1
    }
    for (size_t i = half + 1; i <= sz; i++)
    {
        perm[i] = (i - half) * 2;
    }

    return Permutation(perm);
}

static Permutation secondTypeShuffle(size_t sz = 54)
{
    std::vector<int> elems(sz + 1, -1);
    for (size_t i = 1; i <= sz; i++)
        elems[i] = i;
    for (size_t i = sz / 3 + 1; i <= 2 * sz / 3; i++)
    {
        std::swap(elems[i], elems[i + sz / 3]);
    }
    for (auto v : elems)
        std::cout << v << " ";
    std::cout << std::endl;
    return Permutation(elems);
}

int main()
{
    //freopen("output.txt", "w", stdout);
    //std::cout << firstTypeShuffle(6).toString();
    SchreierStabChain chain(54, {firstTypeShuffle(), secondTypeShuffle()});
    std::cout << chain.getGroupSize();
    return 0;
}