#ifndef MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
#define MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H

#include <cstddef>
#include <iosfwd>
#include <algorithm>
#include <stdexcept>

template <class T>
class StackLstT{
public:
    StackLstT() = default;
    StackLstT(const StackLstT& rhs);
    ~StackLstT();

    void Pop() noexcept;
    void Push(const T& elem);
    bool IsEmpty() const noexcept;
    T& Top();
    const T& Top() const;

    void Clear() noexcept;
    StackLstT& operator=(const StackLstT& rhs);

    StackLstT& operator=(StackLstT&& rhs) noexcept;
    StackLstT(StackLstT&& rhs) noexcept;

private:
    struct Node{
        T val;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};

//----- реализация шаблонных методов производится в хедере -----

template<class T>
StackLstT<T>::StackLstT(const StackLstT<T>& stck) {
    if (!stck.IsEmpty()) {
        head_ = new Node{stck.Top()};
        Node* p_stck = stck.head_;
        Node* temp = head_;
        while (p_stck->next) {
            temp->next = new Node{p_stck->next->val};
            p_stck = p_stck->next;
            temp = temp->next;
        }
    }
}

template<class T>
StackLstT<T>::StackLstT(StackLstT<T>&& stck) noexcept {
    std::swap(head_, stck.head_);
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) {
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            StackLstT tempStack;

            Node* current = rhs.head_;
            while (current != nullptr) {
                tempStack.Push(current->val);
                current = current->next;
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
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& stck) noexcept {
    std::swap(head_, stck.head_);
    return *this;
}

template<class T>
bool StackLstT<T>::IsEmpty() const noexcept {
    return nullptr == head_;
}

template<class T>
void StackLstT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        Node* old = head_;
        head_ = head_->next;
        delete old;
    }
}

template<class T>
void StackLstT<T>::Push(const T& val) {
    head_ = new Node{val, head_};
}

template<class T>
T& StackLstT<T>::Top(){
    if (IsEmpty()) {
        throw std::logic_error("Stack is empy");
    }
    return head_->val;
}

template<class T>
const T& StackLstT<T>::Top() const{
    if (IsEmpty()) {
        throw std::logic_error("Stack is empy");
    }
    return head_->val;
}

template<class T>
void StackLstT<T>::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

template<class T>
StackLstT<T>::~StackLstT(){;}
#endif //MISIS2023F_23_01_KALINKIN_D_S_STACKLST_H
