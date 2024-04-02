#include "queuelst.hpp"


bool QueueLst::IsEmpty() const noexcept{
    return (head_ == nullptr);
}


void QueueLst::Push(const Complex& elem) {
    Node* node = new Node(elem, nullptr);
    if(head_ == nullptr){
        tail_ = node;
        head_ = node;
    }else{
        tail_->next_ = node;
        tail_ = node;
    }
}


Complex& QueueLst::Top(){
    if (head_ != nullptr){
        return head_->val_;
    }else{
        throw std::out_of_range("Queue is null");
    }
}

const Complex& QueueLst::Top() const{
    if (head_ != nullptr){
        return head_->val_;
    }else{
        throw std::out_of_range("Queue is null");
    }
}

void QueueLst::Pop() noexcept{
    if (!IsEmpty()){
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
}

QueueLst::~QueueLst(){
    Clear();
}

void QueueLst::Clear() {
    while (head_ != nullptr){
        Pop();
    }
}

QueueLst::QueueLst(const QueueLst& rhs){
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr) {
        Complex value = rhs_ptr->val_;
        Push(value);
        rhs_ptr = rhs_ptr->next_;
    }
}


QueueLst& QueueLst::operator=(const QueueLst& rhs){
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            QueueLst tempStack;

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


QueueLst::QueueLst(QueueLst&& rhs) noexcept
        : tail_(rhs.tail_), head_(rhs.head_)
{
    rhs.tail_ = nullptr;
    rhs.head_ = nullptr;
}

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(tail_, rhs.tail_);
        std::swap(head_, rhs.head_);
    }

    return *this;
}