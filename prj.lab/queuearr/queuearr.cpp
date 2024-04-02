#include "queuearr.hpp"

bool QueueArr::isfull() {
    if ((head_ == tail_-1) || (head_ == 0 && tail_ == size_-1))
        return true;
    return false;
}

int QueueArr::Size() const noexcept {
    return size_;
}

bool QueueArr::IsEmpty() const noexcept {
    return size_ == 0;
}

Complex& QueueArr::Top() {
    if (IsEmpty())
        throw std::logic_error("Queue is empty");
    else
        return data_[head_];
}


const Complex& QueueArr::Top() const {
    if (IsEmpty())
        throw std::logic_error("Queue is empty");
    else
        return data_[head_];
}


void QueueArr::Clear() noexcept {
    if (size_ != 0){
        for (int i = 0; i < size_; i++){
            data_[i] = {0, 0};
        }
        head_ = -1;
        tail_ = -1;
    }
}