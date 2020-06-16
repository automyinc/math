/*
 * Vector2f.hpp
 *
 *  Created on: Jun 4, 2020
 *      Author: mad
 */

#ifndef INCLUDE_AUTOMY_MATH_VECTOR2F_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR2F_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector2f : public Matrix<float, 2, 1> {
public:
	Vector2f() = default;

	template<typename S>
	Vector2f(const Matrix<S, 2, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector2f& operator=(const Matrix<S, 2, 1>& mat) {
		Matrix<float, 2, 1>::operator=(mat);
		return *this;
	}

	Vector2f(float x, float y) {
		(*this)[0] = x;
		(*this)[1] = y;
	}

	float& x() { return (*this)[0]; }
	float& y() { return (*this)[1]; }

	const float& x() const { return (*this)[0]; }
	const float& y() const { return (*this)[1]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector2f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector2f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector2f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector2f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector2f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR2F_HPP_ */
