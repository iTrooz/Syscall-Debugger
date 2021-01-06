cmake_minimum_required(VERSION 3.17)
project(Syscall_Debugger)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../final)

file( GLOB SOURCES src/*.cpp )
file( GLOB HEADERS headers/*.h )
add_executable(Syscall_Debugger ${SOURCES} ${HEADERS})

find_package(Qt5Widgets REQUIRED)
target_link_libraries(Syscall_Debugger Qt5::Widgets)
target_link_libraries(Syscall_Debugger pthread)
target_include_directories(Syscall_Debugger PUBLIC headers)
