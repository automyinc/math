 /*************************************************************************
 * 
 *  [2017] - [2018] Automy Inc. 
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Automy Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Automy Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Automy Incorporated.
 */

#ifndef MATH_INCLUDE_MATH_MATH3D_H_
#define MATH_INCLUDE_MATH_MATH3D_H_

#include "Util.h"
#include "Matrix.h"
#include "Vector3i.h"
#include "Vector3f.h"
#include "Vector3d.h"
#include "Vector4f.h"
#include "Vector4d.h"
#include "Matrix3d.h"
#include "Matrix4f.h"
#include "Matrix4d.h"

#include <cmath>


namespace math {

template<typename T>
Matrix<T, 3, 3> get_rotate3_x(T radians) {
	return {1, 0, 0,
			0, std::cos(radians), -std::sin(radians),
			0, std::sin(radians), std::cos(radians)};
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_y(T radians) {
	return {std::cos(radians), 0, std::sin(radians),
			0, 1, 0,
			-std::sin(radians), 0, std::cos(radians)};
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_z(T radians) {
	return {std::cos(radians), -std::sin(radians), 0,
			std::sin(radians), std::cos(radians), 0,
			0, 0, 1};
}

template<typename T>
Matrix<T, 4, 4> rotate3_x(T radians) {
	return {1, 0, 0, 0,
			0, std::cos(radians), -std::sin(radians), 0,
			0, std::sin(radians), std::cos(radians), 0,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 4, 4> rotate3_y(T radians) {
	return {std::cos(radians), 0, std::sin(radians), 0,
			0, 1, 0, 0,
			-std::sin(radians), 0, std::cos(radians), 0,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 4, 4> rotate3_z(T radians) {
	return {std::cos(radians), -std::sin(radians), 0, 0,
			std::sin(radians), std::cos(radians), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_xyz(T roll, T pitch, T yaw) {
	return get_rotate3_x(roll) * get_rotate3_y(pitch) * get_rotate3_z(yaw);
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_xyz(const Matrix<T, 3, 1>& rpy) {
	return get_rotate3_xyz(rpy[0], rpy[1], rpy[2]);
}

template<typename T>
Matrix<T, 4, 4> rotate3_xyz(T roll, T pitch, T yaw) {
	return rotate3_x(roll) * rotate3_y(pitch) * rotate3_z(yaw);
}

template<typename T>
Matrix<T, 4, 4> rotate3_xyz(const Matrix<T, 3, 1>& rpy) {
	return rotate3_xyz(rpy[0], rpy[1], rpy[2]);
}

template<typename T>
Matrix<T, 4, 4> translate3(T x, T y, T z) {
	return {1, 0, 0, x,
			0, 1, 0, y,
			0, 0, 1, z,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 4, 4> translate3(const Matrix<T, 3, 1>& xyz) {
	return translate3(xyz[0], xyz[1], xyz[2]);
}

template<typename T>
Matrix<T, 4, 4> scale3(T x, T y, T z) {
	return {x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_axis_angle(const Matrix<T, 3, 1>& axis, T angle) {
	const T s = std::sin(angle);
	const T c = std::cos(angle);
	const T x = axis[0];
	const T y = axis[1];
	const T z = axis[2];
	return {	c + x*x*(1-c),		x*y*(1-c) - z*s,	x*z*(1-c) + y*s,
				y*x*(1-c) + z*s,	c + y*y*(1-c),		y*z*(1-c) - x*s,
				z*x*(1-c) - y*s,	z*y*(1-c) + x*s, 	c + z*z*(1-c)		};
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_xyz_intrinsic(T roll, T pitch, T yaw) {
	Matrix<T, 3, 3> rot = get_rotate3_axis_angle(Matrix<T, 3, 1>({0, 0, T(1)}), yaw);
	rot = get_rotate3_axis_angle(rot * Matrix<T, 3, 1>({0, T(1), 0}), pitch) * rot;
	rot = get_rotate3_axis_angle(rot * Matrix<T, 3, 1>({T(1), 0, 0}), roll) * rot;
	return rot;
}

template<typename T>
Matrix<T, 3, 3> get_rotate3_xyz_intrinsic(const Matrix<T, 3, 1>& rpy) {
	return get_rotate3_xyz_intrinsic(rpy[0], rpy[1], rpy[2]);
}

template<typename T>
Matrix<T, 4, 4> rotate3_xyz_intrinsic(T roll, T pitch, T yaw) {
	const Matrix<T, 3, 3> rot = get_rotate3_xyz_intrinsic(roll, pitch, yaw);
	return {rot(0, 0), rot(0, 1), rot(0, 2), 0,
			rot(1, 0), rot(1, 1), rot(1, 2), 0,
			rot(2, 0), rot(2, 1), rot(2, 2), 0,
			0, 0, 0, 1};
}

template<typename T>
Matrix<T, 4, 4> rotate3_xyz_intrinsic(const Matrix<T, 3, 1>& rpy) {
	return rotate3_xyz_intrinsic(rpy[0], rpy[1], rpy[2]);
}

/*
 * Converts a rotation matrix to intrinsic xyz euler angles.
 */
template<typename T>
Matrix<T, 3, 1> matrix_to_euler_xyz(const Matrix<T, 3, 3>& matrix) {
	const Matrix<T, 3, 1> x = matrix * Matrix<T, 3, 1>({T(1), 0, 0});
	const Matrix<T, 3, 1> y = matrix * Matrix<T, 3, 1>({0, T(1), 0});
	Matrix<T, 3, 1> rpy;
	rpy[2] = atan2(x[1], x[0]);
	const Matrix<T, 3, 1> X = get_rotate3_z(-rpy[2]) * x;
	rpy[1] = atan2(X[2], X[0]);
	const Matrix<T, 3, 1> Y = get_rotate3_z(-rpy[2]) * y;
	rpy[0] = atan2(Y[2], Y[1]);
	return rpy;
}


} // math

#endif /* MATH_INCLUDE_MATH_MATH3D_H_ */
