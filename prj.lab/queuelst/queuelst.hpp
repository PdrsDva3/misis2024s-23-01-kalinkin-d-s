#ifndef MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
#define MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H

#include "complex/complex.hpp"


class QueueLst {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& rhs);
    ~QueueLst();

    void Pop() noexcept;
    void Push(const Complex& elem);
    bool IsEmpty() const noexcept;

    Complex& Top();
    const Complex& Top() const;

    void Clear();
    QueueLst& operator=(const QueueLst& rhs);


    QueueLst(QueueLst&& rhs) noexcept;
    QueueLst& operator=(QueueLst&& rhs) noexcept;

private:
    struct Node{
        Complex val_;
        Node* next_ = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;

};


#endif //MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
