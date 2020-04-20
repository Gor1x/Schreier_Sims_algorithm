#include "Permutation.h"

Permutation::Permutation(size_t length) : length(length)
            , next(std::vector<int> (length + 1, -1)) {}

int Permutation::operator()(int k)
{
    return next[k];
}

Permutation Permutation::operator*(const Permutation &other) const
{

}
