#pragma once
#include <cstdint>
#include <cmath>

namespace euler
{
    template<typename T>
    class tvec4
    {
    public:
        using vec4 = tvec4<T>;

        explicit tvec4() = default;
        explicit tvec4(T v) : m_x(v), m_y(v), m_z(v), m_w(v) { }
        explicit tvec4(T x, T y, T z, T w) : m_x(x), m_y(y), m_z(z), m_w(w) { }

        inline T getX() const { return m_x; }
        inline T getY() const { return m_y; }
        inline T getZ() const { return m_z; }
        inline T getW() const { return m_w; }

        inline vec4& setX(T x) { m_x = x; return *this; }
        inline vec4& setY(T y) { m_y = y; return *this; }
        inline vec4& setZ(T z) { m_z = z; return *this; }
        inline vec4& setW(T w) { m_w = w; return *this; }

        template<int32_t index>
        inline vec4& set(T value)
        {
            static_assert(index < 4 && "Don't set over 4 in vec4!");
            *(&m_x + index) = value;
            return *this;
        }

        inline vec4& set(int32_t index, T value)
        {
            *(&m_x + index) = value;
            return *this;
        }

        template<int32_t index>
        inline T get() const
        {
            static_assert(index < 4 && "Don't get over 4 in vec4!");
            return *(&m_x + index);
        }

        inline T get(int32_t index) const { return *(&m_x + index); }

        inline T& operator[](int32_t index) { return *(&m_x + index); }
        inline T  operator[](int32_t index) const { return *(&m_x + index); }

        inline vec4 operator+(const vec4& vec) const
        {
            return vec4(
                m_x + vec.m_x,
                m_y + vec.m_y,
                m_z + vec.m_z,
                m_w + vec.m_w);
        }

        inline vec4 operator-(const vec4& vec) const
        {
            return vec4(
                m_x - vec.m_x,
                m_y - vec.m_y,
                m_z - vec.m_z,
                m_w - vec.m_w);
        }

        inline vec4& operator+=(const vec4& vec)
        {
            m_x += vec.m_x;
            m_y += vec.m_y;
            m_z += vec.m_z;
            m_w += vec.m_w;

            return *this;
        }

        inline vec4& operator-=(const vec4& vec)
        {
            m_x -= vec.m_x;
            m_y -= vec.m_y;
            m_z -= vec.m_z;
            m_w -= vec.m_w;

            return *this;
        }

        inline vec4& operator*=(T v)
        {
            m_x *= v;
            m_y *= v;
            m_z *= v;
            m_w *= v;

            return *this;
        }

        inline vec4& operator/=(T v)
        {
            m_x /= v;
            m_y /= v;
            m_z /= v;
            m_w /= v;

            return *this;
        }

        inline vec4& operator=(const vec4& vec)
        {
            this->m_x = vec.m_x;
            this->m_y = vec.m_y;
            this->m_z = vec.m_z;
            this->m_w = vec.m_w;

            return *this;
        }

        inline vec4 operator*(T v) const
        {
            return vec4(m_x * v, m_y * v, m_z * v, m_w * v);
        }

        inline vec4 operator/(T v) const
        {
            return vec4(m_x / v, m_y / v, m_z / v, m_w / v);
        }

        inline vec4 operator-() const
        {
            return vec4(-m_x, -m_y, -m_z, -m_w);
        }

        inline bool operator==(const vec4& v) const
        {
            return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z && m_w == v.m_w;
        }

        inline bool operator!=(const vec4& v) const { return !(*this == v); }

    private:
        T m_x, m_y, m_z, m_w;
    };

    template<>
    inline tvec4<float>& tvec4<float>::operator/=(float v)
    {
        v = 1.0f / v;
        m_x *= v;
        m_y *= v;
        m_z *= v;
        m_w *= v;

        return *this;
    }

    template<>
    inline tvec4<float> tvec4<float>::operator/(float v) const
    {
        v = 1.0f / v;
        return vec4(m_x * v, m_y * v, m_z * v, m_w * v);
    }

    template<>
    inline tvec4<double>& tvec4<double>::operator/=(double v)
    {
        v = 1.0 / v;
        m_x *= v;
        m_y *= v;
        m_z *= v;
        m_w *= v;

        return *this;
    }

    template<>
    inline tvec4<double> tvec4<double>::operator/(double v) const
    {
        v = 1.0 / v;
        return vec4(m_x * v, m_y * v, m_z * v, m_w * v);
    }

    template<typename T>
    inline tvec4<T> operator*(T v, const tvec4<T>& vec) { return vec * v; }

    template<typename T>
    inline T max(const tvec4<T>& vec)
    {
        return std::max(std::max(std::max(vec.getX(), vec.getY()), vec.getZ()), vec.getW());
    }

    template<typename T>
    inline T min(const tvec4<T>& vec)
    {
        return std::min(std::min(std::min(vec.getX(), vec.getY()), vec.getZ()), vec.getW());
    }

    template<typename T>
    inline tvec4<T> abs(const tvec4<T>& vec);

    template<> inline tvec4<float> abs<float>(const tvec4<float>& vec)
    {
        return tvec4<float>(std::fabsf(vec.getX()), std::fabsf(vec.getY()), std::fabsf(vec.getZ()), std::fabsf(vec.getW()));
    }

    template<> inline tvec4<double> abs<double>(const tvec4<double>& vec)
    {
        return tvec4<double>(std::fabs(vec.getX()), std::fabs(vec.getY()), std::fabs(vec.getZ()), std::fabs(vec.getW()));
    }

    template<> inline tvec4<int32_t> abs<int32_t>(const tvec4<int32_t>& vec)
    {
        return tvec4<int32_t>(std::abs(vec.getX()), std::abs(vec.getY()), std::abs(vec.getZ()), std::abs(vec.getW()));
    }

    template<typename T>
    inline T dot(const tvec4<T>& v0, const tvec4<T>& v1)
    {
        return v0.getX() * v1.getX() + v0.getY() * v1.getY() + v0.getZ() * v1.getZ() + v0.getW() * v1.getW();
    }

    template<typename T>
    inline T lengthSquare(const tvec4<T>& v)
    {
        return dot(v, v);
    }

    inline const tvec4<float> normalize(const tvec4<float>& vec)
    {
        const float lenSqr = lengthSquare(vec);
        const float lenInv = 1.0f / std::sqrtf(lenSqr);

        return tvec4<float>(vec.getX() * lenInv, vec.getY() * lenInv, vec.getZ() * lenInv, vec.getW() * lenInv);
    }

    inline const tvec4<double> normalize(const tvec4<double>& vec)
    {
        const double lenSqr = lengthSquare(vec);
        const double lenInv = 1.0 / std::sqrt(lenSqr);

        return tvec4<double>(vec.getX() * lenInv, vec.getY() * lenInv, vec.getZ() * lenInv, vec.getW() * lenInv);
    }

    // Final export class.
    using vec4f = tvec4<float>;
    using vec4d = tvec4<double>;
    using vec4i = tvec4<int32_t>;
    using vec4u = tvec4<uint32_t>;
}