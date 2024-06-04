#pragma once
#ifndef MISIS2024S_23_01_KALINKIN_D_S_BitSet_H
#define MISIS2024S_23_01_KALINKIN_D_S_BitSet_H


#include <cstdint>
#include <iosfwd>
#include <vector>


class BitSet{
public:
    BitSet() = default; // конструктор класса
    ~BitSet() = default; // деструктор класса

    BitSet(const BitSet& rhs); // оператор копирования
    BitSet(BitSet&& rhs); // оператор перемещения
    BitSet(const std::int32_t); // оператор создания?

    std::int32_t Size() const {return size_;} // получить размер из битов
    void Resize(const std::int32_t size); // изменить размер

    void Set(const std::int32_t idx, const bool v); // установить все биты на значение v
    bool Get(const std::int32_t idx) const; // получить бит
    void Fill(const bool val) noexcept; // заполнить все биты значением val

    BitSet& operator=(const BitSet&); // оператор присваивания
    BitSet& operator=(BitSet&&); // оператор-воровка))

    BitSet operator&=(const BitSet& rhs); // присваивающее умножение
    BitSet operator^=(const BitSet& rhs); // присваивающее сложение
    BitSet operator|=(const BitSet& rhs); // присваивающий штрих Шефера
    BitSet operator~(); // присваивающее отрицание (отрицание всего битсета?)

    std::ostream& WriteTxt(std::ostream&); // форматированный ввод/вывод
    std::istream& ReadTxt(std::istream&);

    std::ostream& WriteBinary(std::ostream&); // неформатированный ввод/вывод
    std::istream& RaadBinary(std::istream&);

private:
    std::int32_t size_ = 0;
    std::vector<std::uint32_t>* data_ = nullptr;

    class BitAccessor { // какой-то доп класс нужен для ???
    public:
        BitAccessor() = delete;
        BitAccessor(BitSet& bst, const std::int32_t idx) noexcept : bst_(bst), idx_(idx) {}
        ~BitAccessor() = default;
        BitAccessor(const BitAccessor&) = delete;
        BitAccessor(BitAccessor&&) noexcept = default;
        BitAccessor& operator=(const BitAccessor&) { return *this;  }
        BitAccessor& operator=(BitAccessor&&) noexcept { return *this; }
        BitAccessor& operator=(const bool v) { bst_.Set(idx_, v); return *this; }
        operator bool() const { return bst_.Get(idx_); }
    private:
        BitSet& bst_;
        const std::int32_t idx_ = -1;
    };
};

BitSet operator&(const BitSet& lhs, const BitSet& rhs); // бинарный оператор умножения

BitSet operator|(const BitSet& lhs, const BitSet& rhs); // бинарный оператор штриха шефера

BitSet operator^(const BitSet& lhs, const BitSet& rhs); // бинарный оператор сложения

#endif