add_executable (test_prog main.cpp)

target_include_directories (test_prog
                            PRIVATE ../helloLib)

target_link_libraries (test_prog hello)
