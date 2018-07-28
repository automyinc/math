cmake_minimum_required(VERSION 2.6)
project(automy-math)

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(automy_math SHARED
	${GENERATED_SOURCE_FILES}
	src/MatrixXf.cpp
	src/MatrixXd.cpp
)

target_include_directories(automy_math PUBLIC include generated/include)

target_link_libraries(automy_math vnx_base)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY generated/include/ DESTINATION include)
install(DIRECTORY interface/ DESTINATION interface/math)

install(TARGETS automy_math DESTINATION lib)
