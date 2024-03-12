#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H

#include "complex/complex.hpp"
#include <cstddef>
#include <iosfwd>


class StackLst{
public:
    StackLst() = default;
    StackLst(const StackLst& rhs);
    ~StackLst();

    void Pop();
    void Push(const Complex& elem);
    [[nodiscard]] bool IsEmpty() const noexcept;
    Complex& Top();
    [[nodiscard]] const Complex& Top() const;

    void Clear();
    StackLst& operator=(const StackLst& rhs) noexcept;

private:
    struct Node{
        Complex val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};


#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
