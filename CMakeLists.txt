CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(LDLT)

find_package(OpenMP REQUIRED)

add_compile_options(-fopenmp -O3)

add_subdirectory(Block)
add_subdirectory(ldlt)
add_executable(main main.cpp)
target_link_libraries(main block ldlt OpenMP::OpenMP_CXX)