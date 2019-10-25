#include <assert.h>
#include "../bitset.hpp"

int main()
{
    auto set = new Bitset(100);

    assert(set->has(0) == false);

    set->add(32);
    set->add(45);
    assert(set->has(32));
    assert(set->has(45));
}