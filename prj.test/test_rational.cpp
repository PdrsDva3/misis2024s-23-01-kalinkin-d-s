#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <rational/rational.h>

TEST_CASE("rational ctor"){
    Rational first;
    CHECK(0 == first.num());
    CHECK(1 == first.den());

    Rational second(2);
    CHECK(2 == second.num());
    CHECK(1 == second.den());

    Rational third(36, 42);
    CHECK(6 == third.num());
    CHECK(7 == third.den());

    //=================================

    Rational fourth(1, 9);
    Rational ans;
    ans = third + fourth;
    CHECK(61 == ans.num());
    CHECK(63 == ans.den());

    ans = second + fourth;
    CHECK(19 == ans.num());
    CHECK(9 == ans.den());

    ans = fourth + second;
    CHECK(19 == ans.num());
    CHECK(9 == ans.den());

    third += fourth;
    CHECK(61 == third.num());
    CHECK(63 == third.den());

    third += second;
    CHECK(187 == third.num());
    CHECK(63 == third.den());

    second += third;
    CHECK(313 == second.num());
    CHECK(63 == second.den());

    //=================================

    Rational mt1(3, 7);
    Rational mt2(2, 9);
    Rational mt3(5);
    Rational res;

    res = mt1 * mt2;
    CHECK(2 == res.num());
    CHECK(21 == res.den());

    res = mt1 * mt3;
    CHECK(15 == res.num());
    CHECK(7 == res.den());

    res = mt3 * mt1;
    CHECK(15 == res.num());
    CHECK(7 == res.den());

    mt1*= mt2;
    CHECK(2 == mt1.num());
    CHECK(21 == mt1.den());

    mt2*= mt3;
    CHECK(10 == mt2.num());
    CHECK(9 == mt2.den());

    mt3 *= mt1;
    CHECK(10 == mt3.num());
    CHECK(21 == mt3.den());

    //==================================

    Rational del1(2, 3);
    Rational del2(3, 7);
    Rational del3(4);

    res = del1 / del2;
    CHECK(14 == res.num());
    CHECK(9 == res.den());

    res = del1 / del3;
    CHECK(1 == res.num());
    CHECK(6 == res.den());

    res = del3 / del2;
    CHECK(28 == res.num());
    CHECK(3 == res.den());

    del1 /= del2;
    CHECK(14 == del1.num());
    CHECK(9 == del1.den());

    del2 /= del3;
    CHECK(3 == del2.num());
    CHECK(28 == del2.den());

    del3 /= del1;
    CHECK(18 == del3.num());
    CHECK(7 == del3.den());

    //==============================
    Rational ded1(1, 3);
    Rational ded2(2, 5);
    Rational ded3(2);
    bool logic;

    logic = ded1 > ded2;
    CHECK(false == logic);

    logic = ded3 > ded2;
    CHECK(true == logic);

    Rational ded11(1, 3);
    logic = (ded1 == ded11);
    CHECK(true == logic);

    //ded1 = 1/3; ded2 = 2/5; ded3 = 2 !!! <----
    res = ded1 - ded2;
    CHECK(-1 == res.num());
    CHECK(15 == res.den());

    res = ded2 - ded3;
    CHECK(-8 == res.num());
    CHECK(5 == res.den());

    res = ded3 - ded1;
    CHECK(5 == res.num());
    CHECK(3 == res.den());
    
}