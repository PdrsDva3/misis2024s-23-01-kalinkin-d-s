#include "stackarr.hpp"


StackArr::StackArr(const StackArr& rhs)
: top_ind_(rhs.top_ind_), capacity_(rhs.Size()) {
    data_ = new Complex[rhs.Size()];
    for (int i = 0; i < rhs.Size(); i++) {
        data_[i] = rhs.data_[i];
    }
}


StackArr& StackArr::operator=(const StackArr& obj) {
    if (this != &obj) {
        // Если размеры стеков отличаются, изменяем размер текущего стека
        if (capacity_ != obj.capacity_) {
            delete[] data_; // Освобождаем старую память
            capacity_ = obj.capacity_; // Обновляем размер
            data_ = new Complex[capacity_]; // Выделяем новую память
            if (!data_) {
                throw std::bad_alloc(); // Проверяем успешность выделения памяти
            }
        }
        // Копируем данные из obj в текущий объект
        std::copy(obj.data_, obj.data_ + obj.top_ind_ + 1, data_);
        top_ind_ = obj.top_ind_; // Обновляем индекс вершины
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


void StackArr::Clear() noexcept{
    top_ind_ = -1;
}