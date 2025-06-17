add_library(csr_block CsrBlock.cpp)
target_include_directories(csr_block PUBLIC .)
target_link_libraries(csr_block block)