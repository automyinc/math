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

#ifndef MATH_INCLUDE_MATH_VECTOR2I_H_
#define MATH_INCLUDE_MATH_VECTOR2I_H_

#include "Matrix.h"


namespace math {

class Vector2i : public Matrix<int32_t, 2, 1> {
public:
	Vector2i() {}
	
	Vector2i(const Matrix<int32_t, 2, 1>& mat) : Matrix(mat) {}
	
	Vector2i(int32_t x, int32_t y) {
		data[0] = x;
		data[1] = y;
	}
	
	int32_t& x() { return data[0]; }
	int32_t& y() { return data[1]; }
	
	const int32_t& x() const { return data[0]; }
	const int32_t& y() const { return data[1]; }
	
};


} // math


namespace vnx {

inline void read(TypeInput& in, ::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

inline void write(TypeOutput& out, const ::math::Vector2i& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

inline void read(std::istream& in, ::math::Vector2i& value) {
	value.read(in);
}

inline void write(std::ostream& out, const ::math::Vector2i& value) {
	value.write(out);
}

inline void accept(Visitor& visitor, const ::math::Vector2i& value) {
	value.accept(visitor);
}


} // vnx

#endif /* MATH_INCLUDE_MATH_VECTOR2I_H_ */
