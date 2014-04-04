#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>

namespace
{
  template<typename T>
  class Vector3
  {
  public:
    Vector3() :
      m_x(0),
      m_y(0),
      m_z(0) {}

    Vector3(const Vector3<T>& vector)
    {
      *this = vector;
    }

    Vector3(T x, T y, T z) :
      m_x(x),
      m_y(y),
      m_z(z) {}

    ~Vector3() {}

    const Vector3<T>&	operator=(const Vector3<T>& vector)
    {
      m_x = vector.m_x;
      m_y = vector.m_y;
      m_z = vector.m_z;
    }

    const Vector3<T>&	operator+=(const Vector3<T>& vector)
    {
      *this = *this + vector;
    }

    const Vector3<T>&	operator-=(const Vector3<T>& vector)
    {
      *this = *this - vector;
    }

    const Vector3<T>&	operator/=(double factor)
    {
      *this = *this / factor;
    }

    const Vector3<T>&	operator*=(double factor)
    {
      *this = *this * factor;
    }

    Vector3<T>		operator+(const Vector3<T>& vector)
    {
      return (Vector3<T>(m_x + vector.m_x,
			 m_y + vector.m_y,
			 m_z + vector.m_z));
    }

    Vector3<T>		operator-(const Vector3<T>& vector)
    {
      return (Vector3<T>(m_x - vector.m_x,
			 m_y - vector.m_y,
			 m_z - vector.m_z));
    }

    Vector3<T>		operator/(double factor)
    {
      return (Vector3<T>(m_x / factor,
			 m_y / factor,
			 m_z / factor));

    }

    Vector3<T>		operator*(double factor)
    {
      return (Vector3<T>(m_x * factor,
			 m_y * factor,
			 m_z * factor));
    }

    double		dot(const Vector3<T>& vector)
    {
      return (m_x * vector.m_x +
	      m_y * vector.m_y +
	      m_z * vector.m_z);
    }

    Vector3<T>		cross(const Vector3<T>& vector)
    {
      Vector3<T>	crossVector;

      crossVector.m_x = m_y * vector.m_z - m_z * vector.m_y;
      crossVector.m_y = m_z * vector.m_x - m_x * vector.m_z;
      crossVector.m_z = m_x * vector.m_y - m_y * vector.m_x;

      return (crossVector);
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
    T	m_z;
  };

  typedef Vector3<double>	Vector3f;
  typedef Vector3<int>		Vector3i;
  typedef Vector3<unsigned int>	Vector3u;
}
