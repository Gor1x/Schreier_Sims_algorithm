#include <iostream>
#include <vector>

#include "Permutation.h"
#include "SchreierTree.h"

using namespace std;

int main()
{
    auto generators = vector<Permutation>({
                                                  Permutation("(1 2 3)"),
                                                  Permutation("(1 3 4)"),
                                                  Permutation("(2 4 3)")
                                          });
    SchreierTree tree(generators, 1);
    tree.print();

    cout << tree.getWay(4).toString();
    return 0;
}