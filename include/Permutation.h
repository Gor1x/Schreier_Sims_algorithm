#ifndef SCHREIER_SIMS_ALGORITHM_PERMUTATION_H
#define SCHREIER_SIMS_ALGORITHM_PERMUTATION_H

#include <cstddef>
#include <vector>

using std::vector;

class Permutation
{
public:
    /**
     * @brief Создание объекта перестановки длины length
     * @param length Длина перестановки, количество элементов в ней.
     */
    explicit Permutation(size_t length);

    /**
     * @param k Некоторый элемент перестановки
     * @return Возвращает число, в которое переходит @_a k
     */
    int operator()(int k);

    /**
     * @brief Перемножение перестановок слева направо
     * @param other Второй аргумент умножения
     * @return Результат умножения
     */
    Permutation operator*(const Permutation &other) const;

private:
    vector<int> next;
    size_t length;
};


#endif //SCHREIER_SIMS_ALGORITHM_PERMUTATION_H
