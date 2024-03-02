#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.h>


TEST_CASE("Testing QueueLst functionality") {
    QueueLst queue;

    SUBCASE("Queue is initially empty") {
        CHECK(queue.IsEmpty() == true);
    }

    SUBCASE("Pushing items") {
        queue.Push(Complex(1, 2));
        CHECK(queue.IsEmpty() == false);
        CHECK(queue.Top() == Complex(1, 2));

        queue.Push(Complex(3, 4));
        CHECK(queue.Top() == Complex(1, 2));
    }

    SUBCASE("Popping items") {
        queue.Push(Complex(1, 2));
        queue.Push(Complex(3, 4));
        queue.Pop();
        CHECK(queue.Top() == Complex(3, 4));
        queue.Pop();
        CHECK(queue.IsEmpty() == true);
    }

    SUBCASE("Clearing queue") {
        queue.Push(Complex(1, 2));
        queue.Push(Complex(3, 4));
        queue.Clear();
        CHECK(queue.IsEmpty() == true);
    }

    SUBCASE("Copying queue with constructor") {
        queue.Push(Complex(5, 6));
        QueueLst queueCopy(queue);
        CHECK(queueCopy.IsEmpty() == false);
        CHECK(queueCopy.Top() == Complex(5, 6));
    }

    SUBCASE("Copying queue with assignment operator") {
        queue.Push(Complex(7, 8));
        QueueLst queueCopy;
        queueCopy = queue;
        CHECK(queueCopy.IsEmpty() == false);
        CHECK(queueCopy.Top() == Complex(7, 8));
    }

    SUBCASE("Self-assignment") {
        queue.Push(Complex(9, 10));
        queue = queue;
        CHECK(queue.IsEmpty() == false);
        CHECK(queue.Top() == Complex(9, 10));
    }

    SUBCASE("Pop from empty queue") {
        queue.Pop();
        CHECK(queue.IsEmpty() == true);
    }

    SUBCASE("Top from empty queue") {
        bool caughtException = false;
        try {
            Complex Top = queue.Top();
        } catch (...) {
            caughtException = true;
        }
        CHECK(caughtException == true);
    }
}


TEST_CASE("Advanced testing of QueueLst functionality") {
    SUBCASE("Stress test for Push and Pop operations") {
        QueueLst queue;
        int n = 10000;
        for (int i = 0; i < n; ++i) {
            queue.Push(Complex(i, i));
        }
        CHECK(queue.IsEmpty() == false);
        for (int i = 0; i < n; ++i) {
            queue.Pop();
        }
        CHECK(queue.IsEmpty() == true);
    }

    SUBCASE("Copy constructor under heavy load") {
        QueueLst queue;
        int n = 10000; // Количество элементов для добавления
        for (int i = 0; i < n; ++i) {
            queue.Push(Complex(i, i));
        }
        QueueLst queueCopy(queue);
        CHECK(queueCopy.IsEmpty() == false);
        for (int i = 0; i < n; ++i) {
            Complex expected(i, i);
            CHECK(queueCopy.Top() == expected);
            queueCopy.Pop();
        }
        CHECK(queueCopy.IsEmpty() == true);
    }

    SUBCASE("Assignment operator under heavy load") {
        QueueLst queue;
        int n = 10000;
        for (int i = 0; i < n; ++i) {
            queue.Push(Complex(i, i));
        }
        QueueLst queueCopy;
        queueCopy = queue;
        CHECK(queueCopy.IsEmpty() == false);
        for (int i = 0; i < n; ++i) {
            Complex expected(i, i);
            CHECK(queueCopy.Top() == expected);
            queueCopy.Pop();
        }
        CHECK(queueCopy.IsEmpty() == true);
    }

    SUBCASE("Consistency check after multiple operations") {
        QueueLst queue;
        int n = 5000;
        for (int i = 0; i < n; ++i) {
            queue.Push(Complex(i, i));
            if (i % 2 == 0) {
                queue.Pop();
            }
        }
        CHECK(queue.IsEmpty() == false);
        for (int i = n / 2; i < n; ++i) {
            Complex expected(i, i);
            CHECK(queue.Top() == expected);
            queue.Pop();
        }
        CHECK(queue.IsEmpty() == true);
    }
}
