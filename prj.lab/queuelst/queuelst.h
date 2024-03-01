#ifndef MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
#define MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H

#include <complex/complex.h>
#include <cstddef>
#include <iosfwd>


class QueueLst {
    QueueLst() = default;
    QueueLst(const QueueLst&);
    ~QueueLst();

    void Pop();// 4
    void Push(const Complex& elem);// 2
    bool IsEmpty();// 1
    Complex& Top();// 3
    const Complex& Top() const;// 3.1

    void Clear();
    QueueLst& operator=(const QueueLst& obj);

private:
    struct Node{
        Complex val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;

};


#endif //MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
