cmake_minimum_required(VERSION 3.27)
project(Projekt1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Projekt1 main.cpp
        SortAlgType/SortAlgInt.cpp
        SortAlgType/SortAlgInt.h
        MenuFunctions.cpp
        MenuFunctions.h
        TypeAnalysis/IntAnalysis.cpp
        TypeAnalysis/IntAnalysis.h
        TypeAnalysis/DoubleAnalysis.cpp
        TypeAnalysis/DoubleAnalysis.h
        SortAlgType/SortAlgDouble.cpp
        SortAlgType/SortAlgDouble.h
        SortAlgType/SortAlgFloat.cpp
        SortAlgType/SortAlgFloat.h
        TypeAnalysis/FloatAnalysis.cpp
        TypeAnalysis/FloatAnalysis.h
)
