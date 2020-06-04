
#ifndef INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_

#include <automy/math/MatrixX.hpp>


namespace automy {
namespace math {

class MatrixXd : public MatrixX<double> {
public:
	MatrixXd() {}

	MatrixXd(size_t rows, size_t cols) : MatrixX<double>(rows, cols) {}

	MatrixXd(const MatrixXd& B) : MatrixX<double>(B) {}

	template<typename S>
	MatrixXd(const MatrixX<S>& B) : MatrixX<double>(B) {}

};


} // math
} // automy

#endif /* INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_ */
