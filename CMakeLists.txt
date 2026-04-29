cmake_minimum_required(VERSION 3.20)

project(enoge VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

add_executable(enoge
    src/app/Application.cpp
    src/app/main.cpp
)

target_include_directories(enoge
    PRIVATE
        src
)

target_link_libraries(enoge
    PRIVATE
        PkgConfig::SDL3
)

if(MSVC)
    target_compile_options(enoge PRIVATE /W4 /permissive-)
else()
    target_compile_options(enoge PRIVATE -Wall -Wextra -Wpedantic)
endif()