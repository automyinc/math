 /*************************************************************************
 * 
 *  [2017] - [2018] Automy Inc. 
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Automy Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Automy Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Automy Incorporated.
 */

#ifndef MATH_INCLUDE_MATH_VECTOR3D_H_
#define MATH_INCLUDE_MATH_VECTOR3D_H_

#include "Matrix.h"


namespace math {

class Vector3d : public Matrix<double, 3, 1> {
public:
	Vector3d() {}
	
	Vector3d(const Matrix<double, 3, 1>& mat) : Matrix(mat) {}
	
	Vector3d(double x, double y, double z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}
	
	double& x() { return data[0]; }
	double& y() { return data[1]; }
	double& z() { return data[2]; }
	
	const double& x() const { return data[0]; }
	const double& y() const { return data[1]; }
	const double& z() const { return data[2]; }
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Vector3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Vector3d& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Vector3d& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Vector3d& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Vector3d& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR3D_H_ */
