#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"
#include "SchreierStabChain.h"

using namespace std;

int main()
{
    SchreierStabChain stabChain(5, {"(1 2)", "(4 5)", "(1 4)"});
    cout << stabChain.getSize() << " " << stabChain.getBaseSize() << std::endl;
    cout << stabChain.hasPermutation("(2 4)");
    //stabChain.printAllGroup();
    return 0;
}