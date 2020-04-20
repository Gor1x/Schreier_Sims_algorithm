#include <iostream>
#include "Permutation.h"

using std::max;
using std::string;

Permutation::Permutation(size_t length) : length(length)
        , next(std::vector<int>(length + 1, -1))
{
    for (size_t i = 1; i <= length; i++)
    {
        next[i] = i;
    }
}

int Permutation::operator()(int k) const
{
    return next[k];
}

Permutation operator*(const Permutation &first, const Permutation &second)
{
    Permutation perm(max(first.size(), second.size()));
    for (int i = 1; i <= perm.size(); i++)
    {
        perm.set(i, first(second(i)));
    }
    return perm;
}

int Permutation::size() const
{
    return length;
}

void Permutation::set(int where, int what)
{
    next[where] = what;
}

int Permutation::get(int k) const
{
    return operator()(k);
}

Permutation::Permutation(const string &s) : length(-1)
{
    vector<Cycle> cycles;
    size_t position = 0;
    while (true)
    {
        size_t closePosition = s.find(')', position);
        if (closePosition >= s.size())
        {
            break;
        }
        cycles.emplace_back(Cycle(s.substr(position, closePosition - position + 1)));
        position = closePosition + 1;
    }
    Permutation permutation;
    while (!cycles.empty())
    {
        permutation = cycles.back() * permutation;
        cycles.pop_back();
    }

    swap(permutation);
}

Permutation::Permutation(const Cycle &cycle)
{
    length = cycle.getMax();
    next.resize(length + 1);

    auto elementsArray = cycle.getElements();
    for (size_t i = 0; i < elementsArray.size(); i++)
    {

        next[elementsArray[i]] = (i == elementsArray.size() - 1) ?
                                 elementsArray[i + 1] :
                                 elementsArray[0];
    }
}

void Permutation::swap(Permutation &other)
{
    std::swap(length, other.length);
    next.swap(other.next);
}

void Permutation::print()
{
    vector<bool> used(length + 1);
    for (int i = 1; i <= length; i++)
    {
        if (used[i])
        {
            continue;
        }

    }
}



