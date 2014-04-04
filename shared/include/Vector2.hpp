#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

namespace Math
{
  template<typename T>
  class Vector2
  {
  public:
    Vector2() :
      m_x(0),
      m_y(0) {}

    Vector2(const Vector2<T>& vector)
    {
      *this = vector;
    }

    Vector2(T x, T y) :
      m_x(x),
      m_y(y) {}

    ~Vector2() {}

    const Vector2<T>&	operator=(const Vector2<T>& vector)
    {
      m_x = vector.m_x;
      m_y = vector.m_y;
    }

    const Vector2<T>&	operator+=(const Vector2<T>& vector)
    {
      *this = *this + vector;
    }

    const Vector2<T>&	operator-=(const Vector2<T>& vector)
    {
      *this = *this - vector;
    }

  const Vector2<T>&	operator/=(double factor)
    {
      *this = *this / factor;
    }

    const Vector2<T>&	operator*=(double factor)
    {
      *this = *this * factor;
    }

    Vector2<T>		operator+(const Vector2<T>& vector)
    {
      return (Vector2<T>(m_x + vector.m_x,
			 m_y + vector.m_y));
    }

    Vector2<T>		operator-(const Vector2<T>& vector)
    {
      return (Vector2<T>(m_x - vector.m_x,
			 m_y - vector.m_y));
    }

    Vector2<T>		operator/(double factor)
    {
      return (Vector2<T>(m_x / factor,
			 m_y / factor));

    }

    Vector2<T>		operator*(double factor)
    {
      return (Vector2<T>(m_x * factor,
			 m_y * factor));
    }

    double		dot(const Vector2<T>& vector)
    {
      return (m_x * vector.m_x + m_y * vector.m_y);
    }

    double		length()
    {
      return (sqrt(dot(*this)));
    }

    void			normalize()
    {
      *this / length();
    }

  public:
    T	m_x;
    T	m_y;
  };

  typedef Vector2<double>		Vector2f;
  typedef Vector2<int>		Vector2i;
  typedef Vector2<unsigned int>	Vector2u;
}
