#include <cstddef>
#include <iosfwd>

class Dynarr{
public:
    Dynarr() = default;
    Dynarr(std::ptrdiff_t size, float* data) : data_(data) {capacity_ = size; }//--------------

    ~Dynarr() {delete[] data_;}

    Dynarr& operator=(const Dynarr& rhs) {return *this;}
    Dynarr(const Dynarr&) = default;



private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    float* data_ = nullptr;

};
