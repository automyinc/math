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

#ifndef MATH_INCLUDE_MATH_VECTOR4F_H_
#define MATH_INCLUDE_MATH_VECTOR4F_H_

#include "Matrix.h"


namespace math {

class Vector4f : public Matrix<float, 4, 1> {
public:
	Vector4f() {}
	
	Vector4f(const Matrix<float, 4, 1>& mat) : Matrix(mat) {}
	
	Vector4f(float x, float y, float z, float w) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = w;
	}
	
	float& x() { return data[0]; }
	float& y() { return data[1]; }
	float& z() { return data[2]; }
	float& w() { return data[3]; }
	
	const float& x() const { return data[0]; }
	const float& y() const { return data[1]; }
	const float& z() const { return data[2]; }
	const float& w() const { return data[3]; }
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Vector4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Vector4f& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Vector4f& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Vector4f& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Vector4f& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR4F_H_ */
