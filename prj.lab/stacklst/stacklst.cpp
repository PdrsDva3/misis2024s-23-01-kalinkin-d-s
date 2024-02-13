#include "stacklst.h"
#include <iostream>

bool StackLst::IsEmpty() {
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
    while (head_ != nullptr){
        Node* ptr_head = head_;
        head_->
    }
}


