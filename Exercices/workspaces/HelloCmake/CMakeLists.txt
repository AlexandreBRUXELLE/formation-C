cmake_minimum_required(VERSION 2.8)

project(hello_cmake)

add_executable(hellocmake main.c)

target_link_libraries(hellocmake
                      ncurses)

