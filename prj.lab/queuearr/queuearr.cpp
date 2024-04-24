#include "queuearr.hpp"

void QueueArr::recapacity(int n_capacity){
    Complex* n_data = new Complex[n_capacity];
    int temp = 0;
    while (head_ != tail_){
        ++head_;
        ++temp;
        n_data[temp] = data_[head_ % capacity_];
    }
    head_ = 0;
    tail_ = size_ - 1;
    delete data_;
    data_ = n_data;
}

bool QueueArr::isfull() noexcept{
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
        size_ = 0;
    }
}

QueueArr::QueueArr(const QueueArr& rhs)
    : capacity_(rhs.capacity_), size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_)
{
    data_ = new Complex[capacity_];
    for (int i = 0; i < size_; i++) {
        data_[i] = rhs.data_[i];
    }
}

void QueueArr::Pop() noexcept {
    if (!IsEmpty()){
        if (head_ == tail_){
            head_ = -1;
            tail_ = -1;
        }else{
            head_++;
            if (head_ + 1 > capacity_)
                head_ = 0;
        }
        size_ --;
    }
}

void QueueArr::Push(const Complex& rhs){
    if (isfull())
        recapacity(capacity_ * 2);
    tail_ = (tail_ + 1) % capacity_;
    data_[tail_] = rhs;

    size_ += 1;
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept
        : data_(rhs.data_), capacity_(rhs.capacity_), head_(rhs.head_), tail_(rhs.tail_), size_(rhs.size_) {
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.head_ = 0;
    rhs.tail_ = 0;
    rhs.size_ = 0;
}


QueueArr &QueueArr::operator=(QueueArr&& rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(size_, rhs.size_);
    return *this;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) noexcept{
    if (rhs.Size() > capacity_) {
        delete[] data_;
        data_ = new Complex[rhs.Size()];

    }
    for (std::ptrdiff_t i = 0; i < rhs.Size(); i++){
        data_[i] = rhs.data_[(i + rhs.head_) % rhs.Size()];
    }
    capacity_ = rhs.Size();
    tail_ = size_ - 1;
    head_ = 0;
    size_ = rhs.Size();
    return *this;
}
