#ifndef MISIS2023F_23_01_KALINKIN_D_S_DYNAR_H
#define MISIS2023F_23_01_KALINKIN_D_S_DYNAR_H
#include <cstddef>
class DynArr{
public:
    DynArr() = default;

    DynArr(const DynArr&) = default;

    DynArr(DynArr&&) = default;

    //! \param size - начальный размер, 0 < size
    DynArr(const std::ptrdiff_t size) : size_(size) { }

    ~DynArr() = default;

    DynArr& operator=(const DynArr&) = default;

    DynArr& operator=(DynArr&&) = default;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }

    //! \param size - новый размер, 0 < size
    void Resize(const std::ptrdiff_t size) { size_ = size; }

    float& operator[](const std::ptrdiff_t idx);
    

private:
    std::ptrdiff_t size_ = 0;
    float* data_ = nullptr;

};
#endif //MISIS2023F_23_01_KALINKIN_D_S_DYNAR_H
