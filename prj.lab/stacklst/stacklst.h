#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
#include <complex/complex.h>
#include <cstddef>
#include <iosfwd>


class StackLst{
public:
    StackLst() = default;
    StackLst(const StackLst&);
    ~StackLst();

    void Pop();// 4
    void Push(const Complex& elem);// 2
    bool IsEmpty();// 1
    Complex& Top();// 3
    [[nodiscard]] const Complex& Top() const;// 3.1

    void Clear();
    StackLst& operator=(const StackLst& obj);

private:
    struct Node{
        Complex val;
        Node* next = nullptr;
    };

Node* head_ = nullptr;
};


#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
