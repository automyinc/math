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

#ifndef MATH_INCLUDE_MATH_UTIL_H_
#define MATH_INCLUDE_MATH_UTIL_H_

#include <math/Matrix.h>

#include <cmath>


namespace math {

/*
 * Computes angle difference as a - b in radians.
 */
template<typename T>
T angle_diff(T a, T b) {
	return std::atan2(std::sin(a - b), std::cos(a - b));
}

/*
 * Computes angle difference as a - b in radians.
 */
template<typename T>
Matrix<T,3,1> angle_diff(const Matrix<T,3,1>& a, const Matrix<T,3,1>& b) {
	return {angle_diff(a[0], b[0]), angle_diff(a[1], b[1]), angle_diff(a[2], b[2])};
}


} // math

#endif /* MATH_INCLUDE_MATH_UTIL_H_ */
