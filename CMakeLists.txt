CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
SET(CMAKE_CXX_STANDARD 20)
PROJECT(LDLT)

find_package(OpenMP REQUIRED)

add_compile_options(-fopenmp -g)

add_subdirectory(Block)
add_subdirectory(CsrBlock)
add_subdirectory(CoordinateBlock)
add_subdirectory(ldlt)
add_executable(main main.cpp)
target_link_libraries(main csr_block coordinate_block block ldlt OpenMP::OpenMP_CXX)