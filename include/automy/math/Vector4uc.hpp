
#ifndef INCLUDE_AUTOMY_MATH_VECTOR4UC_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR4UC_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector4uc : public Matrix<uint8_t, 4, 1> {
public:
	Vector4uc() = default;

	template<typename S>
	Vector4uc(const Matrix<S, 4, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector4uc& operator=(const Matrix<S, 4, 1>& mat) {
		Matrix<uint8_t, 4, 1>::operator=(mat);
		return *this;
	}

	Vector4uc(uint8_t x, uint8_t y, uint8_t z, uint8_t w) {
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[2] = z;
		(*this)[3] = w;
	}

	uint8_t& x() { return (*this)[0]; }
	uint8_t& y() { return (*this)[1]; }
	uint8_t& z() { return (*this)[2]; }
	uint8_t& w() { return (*this)[3]; }

	const uint8_t& x() const { return (*this)[0]; }
	const uint8_t& y() const { return (*this)[1]; }
	const uint8_t& z() const { return (*this)[2]; }
	const uint8_t& w() const { return (*this)[3]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector4uc& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector4uc& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector4uc& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector4uc& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector4uc& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR4UC_HPP_ */
