#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"
#include "SchreierStabChain.h"

using namespace std;

int main()
{
    SchreierStabChain stabChain(5, {"(1 2)"});
    cout << stabChain.getSize();
    return 0;
}