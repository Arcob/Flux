/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** Vector2f.cpp
** Implements a vector consisting of 2 float values and its helper functions
**
** Author: Julian Thijssen
** -------------------------------------------------------------------------*/

#include "Vector2f.h"
#include <cmath>
#include <sstream>

namespace Flux {
    const Vector2f Vector2f::ZERO = Vector2f(0, 0);
    const Vector2f Vector2f::UP = Vector2f(0, 1);

    /* Core */
    Vector2f::Vector2f() : x(0), y(0) {}

    Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

    void Vector2f::set(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void Vector2f::set(const Vector2f& v) {
        x = v.x;
        y = v.y;
    }

    Vector2f& Vector2f::normalise() {
        float l = length();
        x /= l;
        y /= l;
        return *this;
    }

    float Vector2f::length() const {
        return sqrt(x * x + y * y);
    }

    std::string Vector2f::str() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }

    /* Operator overloads */
    bool Vector2f::operator==(const Vector2f& v) const {
        return x == v.x && y == v.y;
    }

    bool Vector2f::operator!=(const Vector2f& v) const {
        return x != v.x || y != v.y;
    }

    Vector2f& Vector2f::operator+=(const Vector2f& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2f& Vector2f::operator-=(const Vector2f& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2f& Vector2f::operator*=(const Vector2f& v) {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    Vector2f& Vector2f::operator*=(float scale) {
        x *= scale;
        y *= scale;
        return *this;
    }

    Vector2f& Vector2f::operator/=(const Vector2f& v) {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    Vector2f Vector2f::operator+(const Vector2f& v) const {
        return Vector2f(x + v.x, y + v.y);
    }

    Vector2f Vector2f::operator-(const Vector2f& v) const {
        return Vector2f(x - v.x, y - v.y);
    }

    Vector2f Vector2f::operator-() const {
        return Vector2f(-x, -y);
    }

    Vector2f Vector2f::operator*(float scale) const {
        return Vector2f(x * scale, y * scale);
    }

    Vector2f Vector2f::operator/(float divisor) const {
        return Vector2f(x / divisor, y / divisor);
    }

    /* Utility functions */
    float dot(const Vector2f& v1, const Vector2f& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    Vector2f negate(const Vector2f& v) {
        return Vector2f(-v.x, -v.y);
    }

    Vector2f normalise(const Vector2f& v) {
        float l = v.length();
        return Vector2f(v.x / l, v.y / l);
    }
}
