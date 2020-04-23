#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"

using namespace std;

int main()
{

    SchreierTree tree({"(1 2 3)", "(1 3 4)", "(2 4 3)"}, 1);
    tree.print();

    cout << tree.getWay(4).toString();
    return 0;
}