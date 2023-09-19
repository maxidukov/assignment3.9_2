#include <iostream>
#include <compare>

int get_gcf(int,int);
class Fraction
{
private:
    int numerator_;
    int denominator_;
  void reduce(){
      int gcf = get_gcf(numerator_,denominator_);
      if(gcf){
          numerator_ /= gcf;
          denominator_ /= gcf;
      }
   }

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    reduce();
    }
  Fraction operator+(const Fraction& f2){
    return Fraction(this->numerator_*f2.denominator_ + f2.numerator_*this->denominator_, this->denominator_*f2.denominator_);
}
  Fraction operator-(const Fraction& f2){
    return Fraction(this->numerator_*f2.denominator_ - f2.numerator_*this->denominator_, this->denominator_*f2.denominator_);
  }
  Fraction operator*(const Fraction& f2){
    return Fraction(this->numerator_* f2.numerator_, this->denominator_*f2.denominator_);
}
  Fraction operator/(const Fraction& f2){
    return Fraction(this->numerator_*f2.denominator_, this->denominator_*f2.numerator_);
}
  Fraction operator++(){
    this->numerator_ += this->denominator_;
    return *this;
  }
  Fraction operator++(int){
    Fraction temp = *this;
    ++(*this);
    return temp;
  }
  Fraction operator--(){
    this->numerator_ -= this->denominator_;
    return *this;
  }
  Fraction operator--(int){
    Fraction temp = *this;
    --(*this);
    return temp;
  }
  Fraction operator-(){
    return Fraction(-this->numerator_, this->denominator_);
  }
  std::string show_fraction(){
    return std::to_string(numerator_) + "/" + std::to_string(denominator_);
  }
};
int main(){
  int nmr1, dnm1, nmr2, dnm2;
  std::cout<<"Введите числитель дроби 1: ";
  std::cin>>nmr1;
  do{
    std::cout<<"Введите знаменатель дроби 1: ";
    std::cin>>dnm1;
    if(!dnm1){
      std::cout<<" Знаменатель должен быть ненулевым\n";
    }
  }while(!dnm1);
  std::cout<<"Введите числитель дроби 2: ";
  std::cin>>nmr2;
  do{
    std::cout<<"Введите знаменатель дроби 2: ";
    std::cin>>dnm2;
    if(!dnm2){
      std::cout<<" Знаменатель должен быть ненулевым\n";
    }
  }while(!dnm2);
  Fraction f1(nmr1,dnm1);
  Fraction f2(nmr2,dnm2);
  std::cout<<f1.show_fraction()<<" + "<< f2.show_fraction() <<
    " = " << (f1+f2).show_fraction() << std::endl;
  std::cout<<f1.show_fraction()<<" - "<< f2.show_fraction() <<
    " = " << (f1-f2).show_fraction() << std::endl;
  std::cout<<f1.show_fraction()<<" * "<< f2.show_fraction() <<
    " = " << (f1*f2).show_fraction() << std::endl;
  std::cout<<f1.show_fraction()<<" / "<< f2.show_fraction() <<
    " = " << (f1/f2).show_fraction() << std::endl;

  std::cout<<"++"<<f1.show_fraction()<<" * "<< f2.show_fraction() <<
    " = " << (++f1*f2).show_fraction() << std::endl;
  std::cout<<"Значение дроби 1 = "<<f1.show_fraction()<<std::endl;
  std::cout<<f1.show_fraction()<<"-- * "<< f2.show_fraction() <<
    " = " << (f1--*f2).show_fraction() << std::endl;
  std::cout<<"Значение дроби 1 = "<<f1.show_fraction()<<std::endl;
  //std::cout<<get_gcf(48,18)<<std::endl;
  //std::cout<<"-"<<f1.show_fraction()<<" = "<<(-f1).show_fraction()<<std::endl;

  return 0;
}

int get_gcf(int a,int b){
   while(a*b){
      a = b - a;
      b = b - a;
      a = (b + a) % b;
   }
    return abs(a + b);
}
