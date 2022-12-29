cmake_minimum_required(VERSION 3.22.0)
project(Figures)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FigureDynamicLib SHARED Figure.h Figure.cpp MyExceptions.h MyExceptions.cpp
mystdlib.h Quadrilateral.cpp Quadrilateral.h quadrilaterals.h Trinagle.cpp
Trinagle.h trinagles.h)
add_executable(FigureEXE main.cpp)
target_link_libraries(FigureEXE FigureDynamicLib)