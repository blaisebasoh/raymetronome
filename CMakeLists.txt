cmake_minimum_required(VERSION 3.6)
project(raymetronome LANGUAGES CXX)

find_package(raylib CONFIG REQUIRED)
find_path(RAYGUI_INCLUDE_DIRS "raygui.h")

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${RAYGUI_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
