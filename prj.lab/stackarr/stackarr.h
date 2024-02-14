//
// Created by Lol on 06.02.2024.
//

#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H

#include <complex/complex.h>
#include <cstddef>
#include <iostream>


class StackArr{
public:
    [[nodiscard]] StackArr() = default;
    [[nodiscard]] StackArr(const StackArr&);
    ~StackArr() {delete[] data_;}

    [[nodiscard]] StackArr& operator=(const StackArr& obj);
    void Push(const Complex&);
    void Pop() noexcept;
    [[nodiscard]] bool IsEmpty() noexcept;

    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;



private:
    Complex* data_ = nullptr;
    std::ptrdiff_t capacity_ = 0;
    int top_ind_ = -1;
    int Size() const {return top_ind_ + 1;}
};


#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H
