#pragma once
#include <cstdint>
#include <cmath>

namespace euler
{
    template<typename T>
    class tvec3
    {
    public:
        using vec3 = tvec3<T>;

        explicit tvec3() = default;
        explicit tvec3(T v) : m_x(v), m_y(v), m_z(v) { }
        explicit tvec3(T x, T y, T z) : m_x(x), m_y(y), m_z(z) { }

        inline T getX() const { return m_x; }
        inline T getY() const { return m_y; }
        inline T getZ() const { return m_z; }

        inline vec3& setX(T x) { m_x = x; return *this; }
        inline vec3& setY(T y) { m_y = y; return *this; }
        inline vec3& setZ(T z) { m_z = z; return *this; }

        template<int32_t index>
        inline vec3& set(T value)
        {
            static_assert(index < 3 && "Don't set over 3 in vec3!");
            *(&m_x + index) = value;
            return *this;
        }

        inline vec3& set(int32_t index, T value)
        {
            *(&m_x + index) = value;
            return *this;
        }

        template<int32_t index>
        inline T get() const
        {
            static_assert(index < 3 && "Don't get over 3 in vec3!");
            return *(&m_x + index);
        }

        inline T get(int32_t index) const { return *(&m_x + index); }

        inline T& operator[](int32_t index) { return *(&m_x + index); }
        inline T  operator[](int32_t index) const { return *(&m_x + index); }

        inline vec3 operator+(const vec3& vec) const { return vec3(m_x + vec.m_x, m_y + vec.m_y, m_z + vec.m_z); }
        inline vec3 operator-(const vec3& vec) const { return vec3(m_x - vec.m_x, m_y - vec.m_y, m_z - vec.m_z); }

        inline vec3& operator+=(const vec3& vec)
        {
            m_x += vec.m_x;
            m_y += vec.m_y;
            m_z += vec.m_z;

            return *this;
        }

        inline vec3& operator-=(const vec3& vec)
        {
            m_x -= vec.m_x;
            m_y -= vec.m_y;
            m_z -= vec.m_z;

            return *this;
        }

        inline vec3& operator*=(T v)
        {
            m_x *= v;
            m_y *= v;
            m_z *= v;

            return *this;
        }

        inline vec3& operator/=(T v)
        {
            m_x /= v;
            m_y /= v;
            m_z /= v;

            return *this;
        }

        inline vec3& operator=(const vec3& vec)
        {
            this->m_x = vec.m_x;
            this->m_y = vec.m_y;
            this->m_z = vec.m_z;

            return *this;
        }

        inline vec3 operator*(T v) const { return vec3(m_x * v, m_y * v, m_z * v); }
        inline vec3 operator/(T v) const { return vec3(m_x / v, m_y / v, m_z / v); }

        inline vec3 operator-() const { return vec3(-m_x, -m_y, -m_z); }

        inline bool operator==(const vec3& v) const { return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z; }
        inline bool operator!=(const vec3& v) const { return !(*this == v); }

    private:
        T m_x, m_y, m_z;
    };

    template<>
    inline tvec3<float>& tvec3<float>::operator/=(float v)
    {
        v = 1.0f / v;
        m_x *= v;
        m_y *= v;
        m_z *= v;
        return *this;
    }

    template<>
    inline tvec3<float> tvec3<float>::operator/(float v) const
    {
        v = 1.0f / v;
        return vec3(m_x * v, m_y * v, m_z * v);
    }

    template<>
    inline tvec3<double>& tvec3<double>::operator/=(double v)
    {
        v = 1.0 / v;
        m_x *= v;
        m_y *= v;
        m_z *= v;
        return *this;
    }

    template<>
    inline tvec3<double> tvec3<double>::operator/(double v) const
    {
        v = 1.0 / v;
        return vec3(m_x * v, m_y * v, m_z * v);
    }

    template<typename T>
    inline tvec3<T> operator*(T v, const tvec3<T>& vec) { return vec * v; }

    template<typename T>
    inline T max(const tvec3<T>& vec) 
    { 
        return std::max(std::max(vec.getX(), vec.getY()), vec.getZ());
    }

    template<typename T>
    inline T min(const tvec3<T>& vec) 
    { 
        return std::min(std::min(vec.getX(), vec.getY()), vec.getZ());
    }

    template<typename T>
    inline tvec3<T> abs(const tvec3<T>& vec);

    template<> inline tvec3<float> abs<float>(const tvec3<float>& vec)
    {
        return tvec3<float>(std::fabsf(vec.getX()), std::fabsf(vec.getY()), std::fabsf(vec.getZ()));
    }

    template<> inline tvec3<double> abs<double>(const tvec3<double>& vec)
    {
        return tvec3<double>(std::fabs(vec.getX()), std::fabs(vec.getY()), std::fabs(vec.getZ()));
    }

    template<> inline tvec3<int32_t> abs<int32_t>(const tvec3<int32_t>& vec)
    {
        return tvec3<int32_t>(std::abs(vec.getX()), std::abs(vec.getY()), std::abs(vec.getZ()));
    }

    template<typename T>
    inline T dot(const tvec3<T>& v0, const tvec3<T>& v1)
    {
        return v0.getX() * v1.getX() + v0.getY() * v1.getY() + v0.getZ() * v1.getZ();
    }

    template<typename T>
    inline T lengthSquare(const tvec3<T>& v)
    {
        return dot(v, v);
    }

    inline const tvec3<float> normalize(const tvec3<float>& vec)
    {
        const float lenSqr = lengthSquare(vec);
        const float lenInv = 1.0f / std::sqrtf(lenSqr);

        return tvec3<float>(vec.getX() * lenInv, vec.getY() * lenInv, vec.getZ() * lenInv);
    }

    inline const tvec3<double> normalize(const tvec3<double>& vec)
    {
        const double lenSqr = lengthSquare(vec);
        const double lenInv = 1.0 / std::sqrt(lenSqr);

        return tvec3<double>(vec.getX() * lenInv, vec.getY() * lenInv, vec.getZ() * lenInv);
    }

    // Final export class.
    using vec3f = tvec3<float>;
    using vec3d = tvec3<double>;
    using vec3i = tvec3<int32_t>;
    using vec3u = tvec3<uint32_t>;
}