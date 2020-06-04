
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


} // math
} // automy

#endif /* MATH_INCLUDE_MATH_MATH2D_H_ */
