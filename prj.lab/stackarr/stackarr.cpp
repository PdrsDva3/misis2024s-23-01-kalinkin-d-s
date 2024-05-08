#include "stackarr.hpp"


StackArr::StackArr(const StackArr& rhs)
: top_ind_(rhs.top_ind_), capacity_(rhs.Size()) {
    data_ = new Complex[capacity_];
    for (int i = 0; i < rhs.Size(); i++) {
        data_[i] = rhs.data_[i];
    }
}


StackArr& StackArr::operator=(const StackArr& obj) {
    if (this != &obj) {
        if (capacity_ != obj.capacity_) {
            delete[] data_;
            capacity_ = obj.capacity_;
            data_ = new Complex[capacity_];
            if (!data_) {
                throw std::bad_alloc();
            }
        }
        std::copy(obj.data_, obj.data_ + obj.top_ind_ + 1, data_);
        top_ind_ = obj.top_ind_;
    }
    return *this;
}


void StackArr::Pop() noexcept {
    if (top_ind_ >= 0){
        top_ind_ -= 1;
    }
}

bool StackArr::IsEmpty() noexcept {
    return (top_ind_ == -1);
}


Complex& StackArr::Top(){
    if (top_ind_ != -1){
        return data_[top_ind_];
    }
    else{
        throw std::runtime_error("Stack is null");
    }
}


const Complex& StackArr::Top() const{
    if (top_ind_ != -1){
        return data_[top_ind_];
    }
    else{
        throw std::runtime_error("Stack is null");
    }
}

void StackArr::Push(const Complex& element) {
    if (top_ind_ + 1 == capacity_) {
        capacity_ = 2 * capacity_ + 1;
        Complex* newStack = new Complex[capacity_];
        for (int i = 0; i <= top_ind_; i++) {
            newStack[i] = data_[i];
        }
        delete[] data_;
        data_ = newStack;
    }
    top_ind_ += 1;
    data_[top_ind_] = element;
}


void StackArr::Clear() noexcept {
    if (top_ind_ != 0) {
        for (int i = 0; i <= top_ind_; i++) {
            data_[i] = {0, 0};
        }
        top_ind_ = -1;
    }
}

StackArr::StackArr(StackArr&& rhs) noexcept
        : data_(rhs.data_), capacity_(rhs.capacity_), top_ind_(rhs.top_ind_) {
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.top_ind_ = -1;
}


StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(top_ind_, rhs.top_ind_);
    return *this;
}
