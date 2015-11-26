cmake_minimum_required(VERSION 3.3)
project(Handmade_Hero)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

set(SOURCE_FILES main.cpp)
add_executable(Handmade_Hero ${SOURCE_FILES})
target_link_libraries(Handmade_Hero ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})