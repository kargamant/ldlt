CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(LDLT)

add_subdirectory(Block)
add_executable(main main.cpp)
target_link_libraries(main block)