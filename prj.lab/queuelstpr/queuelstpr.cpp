#include "queuelstpr.hpp"

void QueueLstPr::Pop() noexcept {
    if (head_ != nullptr) {
        Node *node_ptr = head_;
        head_ = head_->next_;
        delete node_ptr;
    }
}

float &QueueLstPr::Top() {
    if (head_ == nullptr)
        throw std::logic_error("Queue is empty");
    else
        return head_->val_;
}

const float &QueueLstPr::Top() const {
    if (head_ == nullptr)
        throw std::logic_error("Queue is empty");
    else
        return head_->val_;
}

bool QueueLstPr::IsEmpty() noexcept {
    return head_ == nullptr;
}

bool QueueLstPr::IsEmpty() const noexcept {
    return head_ == nullptr;
}

void QueueLstPr::Clear() {
    while (head_ != nullptr){
        Node* node_ptr = head_;
        head_ = head_->next_;
        delete node_ptr;
    }
}

QueueLstPr::~QueueLstPr() {
    Clear();
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr &rhs) {
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            QueueLstPr tempStack;

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

QueueLstPr::QueueLstPr(QueueLstPr &rhs) {
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr) {
        float value = rhs_ptr->val_;
        Push(value);
        rhs_ptr = rhs_ptr->next_;
    }
}

void QueueLstPr::Push(float& elem) {
    Node* n_node = new Node;
    n_node->val_ = elem;
    if (this->IsEmpty()){
        head_ = n_node;
    }else{
        Node* ptr = head_;

    }

}
