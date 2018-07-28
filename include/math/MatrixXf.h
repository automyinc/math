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

#ifndef MATH_INCLUDE_MATH_MATRIXXF_H_
#define MATH_INCLUDE_MATH_MATRIXXF_H_

#include "MatrixX.h"


namespace math {

class MatrixXf : public MatrixX<float> {
public:
	MatrixXf() {}
	
	MatrixXf(size_t rows, size_t cols) : MatrixX<float>(rows, cols) {}
	
	MatrixXf(const MatrixXf& B) : MatrixX<float>(B) {}
	
	template<typename S>
	MatrixXf(const MatrixX<S>& B) : MatrixX<float>(B) {}
	
};


} // math

#endif /* MATH_INCLUDE_MATH_MATRIXXF_H_ */
