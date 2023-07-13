cmake_minimum_required(VERSION 3.5)

project(QTNetworkSQLApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network Sql)

set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTNetworkSQLApp
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(QTNetworkSQLApp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QTNetworkSQLApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QTNetworkSQLApp PRIVATE Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Sql)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTNetworkSQLApp)
endif()
