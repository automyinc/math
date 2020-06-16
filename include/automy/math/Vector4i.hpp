
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4I_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR4I_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector4i : public Matrix<int32_t, 4, 1> {
public:
	Vector4i() = default;

	template<typename S>
	Vector4i(const Matrix<S, 4, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector4i& operator=(const Matrix<S, 4, 1>& mat) {
		Matrix<int32_t, 4, 1>::operator=(mat);
		return *this;
	}

	Vector4i(int32_t x, int32_t y, int32_t z, int32_t w) {
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[2] = z;
		(*this)[3] = w;
	}

	int32_t& x() { return (*this)[0]; }
	int32_t& y() { return (*this)[1]; }
	int32_t& z() { return (*this)[2]; }
	int32_t& w() { return (*this)[3]; }

	const int32_t& x() const { return (*this)[0]; }
	const int32_t& y() const { return (*this)[1]; }
	const int32_t& z() const { return (*this)[2]; }
	const int32_t& w() const { return (*this)[3]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector4i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector4i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector4i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector4i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector4i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR4I_HPP_ */
