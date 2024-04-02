#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>

TEST_CASE("QueueList ctor") {
    QueueLst queue;

    CHECK(queue.IsEmpty());

    Complex first_complex(1, 1);

    queue.Push(first_complex);

    queue.Pop();

    CHECK(queue.IsEmpty());

    CHECK_THROWS(queue.Top());

    queue.Push(first_complex);

    CHECK_FALSE(queue.IsEmpty());
    CHECK(queue.Top() == first_complex);

    Complex second_complex(2, 2);

    queue.Push(second_complex);

    CHECK(queue.Top() == first_complex);

    queue.Pop();
}

static const Complex a(1, 2);
static const Complex b(1, 3);
static const Complex c(2, 3);

TEST_CASE("time test") {
    long long diff = 0;

    QueueLst queue1;
    for (int i = 0; i < 10000; i++) {
        queue1.Push(a);
    }
    auto start = std::chrono::steady_clock::now();
    QueueLst queue2(queue1);
    auto end = std::chrono::steady_clock::now();
    CHECK_EQ(queue2.Top(), a);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    diff = duration.count();

    start = std::chrono::steady_clock::now();
    QueueLst queue3(std::move(queue1));
    end = std::chrono::steady_clock::now();
    CHECK_EQ(queue3.Top(), a);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    diff -= duration.count();

    CHECK(diff > duration.count() * 10);

    QueueLst queue4;
    for (int i = 0; i < 10000; i++) {
        queue4.Push(a);
    }
    QueueLst queue5;
    start = std::chrono::steady_clock::now();
    queue5 = queue4;
    end = std::chrono::steady_clock::now();
    CHECK_EQ(queue5.Top(), a);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    diff = duration.count();

    start = std::chrono::steady_clock::now();
    QueueLst queue6 = std::move(queue4);
    end = std::chrono::steady_clock::now();
    CHECK_EQ(queue6.Top(), a);
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    diff -= duration.count();

    CHECK(diff > duration.count() * 10);
}