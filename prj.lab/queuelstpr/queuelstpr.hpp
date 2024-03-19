#ifndef MISIS2024S_23_01_KALINKIN_D_S_QUEUELSTPZ_H
#define MISIS2024S_23_01_KALINKIN_D_S_QUEUELSTPZ_H

#include <stdexcept>

class QueueLstPr{
public:
    QueueLstPr() = default;
    ~QueueLstPr();
    QueueLstPr(QueueLstPr& rhs);

    void Push(float& elem);//! дописать
    void Pop() noexcept;

    float& Top();
    [[nodiscard]] const float& Top() const;

    bool IsEmpty() noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept;

    void Clear();
    QueueLstPr& operator=(QueueLstPr& rhs);


private:
    struct Node{
        float val_ = 0;
        Node* next_ = nullptr;
    };
    Node* head_ = nullptr;
//    Node* tail_ = nullptr;
};


#endif //MISIS2024S_23_01_KALINKIN_D_S_QUEUELSTPZ_H
