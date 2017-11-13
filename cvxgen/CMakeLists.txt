cmake_minimum_required(VERSION 2.8)

project(test_solver)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(test_solver testsolver.c ldl.c util.c solver.c matrix_support.c main.cpp)
target_link_libraries(test_solver m)

target_include_directories(test_solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

