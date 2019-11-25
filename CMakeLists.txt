cmake_minimum_required(VERSION 3.13)

project(knoke)

file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(knoke ${SOURCE_FILES})
target_link_libraries(knoke sfml-graphics sfml-audio)
