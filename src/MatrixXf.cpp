
#include <automy/math/MatrixXf.h>

#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>


namespace vnx {

void read(TypeInput& in, ::automy::math::MatrixXf& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

void write(TypeOutput& out, const ::automy::math::MatrixXf& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

void read(std::istream& in, ::automy::math::MatrixXf& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::math::MatrixXf& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::math::MatrixXf& value) {
	value.accept(visitor);
}


} // vnx
