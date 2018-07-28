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

#ifndef MATH_INCLUDE_MATH_VECTOR3I_H_
#define MATH_INCLUDE_MATH_VECTOR3I_H_

#include "Matrix.h"


namespace math {

class Vector3i : public Matrix<int32_t, 3, 1> {
public:
	Vector3i() {}
	
	Vector3i(const Matrix<int32_t, 3, 1>& mat) : Matrix(mat) {}
	
	Vector3i(int32_t x, int32_t y, int32_t z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}
	
	int32_t& x() { return data[0]; }
	int32_t& y() { return data[1]; }
	int32_t& z() { return data[2]; }
	
	const int32_t& x() const { return data[0]; }
	const int32_t& y() const { return data[1]; }
	const int32_t& z() const { return data[2]; }
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Vector3i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Vector3i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Vector3i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Vector3i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Vector3i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR3I_H_ */
