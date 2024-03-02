#include "queuelst.h."


bool QueueLst::IsEmpty() const noexcept{
    return (head_ == nullptr);
}


void QueueLst::Push(const Complex& elem) {
    Node* newNode = new Node(elem);
    if (head_ == nullptr) {
        head_ = newNode;
    } else {
        tail_->next = newNode;
    }
    tail_ = newNode;
}


Complex& QueueLst::Top(){
    if (head_ != nullptr){
        return head_->val;
    }else{
        throw std::runtime_error("Queue is null");
    }
}

const Complex& QueueLst::Top() const{
    if (head_ != nullptr){
        return head_->val;
    }else{
        throw std::runtime_error("Queue is null");
    }
}

void QueueLst::Pop() {
    if (head_ != nullptr) {
        Node *ptr = head_;
        head_ = head_->next;
        delete ptr;
    }
}

QueueLst::~QueueLst(){
    Clear();
}

void QueueLst::Clear() {
    while (head_ != nullptr){
        Node* ptr_head = head_;
        head_ = head_->next;
        delete ptr_head;
    }
}

QueueLst::QueueLst(const QueueLst& rhs){
    Node* rhs_ptr = rhs.head_;
    while (rhs_ptr != nullptr) {
        Complex value = rhs_ptr->val;
        Push(value);
        rhs_ptr = rhs_ptr->next;
    }
}


QueueLst& QueueLst::operator=(const QueueLst& rhs){
    if (this != &rhs) {
        Clear();

        if (!rhs.IsEmpty()) {
            QueueLst tempStack;

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
