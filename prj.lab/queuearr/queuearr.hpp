#ifndef QUEUEARR
#define QUEUEARR

#include <stdexcept>
#include "complex/complex.hpp"

class QueueArr {
public:
    QueueArr() = default;//! done
    ~QueueArr() {delete[] data_;}//! done

    QueueArr(const QueueArr& rhs);//! done        только при инициализации
    QueueArr(QueueArr&& rhs) noexcept;//!  done   только при инициализации

    QueueArr& operator=(const QueueArr& rhs) noexcept;//!  done
    QueueArr& operator=(QueueArr&& rhs) noexcept;//!  done

    void Push(const Complex& rhs);//!  done
    void Pop() noexcept;//! done

    Complex& Top();//! done
    const Complex& Top() const;//! done

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

    Complex* data_ = nullptr;
};

#endif
