
#ifndef INCLUDE_AUTOMY_MATH_VECTOR2D_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR2D_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector2d : public Matrix<double, 2, 1> {
public:
	Vector2d() = default;

	template<typename S>
	Vector2d(const Matrix<S, 2, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector2d& operator=(const Matrix<S, 2, 1>& mat) {
		Matrix<double, 2, 1>::operator=(mat);
		return *this;
	}

	Vector2d(double x, double y) {
		(*this)[0] = x;
		(*this)[1] = y;
	}

	double& x() { return (*this)[0]; }
	double& y() { return (*this)[1]; }

	const double& x() const { return (*this)[0]; }
	const double& y() const { return (*this)[1]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector2d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector2d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector2d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector2d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR2D_HPP_ */
