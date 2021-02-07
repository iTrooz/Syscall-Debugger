cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../final)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

project(SD_win)
project(SD_otracer)

file(GLOB_RECURSE UI_DATA targets/win/*)
file(GLOB_RECURSE OTRACER_DATA targets/otracer/*)
file(GLOB_RECURSE COMMON_DATA targets/common/*)
add_executable(SD_win ${COMMON_DATA} ${UI_DATA})
add_executable(SD_otracer ${COMMON_DATA} ${OTRACER_DATA})

target_include_directories(SD_win PUBLIC targets/common/headers)
target_include_directories(SD_win PUBLIC targets/win/headers)
target_include_directories(SD_otracer PUBLIC targets/common/headers)
target_include_directories(SD_otracer PUBLIC targets/otracer/headers)

find_package(Qt5Widgets REQUIRED)
target_link_libraries(SD_win Qt5::Widgets)
target_link_libraries(SD_win pthread)
target_link_libraries(SD_win cap)

target_link_libraries(SD_otracer pthread)
target_link_libraries(SD_otracer cap)

target_compile_definitions(SD_win PUBLIC TARGET_WIN)
target_compile_definitions(SD_otracer PUBLIC TARGET_OTRACER)
#target_link_libraries(SD_win libexplain.so)

