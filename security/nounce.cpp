#include <cstdlib>
#include "nounce.h"

int Nonce::generate()
{
    return rand() % 10000 + 1;
}