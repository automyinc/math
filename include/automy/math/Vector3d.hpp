
#ifndef INCLUDE_AUTOMY_MATH_VECTOR3D_HPP_
#define INCLUDE_AUTOMY_MATH_VECTOR3D_HPP_

#include <automy/math/Matrix.hpp>


namespace automy {
namespace math {

class Vector3d : public Matrix<double, 3, 1> {
public:
	Vector3d() = default;

	template<typename S>
	Vector3d(const Matrix<S, 3, 1>& mat) {
		*this = mat;
	}

	template<typename S>
	Vector3d& operator=(const Matrix<S, 3, 1>& mat) {
		Matrix<double, 3, 1>::operator=(mat);
		return *this;
	}

	Vector3d(double x, double y, double z) {
		(*this)[0] = x;
		(*this)[1] = y;
		(*this)[2] = z;
	}

	double& x() { return (*this)[0]; }
	double& y() { return (*this)[1]; }
	double& z() { return (*this)[2]; }

	const double& x() const { return (*this)[0]; }
	const double& y() const { return (*this)[1]; }
	const double& z() const { return (*this)[2]; }

};


} // math
} // automy


namespace vnx {

inline void read(TypeInput& in, ::automy::math::Vector3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::automy::math::Vector3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::automy::math::Vector3d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::automy::math::Vector3d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::automy::math::Vector3d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* INCLUDE_AUTOMY_MATH_VECTOR3D_HPP_ */
