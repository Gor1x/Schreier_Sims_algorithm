#ifndef SCHREIER_SIMS_ALGORITHM_SCHREIERSIMSTEST_H
#define SCHREIER_SIMS_ALGORITHM_SCHREIERSIMSTEST_H

#include "Test.h"
#include "Permutation.h"

class SchreierSimsTest : Test
{
public:
    void runAllTests() override;

private:
    static void stringConstructor1();

    static void stringConstructor2();

    static void multiply1();

    static void multiply2();

    static void multiply3();

    static void pow1();

    static void pow2();

    static void pow3();

    static void pow4();

    static void pow5();

    static void powNegative1();

    static void powNegative2();

    static void powNegative3();


};


#endif //SCHREIER_SIMS_ALGORITHM_SCHREIERSIMSTEST_H
