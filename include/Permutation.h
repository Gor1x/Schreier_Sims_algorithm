#ifndef SCHREIER_SIMS_ALGORITHM_PERMUTATION_H
#define SCHREIER_SIMS_ALGORITHM_PERMUTATION_H

#include <cstddef>
#include <vector>
#include <algorithm>

using std::vector;

class Permutation
{
private:
    class Cycle;
public:
    friend class SchreierSimsTest;

    explicit Permutation(size_t length = 0);

    Permutation(const std::string &s);

    Permutation(const Cycle &cycle);

    size_t operator()(size_t k) const;

    int get(int k) const;

    Permutation &pow(int n);

    Permutation &inverse();

    int size() const;

    friend Permutation operator*(const Permutation &, const Permutation &);

    vector<Cycle> getCycles() const;

    std::string toString() const;

    void print() const;

    void swap(Permutation &other);

private:
    void fillNextVectorToId();

    void set(int where, int what);

    size_t length;
    vector<int> next;
};

class Permutation::Cycle
{
public:
    Cycle();

    Cycle(std::string s);

    Cycle(vector<int> vector);

    int get(int k) const;

    int getMax() const;

    const vector<int> &getElements() const;

    void print() const;

    std::string toString() const;

private:

    void normalize();

    vector<int> elements;
};

#endif //SCHREIER_SIMS_ALGORITHM_PERMUTATION_H
