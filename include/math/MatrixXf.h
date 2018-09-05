
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
