#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H

#include "complex/complex.hpp"
#include <cstddef>
#include <iosfwd>


class StackLst{
public:
    StackLst() = default;
    StackLst(const StackLst& rhs);//!
    ~StackLst();//!

    void Pop();//2
    void Push(const Complex& elem);//2
    [[nodiscard]] bool IsEmpty() const noexcept;//2
    Complex& Top();//2
    [[nodiscard]] const Complex& Top() const;//2

    void Clear();//2
    StackLst& operator=(const StackLst& rhs) noexcept;//!

    StackLst& operator=(StackLst&& rhs) noexcept;//!
    StackLst(StackLst&& rhs) noexcept;//!

private:
    struct Node{
        Complex val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};


#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
