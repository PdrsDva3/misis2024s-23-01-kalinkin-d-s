#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklstt/stacklstt.hpp>

TEST_CASE("Pusing int"){
    StackLstT<int> a;
    a.Push(3);
    a.Push(2);
    a.Push(1);
    CHECK(a.Pop() == 3);

}

