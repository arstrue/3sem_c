#pragma once
#include <cmath>
#include <iostream>

struct Vector3f {
    float x;
    float y;
    float z;
};

Vector3f operator+(const Vector3f& a, const Vector3f& b) {
    Vector3f result = { a.x + b.x, a.y + b.y, a.z + b.z };
    return result;
}

Vector3f operator-(const Vector3f& a, const Vector3f& b) {
    Vector3f result = { a.x - b.x, a.y - b.y, a.z - b.z };
    return result;
}

Vector3f operator*(const Vector3f& a, const float b) {
    Vector3f result = { a.x * b, a.y * b, a.z * b };
    return result;
}

Vector3f operator*(const float b, const Vector3f& a) {
    Vector3f result = { a.x * b, a.y * b, a.z * b };
    return result;
}

float operator*(const Vector3f& a, const Vector3f& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3f operator-(const Vector3f& a) {
    Vector3f result = { -a.x, -a.y, -a.z };
    return result;
}

Vector3f operator+(const Vector3f& a) {
    Vector3f result = a;
    return result;
}

bool operator==(const Vector3f& a, const Vector3f& b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const Vector3f& a, const Vector3f& b) {
    return a.x != b.x || a.y != b.y || a.z != b.z;
}

void operator+=(Vector3f& a, const Vector3f& b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

void operator-=(Vector3f& a, const Vector3f& b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}

void operator*=(Vector3f& a, const float b) {
    a.x *= b;
    a.y *= b;
    a.z *= b;
}

void operator/=(Vector3f& a, const float b) {
    a.x /= b;
    a.y /= b;
    a.z /= b;
}

std::ostream& operator<<(std::ostream& out, const Vector3f& a) {
    out << a.x << ", " << a.y << ", " << a.z;
    return out;
}

std::istream& operator>>(std::istream& in, Vector3f& c) {
    in >> c.x >> c.y >> c.z;
    return in;
}

float squaredNorm(const Vector3f& a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float norm(const Vector3f& a) {
    return sqrt(squaredNorm(a));
}

void normalize(Vector3f& a) {
    float n = norm(a);
    a.x /= n;
    a.y /= n;
    a.z /= n;
}