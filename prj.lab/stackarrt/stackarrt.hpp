//
// Created by Lol on 06.02.2024.
//

#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H


#include <cstddef>
#include <iostream>

template<class T>
class StackArrT {
public:
    StackArrT() = default;

    StackArrT(const StackArrT &);

    ~StackArrT() { delete[] data_; }

    StackArrT &operator=(const StackArrT &obj);

    void Push(const T &);

    void Pop() noexcept;

    bool IsEmpty() noexcept;

    T &Top();

    [[nodiscard]] const T &Top() const;

    void Clear() noexcept;

    StackArrT(StackArrT &&rhs) noexcept;

    StackArrT &operator=(StackArrT &&rhs) noexcept;


private:
    T *data_ = nullptr;
    std::ptrdiff_t capacity_ = 0;
    int top_ind_ = -1;

    int Size() const { return top_ind_ + 1; }
};


template<class T>
StackArrT<T>::StackArrT(const StackArrT &rhs)
        : top_ind_(rhs.top_ind_), capacity_(rhs.Size()) {
    data_ = new T[capacity_];
    for (int i = 0; i < rhs.Size(); i++) {
        data_[i] = rhs.data_[i];
    }
}


template<class T>
StackArrT<T> &StackArrT<T>::operator=(const StackArrT &obj) {
    if (this != &obj) {
        if (capacity_ != obj.capacity_) {
            delete[] data_;
            capacity_ = obj.capacity_;
            data_ = new T[capacity_];
            if (!data_) {
                throw std::bad_alloc();
            }
        }
        std::copy(obj.data_, obj.data_ + obj.top_ind_ + 1, data_);
        top_ind_ = obj.top_ind_;
    }
    return *this;
}


template<class T>
void StackArrT<T>::Pop() noexcept {
    if (top_ind_ >= 0) {
        top_ind_ -= 1;
    }
}

template<class T>
bool StackArrT<T>::IsEmpty() noexcept {
    return (top_ind_ == -1);
}


template<class T>
T &StackArrT<T>::Top() {
    if (top_ind_ != -1) {
        return data_[top_ind_];
    } else {
        throw std::runtime_error("Stack is null");
    }
}


template<class T>
const T &StackArrT<T>::Top() const {
    if (top_ind_ != -1) {
        return data_[top_ind_];
    } else {
        throw std::runtime_error("Stack is null");
    }
}


template<class T>
void StackArrT<T>::Push(const T &element) {
    if (top_ind_ + 1 == capacity_) {
        capacity_ = 2 * capacity_ + 1;
        T *newStack = new T[capacity_];
        for (int i = 0; i <= top_ind_; i++) {
            newStack[i] = data_[i];
        }
        delete[] data_;
        data_ = newStack;
    }
    top_ind_ += 1;
    data_[top_ind_] = element;
}


template<class T>
void StackArrT<T>::Clear() noexcept {
    if (top_ind_ != 0) {
        for (int i = 0; i <= top_ind_; i++) {
            data_[i] = {0, 0};
        }
        top_ind_ = -1;
    }
}


template<class T>
StackArrT<T>::StackArrT(StackArrT &&rhs) noexcept
        : data_(rhs.data_), capacity_(rhs.capacity_), top_ind_(rhs.top_ind_) {
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.top_ind_ = -1;
}


template<class T>
StackArrT<T> &StackArrT<T>::operator=(StackArrT &&rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(top_ind_, rhs.top_ind_);
    return *this;
}


#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKARR_H
