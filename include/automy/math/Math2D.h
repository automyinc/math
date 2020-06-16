
#ifndef INCLUDE_AUTOMY_MATH_MATH2D_H_
#define INCLUDE_AUTOMY_MATH_MATH2D_H_

#include <automy/math/Util.h>
#include <automy/math/Matrix.hpp>

#include <cmath>


namespace automy {
namespace math {

template<typename T>
Matrix<T, 2, 2> get_rotate2(T radians) {
	return {std::cos(radians), -std::sin(radians),
			std::sin(radians), std::cos(radians)};
}

template<typename T>
Matrix<T, 3, 3> rotate2(T radians) {
	return {std::cos(radians), -std::sin(radians), 0,
			std::sin(radians), std::cos(radians), 0,
			0, 0, 1};
}

template<typename T>
Matrix<T, 3, 3> translate2(T x, T y) {
	return {1, 0, x,
			0, 1, y, 
			0, 0, 1};
}

template<typename T>
Matrix<T, 3, 3> translate2(const Matrix<T, 2, 1>& xy) {
	return translate2(xy[0], xy[1]);
}

template<typename T>
Matrix<T, 3, 3> scale2(T x, T y) {
	return {x, 0, 0,
			0, y, 0, 
			0, 0, 1};
}

/*
 * Creates a 2D (x, y, yaw) transformation matrix.
 */
template<typename T>
Matrix<T, 3, 3> transform2(T x, T y, T rad) {
	return translate2(x, y) * rotate2(rad);
}

/*
 * Creates a 2D (x, y, yaw) transformation matrix.
 */
template<typename T>
Matrix<T, 3, 3> transform2(const Matrix<T, 3, 1>& pose) {
	return translate2(pose[0], pose[1]) * rotate2(pose[2]);
}


/*
 * Creates a 2.5D (x, y, yaw) rotation matrix.
 */
template<typename T>
Matrix<T, 4, 4> rotate25(T rad) {
	return {std::cos(rad), -std::sin(rad), 0, 0,
			std::sin(rad), std::cos(rad), 0, 0,
			0, 0, 1, rad,
			0, 0, 0, 1};
}

/*
 * Creates a 2.5D (x, y, yaw) translation matrix.
 */
template<typename T>
Matrix<T, 4, 4> translate25(T x, T y) {
	return {1, 0, 0, x,
			0, 1, 0, y,
			0, 0, 1, 0,
			0, 0, 0, 1};
}

/*
 * Creates a 2.5D (x, y, yaw) transformation matrix.
 */
template<typename T>
Matrix<T, 4, 4> transform25(T x, T y, T rad) {
	return translate25(x, y) * rotate25(rad);
}

/*
 * Creates a 2.5D (x, y, yaw) transformation matrix.
 */
template<typename T>
Matrix<T, 4, 4> transform25(const Matrix<T, 3, 1>& pose) {
	return translate25(pose[0], pose[1]) * rotate25(pose[2]);
}


} // math
} // automy

#endif /* MATH_INCLUDE_MATH_MATH2D_H_ */
