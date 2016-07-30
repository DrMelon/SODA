//
// @Author: J Brown (@DrMelon)
// 2016

#ifndef _SODA_UTIL_VECTORMATH_H_
#define _SODA_UTIL_VECTORMATH_H_

// Woo, vector math!!

namespace SODA
{
	template<typename T>
	class Vector2
	{
		public:
			T x;
			T y;

			Vector2();
			Vector2(T, T);

			template<typename U>
			Vector2(const Vector2<U>& vector);

			T GetMagnitude();
			Vector2 Normalized();
			void Normalize();
		
	};

	template<typename T>
	Vector2<T> operator -(const Vector2<T>& right);

	template<typename T>
	Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

	template<typename T>
	Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

	template<typename T>
	Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);

	template<typename T>
	Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);

	template<typename T>
	Vector2<T> operator *(const Vector2<T>&left, const T right);

	template<typename T>
	Vector2<T> operator /(const Vector2<T>&left, const T right);

	template<typename T>
	Vector2<T>& operator *=(Vector2<T>&left, const T right);

	template<typename T>
	Vector2<T>& operator /=(Vector2<T>&left, const T right);


	template<typename T>
	Vector2<T>::Vector2() : x(0), y(0)
	{

	}

	template<typename T>
	Vector2<T>::Vector2(T a, T b)
	{
		x = a;
		y = b;
	}

	template<typename T>
	T Vector2<T>::GetMagnitude()
	{
		return std::sqrt((x*x) + (y*y));
	}

	template<typename T>
	Vector2<T> Vector2<T>::Normalized()
	{
		Vector2<T> normalized;
		normalized.x = x;
		normalized.y = y;

		normalized.Normalize();

		return normalized;
	}

	template<typename T>
	void Vector2<T>::Normalize()
	{
		T magnitude = GetMagnitude();

		x /= magnitude;
		y /= magnitude;
	}

	template<typename T>
	template<typename U>
	Vector2<T>::Vector2(const Vector2<U>& vector)
	{
		x = (T)vector.x;
		y = (T)vector.y;
	}

	template<typename T>
	Vector2<T> operator-(const Vector2<T>& right)
	{
		return Vector2<T>(-right.x, -right.y);
	}

	template<typename T>
	Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x + right.x, left.y + right.y);
	}

	template<typename T>
	Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x + right.x, left.y + right.y);
	}

	template<typename T>
	Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}

	template<typename T>
	Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}

	template<typename T>
	Vector2<T> operator*(const Vector2<T>& left, const T right)
	{
		return Vector2<T>(left.x * right, left.y * right);
	}

	template<typename T>
	Vector2<T> operator/(const Vector2<T>& left, const T right)
	{
		return Vector2<T>(left.x / right, left.y / right);
	}

	template<typename T>
	Vector2<T>& operator*=(Vector2<T>& left, const T right)
	{
		left.x *= right;
		left.y *= right;

		return left;
	}

	template<typename T>
	Vector2<T>& operator/=(Vector2<T>& left, const T right)
	{
		left.x /= right;
		left.y /= right;

		return left;
	}


}

#endif