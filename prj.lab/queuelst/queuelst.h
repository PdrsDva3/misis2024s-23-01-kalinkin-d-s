#ifndef MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
#define MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H

#include <complex/complex.h>
#include <cstddef>
#include <iosfwd>


class QueueLst {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& rhs);
    ~QueueLst();

    void Pop();
    void Push(const Complex& elem);
    bool IsEmpty() const noexcept;

    Complex& Top();
    const Complex& Top() const;

    void Clear();
    QueueLst& operator=(const QueueLst& rhs);

private:
    struct Node{
        Complex val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;

};


#endif //MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
