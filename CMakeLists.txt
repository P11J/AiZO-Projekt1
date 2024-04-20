cmake_minimum_required(VERSION 3.27)
project(Projekt1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Projekt1 main.cpp
        SortAlgInt.cpp
        SortAlgInt.h
        MenuFunctions.cpp
        MenuFunctions.h
        IntAnalysis.cpp
        IntAnalysis.h
        DoubleAnalysis.cpp
        DoubleAnalysis.h
        SortAlgDouble.cpp
        SortAlgDouble.h
        SortAlgFloat.cpp
        SortAlgFloat.h
)
