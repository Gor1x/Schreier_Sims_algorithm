#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"
#include "SchreierStabChain.h"

using namespace std;

int main()
{
    SchreierStabChain stabChain(5, {"(1 2)", "(1 3)"});
    cout << stabChain.getSize() << " " << stabChain.getBaseSize();
    return 0;
}