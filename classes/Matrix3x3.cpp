//
//  Matrix3x3.cpp
//  ggmath
//
//  Created by Mike Wei on 2019/2/11.
//  Copyright © 2019 Mike Wei. All rights reserved.
//

#include "Matrix3x3.hpp"

Matrix3x3 Matrix3x3::identity() {
    Matrix3x3 result;
    result.set(1.0, 0.0, 0.0,
               0.0, 1.0, 0.0,
               0.0, 0.0, 1.0);
    return result;
}

Matrix3x3 Matrix3x3::centerOnly() {
    Matrix3x3 result;
    result.set(0.0, 0.0, 0.0,
               0.0, 1.0, 0.0,
               0.0, 0.0, 0.0);
    return result;
}

Matrix3x3::Matrix3x3(float _m11, float _m12, float _m13,
                     float _m21, float _m22, float _m23,
                     float _m31, float _m32, float _m33) {
    m11 = _m11;
    m12 = _m12;
    m13 = _m13;
    
    m21 = _m12;
    m22 = _m22;
    m23 = _m23;
    
    m31 = _m31;
    m32 = _m32;
    m33 = _m33;
}

void Matrix3x3::set(float _m11, float _m12, float _m13,
                    float _m21, float _m22, float _m23,
                    float _m31, float _m32, float _m33) {
    m11 = _m11;
    m12 = _m12;
    m13 = _m13;
    
    m21 = _m12;
    m22 = _m22;
    m23 = _m23;
    
    m31 = _m31;
    m32 = _m32;
    m33 = _m33;
}

float& Matrix3x3::operator[]( const int& index ) {
    switch(index) {
        case 0:  return m11;
        case 1:  return m12;
        case 2:  return m13;
        case 3:  return m21;
        case 4:  return m22;
        case 5:  return m23;
        case 6:  return m31;
        case 7:  return m32;
        case 8:  return m33;
        default: return m11;
    }
}

void Matrix3x3::transpose() {
    m12 += m21; m21 = m12 - m21; m12 -= m21; //swap b and d
    m13 += m31; m31 = m13 - m31; m13 -= m31; //swap c and g
    m23 += m32; m32 = m23 - m32; m23 -= m32; //swap f and h
}

Matrix3x3 Matrix3x3::transpose(const Matrix3x3& A) {
    Matrix3x3 result = A;
    result.transpose();
    return result;
}

float Matrix3x3::determinant() const {
    float det = m11 * m22 * m33
    + m12 * m23 * m31
    + m21 * m32 * m13
    - m31 * m22 * m13
    - m21 * m12 * m33
    - m32 * m23 * m11;
    return det;
}

float Matrix3x3::determinant(const Matrix3x3& A) {
    return A.determinant();
}

Matrix3x3 Matrix3x3::inverse(const Matrix3x3& A) {
    Matrix3x3 result = A;
    result.invert();
    return result;
}

void Matrix3x3::invert() {
    float det = determinant();
    Matrix3x3 B;
    
    //included in these calculations: minor, cofactor (changed signs), transpose (by the order of "="), division through determinant
    B.m11 = ( m22 * m33 - m32 * m23) / det;
    B.m12 = (-m12 * m33 + m32 * m13) / det;
    B.m13 = ( m12 * m23 - m22 * m13) / det;
    B.m21 = (-m21 * m33 + m31 * m23) / det;
    B.m22 = ( m11 * m33 - m31 * m13) / det;
    B.m23 = (-m11 * m23 + m21 * m13) / det;
    B.m31 = ( m21 * m32 - m31 * m22) / det;
    B.m32 = (-m11 * m32 + m31 * m12) / det;
    B.m33 = ( m11 * m22 - m21 * m12) / det;
    
    *this = B;
}

Matrix3x3 Matrix3x3::entrywiseTimes(const Matrix3x3& A) {
    Matrix3x3 C = *this;
    C.m11 *= A.m11;
    C.m12 *= A.m12;
    C.m13 *= A.m13;
    C.m21 *= A.m21;
    C.m22 *= A.m22;
    C.m23 *= A.m23;
    C.m31 *= A.m31;
    C.m32 *= A.m32;
    C.m33 *= A.m33;
    return C;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& B) {
    Matrix3x3 result;
    result.m11 = m11 + B.m11;
    result.m12 = m12 + B.m12;
    result.m13 = m13 + B.m13;
    result.m21 = m21 + B.m21;
    result.m22 = m21 + B.m22;
    result.m23 = m23 + B.m23;
    result.m31 = m31 + B.m31;
    result.m32 = m32 + B.m32;
    result.m33 = m33 + B.m33;
    return result;
}

