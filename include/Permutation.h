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
    /**
     * @brief Создание объекта перестановки длины length
     * @param length Длина перестановки, количество элементов в ней.
     */
    explicit Permutation(size_t length = 0);

    Permutation(const std::string &s);

    Permutation(const Cycle &cycle);

    /**
     * @param k Некоторый элемент перестановки
     * @return Возвращает число, в которое переходит @_a k
     */
    int operator()(int k) const;

    int get(int k) const;

    /**
     * @return Длина перестановки
     */
    int size() const;

    friend Permutation operator*(const Permutation &, const Permutation &);

    void print();

    void swap(Permutation &other);

private:
    void set(int where, int what);

    int length;
    vector<int> next;
};

class Permutation::Cycle
{
public:
    Cycle(std::string s);

    int get(int k) const;

    int getMax() const;

    const vector<int> &getElements() const;

private:
    void print() const;

    void normalize();

    vector<int> elements;
};

#endif //SCHREIER_SIMS_ALGORITHM_PERMUTATION_H
