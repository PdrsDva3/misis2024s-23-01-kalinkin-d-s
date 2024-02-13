#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdint>


class Rational {
public:
    Rational() = default;
    Rational(const int64_t n, const int64_t d) : num_(n), den_(d) {fix();}
    explicit Rational(int64_t n) : Rational(n, 1) {}
    ~Rational() = default; // деструктор (сборщик мусора)
    Rational(const Rational& rhs) = default;

    Rational& operator=(const Rational& rhs) {num_ = rhs.num_; den_ = rhs.den_; return *this;}

    std::int64_t num() const { return num_; }
    std::int64_t den() const { return den_; }

    bool operator==(const Rational& rhs) const {return num_*rhs.den_ == rhs.num_*den_;}
    bool operator==(const int64_t rhs) const {return operator==(Rational(rhs));}

    bool operator!=(const Rational& rhs) const {return !operator==(rhs);}
    bool operator!=(const int64_t& rhs) const {return !operator==(rhs);}

    bool operator>(const Rational& rhs) const {return num_*rhs.den_ > rhs.num_*den_;}
    bool operator>(const int64_t& rhs) const {return operator>(Rational(rhs));}

    bool operator>=(const Rational& rhs) const {return (operator>(rhs) || operator==(rhs));}
    bool operator>=(const int64_t& rhs) const {return operator>=(Rational(rhs));}

    bool operator<=(const Rational& rhs) const {return !operator>(rhs);}
    bool operator<=(const int64_t& rhs) const {return operator<=(Rational(rhs));}

    bool operator<(const Rational& rhs) const {return (!operator>(rhs) && operator!=(rhs));}
    bool operator<(const int64_t& rhs) const {return operator<=(Rational(rhs));}

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int64_t& rhs) {return operator+=(Rational(rhs));}

    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int64_t& rhs) {return operator-=(Rational(rhs));}

    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int64_t& rhs) {return operator*=(Rational(rhs));}

    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int64_t& rhs) {return operator/=(Rational(rhs));}


    std::istream& readFrom(std::istream& istrm);
    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    int64_t num_ = 0;
    int64_t den_ = 1;
    char sep = '/';
    void fix();

};


Rational operator+(Rational lhs, const Rational& rhs);
Rational operator+(Rational lhs, const int64_t& rhs);
Rational operator+(const int64_t& lhs, const Rational& rhs);

Rational operator-(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const int64_t& rhs);
Rational operator-(const int64_t& lhs, const Rational& rhs);

Rational operator*(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const int64_t& rhs);
Rational operator*(const int64_t& lhs, const Rational& rhs);


Rational operator/(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const int64_t& rhs);
Rational operator/(const int64_t& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {return rhs.writeTo(ostrm);}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {return rhs.readFrom(istrm);}

#endif