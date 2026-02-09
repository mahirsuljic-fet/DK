#pragma once

#include <cmath>
#include <ostream>

struct Vector2D
{
    double x;
    double y;

    double getMagnitude() const
    {
      return std::sqrt(x * x + y * y);
    }

    Vector2D operator+(const Vector2D& other)
    {
      return { this->x + other.x, this->y + other.y };
    }

    Vector2D operator-(const Vector2D& other)
    {
      return { this->x - other.x, this->y - other.y };
    }
};

inline std::ostream& operator<<(std::ostream& os, const Vector2D& vec)
{
  return os << "[ " << vec.x << ", " << vec.y << " ]";
}
