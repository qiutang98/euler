#pragma once
#include <cstdint>
#include <cmath>

namespace euler
{
    template<typename T>
    class tvec2
    {
    public:
        using vec2 = tvec2<T>;

        explicit tvec2() = default;
        explicit tvec2(T v) : m_x(v), m_y(v) { }
        explicit tvec2(T x, T y) : m_x(x), m_y(y) { }

        inline T getX() const { return m_x; }
        inline T getY() const { return m_y; }

        inline vec2& setX(T x) { m_x = x; return *this; }
        inline vec2& setY(T y) { m_y = y; return *this; }

        template<int32_t index>
        inline vec2& set(T value)
        {
            static_assert(index < 2 && "Don't set over 2 in vec2!");
            *(&m_x + index) = value;
            return *this;
        }

        inline vec2& set(int32_t index, T value)
        {
            *(&m_x + index) = value;
            return *this;
        }

        template<int32_t index>
        inline T get() const
        {
            static_assert(index < 2 && "Don't get over 2 in vec2!");
            return *(&m_x + index);
        }

        inline T get(int32_t index) const { return *(&m_x + index); }

        inline T& operator[](int32_t index) { return *(&m_x + index); }
        inline T  operator[](int32_t index) const { return *(&m_x + index); }

        inline vec2 operator+(const vec2& vec) const { return vec2(m_x + vec.m_x, m_y + vec.m_y); }
        inline vec2 operator-(const vec2& vec) const { return vec2(m_x - vec.m_x, m_y - vec.m_y); }

        inline vec2& operator+=(const vec2& vec)
        {
            m_x += vec.m_x;
            m_y += vec.m_y;
            return *this;
        }

        inline vec2& operator-=(const vec2& vec)
        {
            m_x -= vec.m_x;
            m_y -= vec.m_y;
            return *this;
        }

        inline vec2& operator*=(T v)
        {
            m_x *= v;
            m_y *= v;
            return *this;
        }

        inline vec2& operator/=(T v)
        {
            m_x /= v;
            m_y /= v;
            return *this;
        }

        inline vec2& operator=(const vec2& vec)
        {
            this->m_x = vec.m_x;
            this->m_y = vec.m_y;

            return *this;
        }

        inline vec2 operator*(T v) const { return vec2(m_x * v, m_y * v); }
        inline vec2 operator/(T v) const { return vec2(m_x / v, m_y / v); }

        inline vec2 operator-() const { return vec2(-m_x, -m_y); }

        inline bool operator==(const vec2& v) const { return m_x == v.m_x && m_y == v.m_y; }
        inline bool operator!=(const vec2& v) const { return !(*this == v); }

    private:
        T m_x, m_y;
    };

    template<>
    inline tvec2<float>& tvec2<float>::operator/=(float v)
    {
        v = 1.0f / v;
        m_x *= v;
        m_y *= v;
        return *this;
    }

    template<>
    inline tvec2<float> tvec2<float>::operator/(float v) const
    {
        v = 1.0f / v;
        return vec2(m_x * v, m_y * v);
    }

    template<>
    inline tvec2<double>& tvec2<double>::operator/=(double v)
    {
        v = 1.0 / v;
        m_x *= v;
        m_y *= v;
        return *this;
    }

    template<>
    inline tvec2<double> tvec2<double>::operator/(double v) const
    {
        v = 1.0 / v;
        return vec2(m_x * v, m_y * v);
    }

    template<typename T>
    inline tvec2<T> operator*(T v, const tvec2<T>& vec) { return vec * v; }

    template<typename T>
    inline T max(const tvec2<T>& vec) { return vec.getX() > vec.getY() ? vec.getX() : vec.getY(); }

    template<typename T>
    inline T min(const tvec2<T>& vec) { return vec.getX() < vec.getY() ? vec.getX() : vec.getY(); }

    template<typename T>
    inline tvec2<T> abs(const tvec2<T>& vec);

    template<> inline tvec2<float> abs<float>(const tvec2<float>& vec)
    {
        return tvec2<float>(std::fabsf(vec.getX()), std::fabsf(vec.getY()));
    }

    template<> inline tvec2<double> abs<double>(const tvec2<double>& vec)
    {
        return tvec2<double>(std::fabs(vec.getX()), std::fabs(vec.getY()));
    }

    template<> inline tvec2<int32_t> abs<int32_t>(const tvec2<int32_t>& vec)
    {
        return tvec2<int32_t>(std::abs(vec.getX()), std::abs(vec.getY()));
    }

    template<typename T>
    inline T dot(const tvec2<T>& v0, const tvec2<T>& v1)
    {
        return v0.getX() * v1.getX() + v0.getY() * v1.getY();
    }

    template<typename T>
    inline T lengthSquare(const tvec2<T>& v)
    {
        return dot(v, v);
    }

    inline const tvec2<float> normalize(const tvec2<float>& vec)
    {
        const float lenSqr = lengthSquare(vec);
        const float lenInv = 1.0f / std::sqrtf(lenSqr);

        return tvec2<float>(vec.getX() * lenInv, vec.getY() * lenInv);
    }

    inline const tvec2<double> normalize(const tvec2<double>& vec)
    {
        const double lenSqr = lengthSquare(vec);
        const double lenInv = 1.0f / std::sqrtf(lenSqr);

        return tvec2<double>(vec.getX() * lenInv, vec.getY() * lenInv);
    }

    // Final export class.
    using vec2f = tvec2<float>;
    using vec2d = tvec2<double>;
    using vec2i = tvec2<int32_t>;
    using vec2u = tvec2<uint32_t>;
}