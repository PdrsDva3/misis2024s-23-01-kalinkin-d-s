#include<cstdint>
#include <vector>


class Bitset{
public:
    Bitset() = default;
    ~Bitset() = default;

    Bitset(const Bitset& rhs);
    Bitset(Bitset&& rhs);
    Bitset(const std::int32_t);

    std::int32_t Size() const {return size_;}
    void Resize(const std::int32_t size); //size > 0  #1

    void Set(const std::int32_t idx, const bool v);
    bool Get(const std::int32_t idx) const;
    void Fill(const bool v) noexcept;

    Bitset& operator=(const Bitset&);
    Bitset& operator=(Bitset&&);

    Bitset operator&=(const Bitset& rhs);
    Bitset operator^=(const Bitset& rhs);
    Bitset operator|=(const Bitset& rhs);
    Bitset operator~();


private:
    std::int32_t size_ = 0;
    std::vector<std::uint32_t>* data = nullptr;
};

Bitset operator&(const Bitset& lhs, const Bitset& rhs);

Bitset operator|(const Bitset& lhs, const Bitset& rhs);

Bitset operator^(const Bitset& lhs, const Bitset& rhs);
