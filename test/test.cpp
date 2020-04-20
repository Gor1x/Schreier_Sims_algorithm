#include <cassert>
#include "Permutation.h"

void testCreating()
{
    Permutation permutation(6);
    assert(permutation(3) == -1);
}

int main()
{
    testCreating();
}