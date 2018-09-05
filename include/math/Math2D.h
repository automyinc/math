
#ifndef MATH_INCLUDE_MATH_MATH2D_H_
#define MATH_INCLUDE_MATH_MATH2D_H_

#include "Util.h"
#include "Matrix.h"
#include "Vector2i.h"
#include "Vector2f.h"
#include "Vector2d.h"
#include "Vector3i.h"
#include "Vector3f.h"
#include "Vector3d.h"
#include "Matrix2d.h"
#include "Matrix3d.h"

#include <cmath>


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


} // math

#endif /* MATH_INCLUDE_MATH_MATH2D_H_ */
