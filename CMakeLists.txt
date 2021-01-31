cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../final)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

project(SD_ui)
project(SD_otracer)

file(GLOB_RECURSE UI_DATA targets/ui/*)
file(GLOB_RECURSE OTRACER_DATA targets/otracer/*)
file(GLOB_RECURSE COMMON_DATA targets/common/*)
add_executable(SD_ui ${COMMON_DATA} ${UI_DATA} ${OTRACER_DATA})
add_executable(SD_otracer ${COMMON_DATA} ${OTRACER_DATA})

target_include_directories(SD_ui PUBLIC targets/common/headers)
target_include_directories(SD_ui PUBLIC targets/ui/headers)
target_include_directories(SD_otracer PUBLIC targets/common/headers)
target_include_directories(SD_otracer PUBLIC targets/otracer/headers)

target_include_directories(SD_ui PUBLIC targets/otracer/headers) # TODO TEMP

find_package(Qt5Widgets REQUIRED)
target_link_libraries(SD_ui Qt5::Widgets)
target_link_libraries(SD_ui pthread)
target_link_libraries(SD_otracer libexplain.so)

