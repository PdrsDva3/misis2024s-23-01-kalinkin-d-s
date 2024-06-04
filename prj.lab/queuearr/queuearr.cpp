#include "queuearr.hpp"

void QueueArr::recapacity(const std::ptrdiff_t n_capacity){
    Complex* oldData = data_;
    data_ = new Complex[n_capacity];
    for (std::ptrdiff_t i = 0; i < size_; i++){
        data_[i] = oldData[(i + head_) % capacity_];
    }
    tail_ = size_ - 1;
    capacity_ = n_capacity;
    head_ = 0;
    delete[] oldData;
}

const bool QueueArr::isfull() const noexcept{
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
        throw std::out_of_range("Queue is empty");
    else
        return data_[head_];
}


const Complex& QueueArr::Top() const {
    if (IsEmpty())
        throw std::out_of_range("Queue is empty");
    else
        return data_[head_];
}


void QueueArr::Clear() noexcept {
    if (size_ != 0){
        for (int i = 0; i < size_; i++){
            data_[i] = Complex(0);
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

void QueueArr::Push(const Complex& val) {
    if (Size() == capacity_) {
        int new_capacity_ = (capacity_ != 0 ? 2 * capacity_ : 10);
        Complex* new_mass_ = new Complex[new_capacity_];
        int new_begin = 0;
        int new_end = Size();

        if (head_ < tail_)
            std::copy(data_ + head_, data_ + tail_, new_mass_);
        if (head_ > tail_)
        {
            std::copy(data_ + head_, data_ + capacity_, new_mass_);
            std::copy(data_, data_ + tail_, new_mass_ + (capacity_ - head_));
        }

        head_ = new_begin;
        tail_ = new_end;
        capacity_ = new_capacity_;
        if (data_ != nullptr)
            delete[] data_;
        data_ = new_mass_;
    }
    if (tail_ == capacity_)
    {
        tail_ = 1;
        data_[0] = val;
    }
    else
    {
        data_[tail_] = val;
        tail_++;
    }
}
    
QueueArr::QueueArr(QueueArr&& rhs) noexcept
        : data_(rhs.data_), capacity_(rhs.capacity_), head_(rhs.head_), tail_(rhs.tail_), size_(rhs.size_) {
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.head_ = -1;
    rhs.tail_ = -1;
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
