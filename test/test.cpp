#include <cassert>
#include "Permutation.h"

void testCreating()
{
    Permutation permutation(6);
    assert(permutation(3) == 3);
}

int main()
{
    testCreating();
}