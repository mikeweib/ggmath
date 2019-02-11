//
//  Matrix3x3.hpp
//  ggmath
//
//  Created by Mike Wei on 2019/2/11.
//  Copyright © 2019 Mike Wei. All rights reserved.
//

#ifndef Matrix3x3_hpp
#define Matrix3x3_hpp

#include <stdio.h>

#include "ggmath.h"


class HIDDEN_API Matrix3x3 {
    
public:
    
    float m11;
    float m12;
    float m13;
    
    float m21;
    float m22;
    float m23;
    
    float m31;
    float m32;
    float m33;
    
    static Matrix3x3 identity();
    
    static Matrix3x3 centerOnly();
    
    Matrix3x3(float _m11=0.0, float _m12=0.0, float _m13=0.0,
              float _m21=0.0, float _m22=0.0, float _m23=0.0,
              float _m31=0.0, float _m32=0.0, float _m33=0.0);
    
    void set(float _m11, float _m12, float _m13,
             float _m21, float _m22, float _m23,
             float _m31, float _m32, float _m33);
    
    void transpose();
    
    Matrix3x3 transpose(const Matrix3x3& A);
    
    float determinant() const;
    
    float determinant(const Matrix3x3& A);

    Matrix3x3 inverse(const Matrix3x3& A);
    
    void invert();
    
    Matrix3x3 entrywiseTimes(const Matrix3x3& A);
    
    
    float& operator[]( const int& index );
    
    Matrix3x3 operator+(const Matrix3x3& B);
    
    void operator+=(const Matrix3x3& B);
    
    Matrix3x3 operator-(const Matrix3x3& B);
    
    void operator-=(const Matrix3x3& B);
    
    Matrix3x3 operator*(const Matrix3x3& B);
    
    void operator*=(const Matrix3x3& B);
    
    Matrix3x3 operator*(float scalar);
    
    void operator*=(float scalar);
    
    Matrix3x3 operator/(const Matrix3x3& B);
    
    void operator/=(const Matrix3x3& B);
    
    Matrix3x3 operator/(float scalar);
    
    void operator/=(float scalar);
};

#endif /* Matrix3x3_hpp */
