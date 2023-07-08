cmake_minimum_required(VERSION 3.21)
project(FatherActivity)

set(CMAKE_CXX_STANDARD 14)

add_executable(FatherActivity main.cpp DocumentReceiver.cpp DocumentReceiver.h Node.cpp Node.h Disease.cpp Disease.h DecisionTree.cpp DecisionTree.h)
