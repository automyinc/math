
#ifndef INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_
#define INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_

#include <automy/math/MatrixX.hpp>


namespace automy {
namespace math {

class MatrixXd : public MatrixX<double> {
public:
	MatrixXd() = default;

	MatrixXd(size_t rows, size_t cols) : MatrixX<double>(rows, cols) {}

	template<typename S>
	MatrixXd(const MatrixX<S>& B) : MatrixX<double>(B) {}

	template<typename S>
	MatrixXd& operator=(const MatrixX<S>& B) {
		MatrixX<double>::operator=(B);
		return this;
	}

};


} // math
} // automy

#endif /* INCLUDE_AUTOMY_MATH_MATRIXXD_HPP_ */
