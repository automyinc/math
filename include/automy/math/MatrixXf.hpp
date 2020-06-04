
#ifndef INCLUDE_AUTOMY_MATH_MATRIXXF_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIXXF_HPP_

#include <automy/math/MatrixX.hpp>


namespace automy {
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
} // automy

#endif /* INCLUDE_AUTOMY_MATH_MATRIXXF_HPP_ */
