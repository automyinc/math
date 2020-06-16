
#ifndef INCLUDE_AUTOMY_MATH_VECTOR2I_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR2I_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector2i : public Matrix<int32_t, 2, 1> {
public:
	Vector2i() = default;

	template<typename S>
	Vector2i(const Matrix<S, 2, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector2i& operator=(const Matrix<S, 2, 1>& mat) {
		Matrix<int32_t, 2, 1>::operator=(mat);
		return *this;
	}

	Vector2i(int32_t x, int32_t y) {
		(*this)[0] = x;
		(*this)[1] = y;
	}

	int32_t& x() { return (*this)[0]; }
	int32_t& y() { return (*this)[1]; }

	const int32_t& x() const { return (*this)[0]; }
	const int32_t& y() const { return (*this)[1]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector2i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector2i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector2i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR2I_HPP_ */
