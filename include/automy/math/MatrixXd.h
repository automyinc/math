
#ifndef INCLUDE_AUTOMY_MATH_MATRIXXD_H_
#define INCLUDE_AUTOMY_MATH_MATRIXXD_H_

#include "MatrixX.h"


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

#endif /* MATH_INCLUDE_MATH_MATRIXXD_H_ */
