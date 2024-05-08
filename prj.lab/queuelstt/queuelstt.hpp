#ifndef MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
#define MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H

#include <stdexcept>

template <class T>
class QueueLstT {
public:
    QueueLstT() = default;
    QueueLstT(const QueueLstT& rhs);
    ~QueueLstT();

    void Pop() noexcept;
    void Push(const T& elem);
    bool IsEmpty() const noexcept;

    T& Top();
    const T& Top() const;

    void Clear();
    QueueLstT& operator=(const QueueLstT& rhs);


    QueueLstT(QueueLstT&& rhs) noexcept;
    QueueLstT& operator=(QueueLstT&& rhs) noexcept;

private:
    struct Node{
        T val_;
        Node* next_ = nullptr;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;

};

//-------------------реализация методов

template<class T>
void QueueLstT<T>::Push(const T& elem){
    Node* node = new Node(elem, nullptr);
    if(head_ == nullptr){
        tail_ = node;
        head_ = node;
    }else{
        tail_->next_ = node;
        tail_ = node;
    }
}

template<class T>
void QueueLstT<T>::Pop() noexcept {
    if (!IsEmpty()){
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
}

template<class T>
bool QueueLstT<T>::IsEmpty() const noexcept {
    return (head_ == nullptr);
}

template<class T>
T& QueueLstT<T>::Top() {
    if (head_ != nullptr){
        return head_->val_;
    }else{
        throw std::out_of_range("Queue is null");
    }
}

template<class T>
const T& QueueLstT<T>::Top() const{
    if (head_ != nullptr){
        return head_->val_;
    }else{
        throw std::out_of_range("Queue is null");
    }
}

template<class T>
void QueueLstT<T>::Clear() {
    while (head_ != nullptr){
        Pop();
    }
}

template<class T>
QueueLstT<T>::~QueueLstT(){
    Clear();
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(const QueueLstT& rhs){
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            QueueLstT tempStack;

            Node* current = rhs.head_;
            while (current != nullptr) {
                tempStack.Push(current->val_);
                current = current->next_;
            }

            while (!tempStack.IsEmpty()) {
                Push(tempStack.Top());
                tempStack.Pop();
            }
        }
    }
    return *this;
}

template<class T>
QueueLstT<T>::QueueLstT(const QueueLstT& rhs){
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr) {
        T value = rhs_ptr->val_;
        Push(value);
        rhs_ptr = rhs_ptr->next_;
    }
}

template<class T>
QueueLstT<T>::QueueLstT(QueueLstT&& rhs) noexcept
        : tail_(rhs.tail_), head_(rhs.head_)
{
    rhs.tail_ = nullptr;
    rhs.head_ = nullptr;
}

template<class T>
QueueLstT<T>& QueueLstT<T>::operator=(QueueLstT&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(tail_, rhs.tail_);
        std::swap(head_, rhs.head_);
    }

    return *this;
}
#endif //MISIS2024S_23_01_KALINKIN_D_S_QueueLst_H
