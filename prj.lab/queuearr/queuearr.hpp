#ifndef QUEUEARR
#define QUEUEARR

#include <stdexcept>
#include "complex/complex.hpp"

class QueueArr {
public:
    QueueArr() = default;//! done
    ~QueueArr() {delete[] data_;}

    QueueArr(QueueArr&& rhs) noexcept;
    QueueArr(const QueueArr& rhs);

    QueueArr& operator=(QueueArr&& rhs) noexcept;
    QueueArr& operator=(const QueueArr& rhs) noexcept;

    void Push(const Complex& rhs);
    void Pop() noexcept;

    Complex& Top();//! done
    const Complex& Top() const;//! done

    void Clear() noexcept;//! done
    int Size() const noexcept;//! done
    bool IsEmpty() const noexcept;//! done

private:
    bool isfull();

    int head_ = -1;
    int tail_ = -1;

    int size_ = 0;
    std::ptrdiff_t capacity_ = 0;

    Complex* data_ = nullptr;
};

#endif
