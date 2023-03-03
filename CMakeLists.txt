cmake_minimum_required(VERSION 3.0.0)
project(fs VERSION 0.1.0)

add_executable(fs main.cpp)
target_include_directories(fs PRIVATE .)
