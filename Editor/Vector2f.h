/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** Vector2f.h
** Declares a vector consisting of 2 float values and its helper functions
**
** Author: Julian Thijssen
** -------------------------------------------------------------------------*/

#pragma once

#include <string>

namespace Flux {
    class Vector2f {
    public:
        float x, y;

        static const Vector2f ZERO;
        static const Vector2f UP;

        /* Core */
        Vector2f();
        Vector2f(float x, float y);
        void set(float x, float y);
        void set(const Vector2f& v);
        Vector2f& normalise();

        float length() const;
        std::string str() const;

        /* Operator overloads */
        bool operator==(const Vector2f& v) const;
        bool operator!=(const Vector2f& v) const;
        Vector2f& operator+=(const Vector2f& v);
        Vector2f& operator-=(const Vector2f& v);
        Vector2f& operator*=(const Vector2f& v);
        Vector2f& operator*=(float scale);
        Vector2f& operator/=(const Vector2f& v);
        Vector2f operator+(const Vector2f& v) const;
        Vector2f operator-(const Vector2f& v) const;
        Vector2f operator-() const;
        Vector2f operator*(float scale) const;
        Vector2f operator/(float divisor) const;
    };

    /* Utility functions */
    float dot(const Vector2f& v1, const Vector2f& v2);
    Vector2f negate(const Vector2f& v);
    Vector2f normalise(const Vector2f& v);
}
