#ifndef QUEUEARR
#define QUEUEARR

#include <stdexcept>

template<class T>
class QueueArrT {
public:
    QueueArrT() = default;//! done
    ~QueueArrT() { delete[] data_; }//! done

    QueueArrT(const QueueArrT &rhs);//! done        только при инициализации
    QueueArrT(QueueArrT &&rhs) noexcept;//!  done   только при инициализации

    QueueArrT &operator=(const QueueArrT &rhs) noexcept;//!  done
    QueueArrT &operator=(QueueArrT &&rhs) noexcept;//!  done

    void Push(const T &rhs);//!  done
    void Pop() noexcept;//! done

    T &Top();//! done
    const T &Top() const;//! done

    void Clear() noexcept;//! done
    int Size() const noexcept;//! done
    bool IsEmpty() const noexcept;//! done

private:
    void recapacity(int n_capacity);

    bool isfull() noexcept;

    int head_ = -1;
    int tail_ = -1;

    int size_ = 0;
    int capacity_ = 0;

    T *data_ = nullptr;
};

//-------------------реализация

template<class T>
void QueueArrT<T>::recapacity(int n_capacity) {
    T *n_data = new T[n_capacity];
    int temp = 0;
    while (head_ != tail_) {
        ++head_;
        ++temp;
        n_data[temp] = data_[head_ % capacity_];
    }
    head_ = 0;
    tail_ = size_ - 1;
    delete data_;
    data_ = n_data;
}

template<class T>
bool QueueArrT<T>::isfull() noexcept {
    if ((head_ == tail_ - 1) || (head_ == 0 && tail_ == size_ - 1))
        return true;
    return false;
}

template<class T>
int QueueArrT<T>::Size() const noexcept {
    return size_;
}

template<class T>
bool QueueArrT<T>::IsEmpty() const noexcept {
    return size_ == 0;
}


template<class T>
T &QueueArrT<T>::Top() {
    if (IsEmpty())
        throw std::logic_error("Queue is empty");
    else
        return data_[head_];
}

template<class T>
const T &QueueArrT<T>::Top() const {
    if (IsEmpty())
        throw std::logic_error("Queue is empty");
    else
        return data_[head_];
}

template<class T>
void QueueArrT<T>::Clear() noexcept {
    if (size_ != 0) {
        for (int i = 0; i < size_; i++) {
            data_[i] = {0, 0};
        }
        head_ = -1;
        tail_ = -1;
        size_ = 0;
    }
}

template<class T>
QueueArrT<T>::QueueArrT(const QueueArrT &rhs)
        : capacity_(rhs.capacity_), size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_) {
    data_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        data_[i] = rhs.data_[i];
    }
}

template<class T>
void QueueArrT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ == tail_) {
            head_ = -1;
            tail_ = -1;
        } else {
            head_++;
            if (head_ + 1 > capacity_)
                head_ = 0;
        }
        size_--;
    }
}

template<class T>
void QueueArrT<T>::Push(const T &rhs) {
    if (isfull())
        recapacity(capacity_ * 2);
    tail_ = (tail_ + 1) % capacity_;
    data_[tail_] = rhs;

    size_ += 1;
}

template<class T>
QueueArrT<T>::QueueArrT(QueueArrT &&rhs) noexcept
        : data_(rhs.data_), capacity_(rhs.capacity_), head_(rhs.head_), tail_(rhs.tail_), size_(rhs.size_) {
    rhs.data_ = nullptr;
    rhs.capacity_ = 0;
    rhs.head_ = 0;
    rhs.tail_ = 0;
    rhs.size_ = 0;
}

template<class T>
QueueArrT<T> &QueueArrT<T>::operator=(QueueArrT &&rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(size_, rhs.size_);
    return *this;
}

template<class T>
QueueArrT<T> &QueueArrT<T>::operator=(const QueueArrT &rhs) noexcept {
    if (rhs.Size() > capacity_) {
        delete[] data_;
        data_ = new T[rhs.Size()];

    }
    for (std::ptrdiff_t i = 0; i < rhs.Size(); i++) {
        data_[i] = rhs.data_[(i + rhs.head_) % rhs.Size()];
    }
    capacity_ = rhs.Size();
    tail_ = size_ - 1;
    head_ = 0;
    size_ = rhs.Size();
    return *this;
}

#endif