void Matrix3x3::operator+=(const Matrix3x3& B) {
    m11 += B.m11;
    m12 += B.m12;
    m13 += B.m13;
    m21 += B.m21;
    m22 += B.m22;
    m23 += B.m23;
    m31 += B.m31;
    m32 += B.m32;
    m33 += B.m33;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& B) {
    Matrix3x3 result;
    result.m11 = m11 - B.m11;
    result.m12 = m12 - B.m12;
    result.m13 = m13 - B.m13;
    result.m21 = m21 - B.m21;
    result.m22 = m21 - B.m22;
    result.m23 = m23 - B.m23;
    result.m31 = m31 - B.m31;
    result.m32 = m32 - B.m32;
    result.m33 = m33 - B.m33;
    return result;
}

void Matrix3x3::operator-=(const Matrix3x3& B) {
    m11 -= B.m11;
    m12 -= B.m12;
    m13 -= B.m13;
    m21 -= B.m21;
    m22 -= B.m22;
    m23 -= B.m23;
    m31 -= B.m31;
    m32 -= B.m32;
    m33 -= B.m33;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& B) {
    Matrix3x3 result;
    result.m11 = m11 * B.m11;
    result.m12 = m12 * B.m12;
    result.m13 = m13 * B.m13;
    result.m21 = m21 * B.m21;
    result.m22 = m21 * B.m22;
    result.m23 = m23 * B.m23;
    result.m31 = m31 * B.m31;
    result.m32 = m32 * B.m32;
    result.m33 = m33 * B.m33;
    return result;
}

void Matrix3x3::operator*=(const Matrix3x3& B) {
    m11 *= B.m11;
    m12 *= B.m12;
    m13 *= B.m13;
    m21 *= B.m21;
    m22 *= B.m22;
    m23 *= B.m23;
    m31 *= B.m31;
    m32 *= B.m32;
    m33 *= B.m33;
}

Matrix3x3 Matrix3x3::operator*(float scalar) {
    Matrix3x3 result;
    result.m11 = m11 * scalar;
    result.m12 = m12 * scalar;
    result.m13 = m13 * scalar;
    result.m21 = m21 * scalar;
    result.m22 = m21 * scalar;
    result.m23 = m23 * scalar;
    result.m31 = m31 * scalar;
    result.m32 = m32 * scalar;
    result.m33 = m33 * scalar;
    return result;
}

void Matrix3x3::operator*=(float scalar) {
    m11 *= scalar;
    m12 *= scalar;
    m13 *= scalar;
    m21 *= scalar;
    m22 *= scalar;
    m23 *= scalar;
    m31 *= scalar;
    m32 *= scalar;
    m33 *= scalar;
}

Matrix3x3 Matrix3x3::operator/(const Matrix3x3& B) {
    Matrix3x3 result;
    result.m11 = m11 / B.m11;
    result.m12 = m12 / B.m12;
    result.m13 = m13 / B.m13;
    result.m21 = m21 / B.m21;
    result.m22 = m21 / B.m22;
    result.m23 = m23 / B.m23;
    result.m31 = m31 / B.m31;
    result.m32 = m32 / B.m32;
    result.m33 = m33 / B.m33;
    return result;
}

void Matrix3x3::operator/=(const Matrix3x3& B) {
    m11 /= B.m11;
    m12 /= B.m12;
    m13 /= B.m13;
    m21 /= B.m21;
    m22 /= B.m22;
    m23 /= B.m23;
    m31 /= B.m31;
    m32 /= B.m32;
    m33 /= B.m33;
}

Matrix3x3 Matrix3x3::operator/(float scalar) {
    Matrix3x3 result;
    result.m11 = m11 / scalar;
    result.m12 = m12 / scalar;
    result.m13 = m13 / scalar;
    result.m21 = m21 / scalar;
    result.m22 = m21 / scalar;
    result.m23 = m23 / scalar;
    result.m31 = m31 / scalar;
    result.m32 = m32 / scalar;
    result.m33 = m33 / scalar;
    return result;
}

void Matrix3x3::operator/=(float scalar) {
    m11 /= scalar;
    m12 /= scalar;
    m13 /= scalar;
    m21 /= scalar;
    m22 /= scalar;
    m23 /= scalar;
    m31 /= scalar;
    m32 /= scalar;
    m33 /= scalar;
}
