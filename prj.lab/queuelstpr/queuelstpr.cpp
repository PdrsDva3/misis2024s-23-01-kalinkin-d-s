#include "queuelstpr.hpp"

void QueueLstPr::Pop() noexcept {
    if (!IsEmpty()) {
        Node* node_ptr = head_;
        head_ = head_->next_;
        delete node_ptr;
    }
}

float& QueueLstPr::Top() {
    if (head_ == nullptr)
        throw std::out_of_range("Queue is empty");
    else
        return head_->val_;
}

const float& QueueLstPr::Top() const {
    if (head_ == nullptr)
        throw std::out_of_range("Queue is empty");
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

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
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

QueueLstPr::QueueLstPr(QueueLstPr& rhs) {
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr) {
        float value = rhs_ptr->val_;
        Push(value);
        rhs_ptr = rhs_ptr->next_;
    }
}

void QueueLstPr::Push(const float& elem) {
    Node* node = new Node(elem, nullptr);
    if(head_ == nullptr){
        head_ = node;
        tail_ = node;
    }else if (elem <= head_->val_){
            node->next_ = head_;
            head_ = node;
    }else if (elem >= tail_->val_){
        tail_->next_ = node;
        tail_ = node;
    }else {
        Node* temp = head_;
        while (temp != nullptr) {
            if (elem <= temp->next_->val_) {
                Node* next_node = temp->next_;
                temp->next_ = node;
                node->next_ = next_node;
                break;
            }else{
                temp = temp->next_;
            }
        }
    }
}


QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept
        : tail_(rhs.tail_), head_(rhs.head_)
{
    rhs.tail_ = nullptr;
    rhs.head_ = nullptr;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(tail_, rhs.tail_);
        std::swap(head_, rhs.head_);
    }

    return *this;
}