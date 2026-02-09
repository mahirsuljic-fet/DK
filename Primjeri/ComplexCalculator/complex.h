#include <cmath>
#include <ostream>
#include <string>

struct Complex
{
    double re;
    double im;

    Complex() : re(0), im(0) { }
    Complex(double re) : re(re), im(0) { }
    Complex(double re, double im) : re(re), im(im) { }

    Complex(std::string text)
    {
      int delimiterIndex = 0;
      for (int i = text.length() - 1; i >= 0; --i)
      {
        if (text[i] == '+' || text[i] == '-')
        {
          delimiterIndex = i;
          break;
        }
      }

      if (delimiterIndex == 0)
      {
        this->re = 0;
      }
      else
      {
        text[delimiterIndex] = '\0';
        const char* reStart = text.c_str();
        this->re = std::stod(reStart);
      }

      text.back() = '\0';

      const char* imStart = text.c_str() + delimiterIndex + 1;
      this->im = std::stod(imStart);
    }

    double module() const { return std::sqrt(this->re * this->re + this->im * this->im); }

    Complex operator+(const Complex& other) { return { this->re + other.re, this->im + other.im }; }
    Complex operator-(const Complex& other) { return { this->re - other.re, this->im - other.im }; }

    Complex operator*(const Complex& other)
    {
      return {
        this->re * other.re - this->im * other.im,
        this->re * other.im + this->im * other.re
      };
    }

    Complex operator/(const Complex& other)
    {
      const double divisor = other.re * other.re + other.im * other.im;
      return {
        (this->re * other.re + this->im * other.im) / divisor,
        (this->im * other.re - this->re * other.im) / divisor
      };
    }
};

inline std::ostream& operator<<(std::ostream& os, const Complex& inum)
{
  if (inum.re != 0) os << inum.re;
  if (inum.im > 0) os << '+';
  if (inum.im != 0) os << inum.im << 'i';
  return os;
}
