#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "complex\complex.h"
#include <iostream>

TEST_CASE("complex ctor"){
    Complex first;

    CHECK(0.0 == first.realf());
    CHECK(0.0 == first.imagf());

    Complex second({1.0, 8.0});
    Complex third({9});

//    CHECK();
}