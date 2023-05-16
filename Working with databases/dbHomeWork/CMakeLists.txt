cmake_minimum_required(VERSION 3.22.0)

project(dbHomeWork)


add_executable(dbHomeWork main.cpp)
add_subdirectory("D:\\netology\\Working with databases\\libpqxx-7.7.5" libqpxx-build)
target_compile_features(dbHomeWork PRIVATE cxx_std_17)

target_link_libraries(dbHomeWork pqxx)
 
