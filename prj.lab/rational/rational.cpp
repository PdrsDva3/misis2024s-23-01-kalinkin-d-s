#include "rational.h"

std::ostream& Rational::writeTo(std::ostream& ostrm) const{
    ostrm << num_ << sep << den_;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int64_t num = 0;
    char delimiter = 0;
    int64_t den = 0;
    int64_t check_digits = 0;
    istrm >> num;
    istrm.get(delimiter);
//    смотрим, но не вытаскиваем следующий элемент из потока
    check_digits = istrm.peek();
//    проверяем, если это НЕ число, то файлбит
    istrm >> den;
    if (check_digits > '9' || check_digits < '0') {
        istrm.setstate(std::ios_base::failbit);
    } else {
        if (istrm.good() || istrm.eof()) {
            if (den > 0 && delimiter == sep) {
                num_ = num;
                den_ = den;
                fix();
            }
            else {
                istrm.setstate(std::ios_base::failbit);
            }
        }
    }
    return istrm;
}


Rational operator+(Rational lhs, const Rational& rhs) {return lhs += rhs;}
Rational operator+(Rational lhs, const int64_t& rhs) {return lhs += Rational(rhs);}
Rational operator+(const int64_t& lhs, const Rational& rhs) {return Rational(lhs) += rhs;}

Rational operator-(Rational lhs, const Rational& rhs) {return lhs -= rhs;}
Rational operator-(Rational lhs, const int64_t& rhs) {return lhs -= Rational(rhs);}
Rational operator-(const int64_t& lhs, const Rational& rhs) {return Rational(lhs) -= rhs;}

Rational operator*(Rational lhs, const Rational& rhs) {return lhs *= rhs;}
Rational operator*(Rational lhs, const int64_t& rhs) {return lhs *= Rational(rhs);}
Rational operator*(const int64_t& lhs, const Rational& rhs) {return Rational(lhs) *= rhs;}


Rational operator/(Rational lhs, const Rational& rhs) {return lhs /= rhs;}
Rational operator/(Rational lhs, const int64_t& rhs) {return lhs /= Rational(rhs);}
Rational operator/(const int64_t& lhs, const Rational& rhs) {return Rational(lhs) /= rhs;}


int64_t nodf(int64_t n, int64_t d){
    while (n != 0 && d!= 0){
        if(n >= d){
            n %= d;
        }else{
            d %= n;
        }
    }
    return n + d;
}


void Rational::fix(){
    if (den_ == 0){
        throw std::runtime_error("Division by zero");
    }
    int sign_n;
    int sign_d;
    if (num_ < 0){
        sign_n = -1;
    }else{
        sign_n = 1;
    }
    if (den_ < 0){
        sign_d = -1;
    }else{
        sign_d = 1;
    }
    num_ *= sign_n;
    den_ *= sign_d;

    int64_t nod = nodf(num_, den_);
    num_ /= nod;
    den_ /= nod;
    
    num_ *= sign_n * sign_d;

}


Rational& Rational::operator+=(const Rational& rhs){
    int64_t n1 = num_;
    int64_t d1 = den_;
    int64_t n2 = rhs.num_;
    int64_t d2 = rhs.den_;
    if (d1!= d2){
        n1*= d2;
        n2*= d1;
        d1*= d2;
    }
    n1+= n2;
    num_ = n1;
    den_ = d1;
    fix();
    return *this;
}


Rational& Rational::operator-=(const Rational& rhs){
    int64_t n1 = num_;
    int64_t d1 = den_;
    int64_t n2 = rhs.num_;
    int64_t d2 = rhs.den_;
    if (d1!= d2){
        n1*=d2;
        n2*=d1;
        d1*=d2;
    }
    n1-=n2;
    num_ = n1;
    den_ = d1;
    fix();
    return *this;
}


Rational& Rational::operator*=(const Rational& rhs){
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    fix();
    return *this;
}


Rational& Rational::operator/=(const Rational& rhs){
    if (rhs.num_ != 0){
        num_ *= rhs.den_;
        den_ *= rhs.num_;
        fix();
        return *this;
    }else{
        throw std::runtime_error("Division by zero");
    }
}
