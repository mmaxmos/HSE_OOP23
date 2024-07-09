cmake_minimum_required(VERSION 3.23)
project(Project_OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_OOP main.cpp PaperProduct.cpp PaperProduct.h Book.cpp Book.h Page.cpp Page.h Block.cpp Block.h)
