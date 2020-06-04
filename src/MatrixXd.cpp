
#include <automy/math/MatrixXd.hpp>


namespace vnx {

void read(TypeInput& in, ::automy::math::MatrixXd& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

void write(TypeOutput& out, const ::automy::math::MatrixXd& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

void read(std::istream& in, ::automy::math::MatrixXd& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::math::MatrixXd& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::math::MatrixXd& value) {
	value.accept(visitor);
}


} // vnx
