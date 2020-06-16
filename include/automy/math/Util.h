
#ifndef INCLUDE_AUTOMY_MATH_UTIL_H_
#define INCLUDE_AUTOMY_MATH_UTIL_H_

#include <automy/math/Matrix.hpp>

#include <cmath>


namespace automy {
namespace math {

/*
 * Normalize angle in [rad] between +pi and -pi.
 */
template<typename T>
T normalize_angle(T rad) {
	T angle = std::fmod(rad, T(2 * M_PI));
	if(angle > M_PI) {
		angle -= T(2 * M_PI);
	} else if(angle < -M_PI) {
		angle += T(2 * M_PI);
	}
	return angle;
}

/*
 * Normalize angle in [rad] between 0 and 2 * pi.
 */
template<typename T>
T normalize_angle_positive(T rad) {
	T angle = std::fmod(rad, T(2 * M_PI));
	if(angle < 0) {
		angle += T(2 * M_PI);
	}
	return angle;
}

/*
 * Computes angle difference as a - b in radians.
 */
template<typename T>
T angle_diff(T a, T b) {
	return std::atan2(std::sin(a - b), std::cos(a - b));
}

/*
 * Computes 3D angle difference as a - b in radians.
 */
template<typename T>
Matrix<T, 3, 1> angle_diff(const Matrix<T, 3, 1>& a, const Matrix<T, 3, 1>& b) {
	return {angle_diff(a[0], b[0]), angle_diff(a[1], b[1]), angle_diff(a[2], b[2])};
}


} // math
} // automy

#endif /* MATH_INCLUDE_MATH_UTIL_H_ */
