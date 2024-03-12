#include "stacklst.hpp"
#include <iostream>

bool StackLst::IsEmpty() const noexcept{
    return (head_ == nullptr);
}


void StackLst::Push(const Complex& elem) {
    Node* node = new Node;
    node->val = elem;
    node->next = head_;
    head_ = node;
}

Complex& StackLst::Top(){
    if (head_ != nullptr){
        return head_->val;
    }else{
        throw std::runtime_error("Stack is null");
    }
}

const Complex& StackLst::Top() const{
    if (head_ != nullptr){
        return head_->val;
    }else{
        throw std::runtime_error("Stack is null");
    }
}

void StackLst::Pop() {
    Node* ptr = head_;
    head_ = head_->next;
    delete ptr;
}

StackLst::~StackLst(){
    Clear();
}

void StackLst::Clear() {
    while (head_ != nullptr){
        Node* ptr_head = head_;
        head_ = head_->next;
        delete ptr_head;
    }
}

StackLst::StackLst(const StackLst& rhs) {
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr){
        Complex value = rhs_ptr->val;
        Push(value);
        rhs_ptr = rhs_ptr->next;
    }
}


StackLst& StackLst::operator=(const StackLst& rhs) noexcept {
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            StackLst tempStack;

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
