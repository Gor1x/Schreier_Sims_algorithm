#include "SchreierSimsTest.h"
#include <Permutation.h>
#include <iostream>

void SchreierSimsTest::runAllTests()
{
    std::cout << std::endl;

    stringConstructor1();
    stringConstructor2();

    multiply1();
    multiply2();
    multiply3();

    pow1();
    pow2();
    pow3();
    pow4();
    pow5();

    powNegative1();
    powNegative2();
    powNegative3();

    showFinalResult();
}

void SchreierSimsTest::multiply1()
{
    Permutation first("(1 2 3)");
    Permutation second("(3 2 1)");
    DO_CHECK((first * second).toString() == "id");
}

void SchreierSimsTest::multiply2()
{
    Permutation first("(1 2 3)");
    Permutation second("(3 4 2)");
    DO_CHECK((first * second).toString() == "(1 2)(3 4)");
}

void SchreierSimsTest::multiply3()
{
    Permutation first("(11 10 6 8)");
    Permutation second("(5 8 6 3)");
    DO_CHECK((first * second).toString() == "(3 5 11 10 6)");
}

void SchreierSimsTest::pow1()
{
    Permutation perm("(1 2)");
    DO_CHECK(perm.pow(1e9).toString() == "id");
}

void SchreierSimsTest::pow2()
{
    Permutation perm("(1 2 3)");
    DO_CHECK(perm.pow(1).toString() == "(1 2 3)");
}

void SchreierSimsTest::pow3()
{
    Permutation perm("(1 2 3)");
    DO_CHECK(perm.pow(2).toString() == "(1 3 2)");
}

void SchreierSimsTest::pow4()
{
    Permutation perm("(1 2)");
    DO_CHECK(perm.pow(1e9 + 1).toString() == "(1 2)");
}

void SchreierSimsTest::pow5()
{
    Permutation perm("(1 2 3)");
    DO_CHECK(perm.pow(3).toString() == "id");
}

void SchreierSimsTest::stringConstructor2()
{
    Permutation perm("(1 2 3)(3 2 1)(1 2)(2 1)(4 5 6 7)(7 6 5 4)");
    DO_CHECK(perm.toString() == "id");
}

void SchreierSimsTest::stringConstructor1()
{
    Permutation perm("(1)");
    DO_CHECK(perm.toString() == "id");
}

void SchreierSimsTest::powNegative1()
{
    Permutation perm("(1 2 3)");
    DO_CHECK(perm.pow(-1).toString() == "(1 3 2)");
}

void SchreierSimsTest::powNegative2()
{
    Permutation perm("(2 4 3 5)");
    DO_CHECK(perm.pow(-2).toString() == "(2 3)(4 5)");
}

void SchreierSimsTest::powNegative3()
{
    Permutation perm("(1 10 2)");
    DO_CHECK(perm.pow(-1e9).toString() == "(1 2 10)");
}





