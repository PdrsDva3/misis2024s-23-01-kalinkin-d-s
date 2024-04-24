#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklstt/stacklstt.hpp>

TEST_CASE("Type integer"){
    StackLstT<int> stack;
    for (int i = 1; i <= 100; i++){
        stack.Push(i);
    }
    CHECK_EQ(stack.Top(), 100);
    for (int i = 1; i <= 100; i++){
        stack.Pop();
    }
    CHECK(stack.IsEmpty());
    CHECK_NOTHROW(stack.Pop());

}

