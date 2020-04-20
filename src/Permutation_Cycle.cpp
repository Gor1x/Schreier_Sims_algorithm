#include <stdexcept>
#include <iostream>
#include <utility>
#include "Permutation.h"

Permutation::Cycle::Cycle(std::string s)
{
    if (s.size() <= 2 || s[0] != '(' || s.back() != ')')
    {
        throw std::logic_error("Неправильный формат цикла");
    }

    elements.reserve(s.size());
    s.erase(0, 1);
    s.back() = ' ';

    size_t position = 0;
    while (true)
    {
        size_t nextSpace = s.find(' ', position);
        if (nextSpace >= s.size())
        {
            break;
        }

        elements.emplace_back(std::stoi(
                s.substr(position, nextSpace - position)));
        position = nextSpace + 1;
    }
    elements.shrink_to_fit();

    normalize();
}

void Permutation::Cycle::print() const
{
    std::cout << "(";
    for (size_t i = 0; i < elements.size() - 1; i++)
        std::cout << elements[i] << " ";
    std::cout << elements.back();
    std::cout << ")";
}

void Permutation::Cycle::normalize()
{
    std::rotate(elements.begin(), std::min_element(elements.begin(), elements.end()), elements.end());
}

int Permutation::Cycle::get(int k) const
{
    auto pos = find(elements.begin(), elements.end(), k);
    if (pos + 1 == elements.end())
    {
        return *elements.begin();
    }
    else
    {
        return *(pos + 1);
    }
}

int Permutation::Cycle::getMax() const
{
    return *max_element(elements.begin(), elements.end());
}

const vector<int> &Permutation::Cycle::getElements() const
{
    return elements;
}

Permutation::Cycle::Cycle(vector<int> vec) : elements(std::move(vec))
{
    normalize();
}

Permutation::Cycle::Cycle() {}

