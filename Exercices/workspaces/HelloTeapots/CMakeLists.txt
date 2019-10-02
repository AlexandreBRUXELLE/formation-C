cmake_minimum_required (VERSION 2.8.5)

project (HelloTeapots)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(X11 )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set ( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/ )

file(GLOB PROJ_SRC
  ./src/*.c
)

#file(GLOB PROJ_HEADER
#  ./include/*.h
#)

message( STATUS ${PROJ_SRC} )

#LINK_DIRECTORIES(${PROJ_HEADER})

add_executable(HelloTeapots ${PROJ_SRC})

TARGET_LINK_LIBRARIES (
  HelloTeapots
  ${SDL2_LIBRARIES}
  ${X11_LIBRARIES}
  ${OPENGL_LIBRARIES} 
  ${GLUT_LIBRARY}
)
