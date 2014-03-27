//
// Vector2.hpp for  in /home/guerot_a/rendu/cpp_nibbler/core
//
// Made by guerot_a
// Login   <guerot_a@epitech.net>
//
// Started on  Thu Mar 27 17:53:14 2014 guerot_a
// Last update Thu Mar 27 19:35:45 2014 guerot_a
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

template<typename T>
class Vector2
{
public:
  Vector2()
  {
    x = 0;
    y = 0;
  }

  Vector2(const Vector2& vector)
  {
    *this = vector;
  }

  Vector2(T _x, T _y)
  {
    x = _x;
    y = _y;
  }

  ~Vector2()
  {
  }

  Vector2&	operator=(const Vector2& vector)
  {
    x = vector.x;
    y = vector.y;

    return (*this);
  }

  Vector2&	operator+=(const Vector2& vector)
  {
    x += vector.x;
    y += vector.y;

    return (*this);
  }

  Vector2&	operator-=(const Vector2& vector)
  {
    x -= vector.x;
    y -= vector.y;

    return (*this);
  }

  Vector2&	operator*=(double factor)
  {
    x *= factor;
    y *= factor;

    return (*this);
  }

  Vector2&	operator/=(double factor)
  {
    x /= factor;
    y /= factor;

    return (*this);
  }

  Vector2	operator+(const Vector2& vector)
  {
    Vector2	newVector(*this);

    newVector += vector;
    return (newVector);
  }

  Vector2	operator-(const Vector2& vector)
  {
    Vector2	newVector(*this);

    newVector -= vector;
    return (newVector);
  }

  Vector2	operator*(double factor)
  {
    Vector2	newVector(*this);

    newVector *= factor;
    return (newVector);
  }

  Vector2	operator/(double factor)
  {
    Vector2	newVector(*this);

    newVector /= factor;
    return (newVector);
  }

  T	x;
  T	y;
};

typedef Vector2<int>		Vector2i;
typedef Vector2<double>		Vector2f;
typedef Vector2<float>		Vector2d;
typedef Vector2<unsigned>	Vector2u;

#endif /* VECTOR2_HPP */
