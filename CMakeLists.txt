cmake_minimum_required(VERSION 3.10)
project(what_is_this)
set(CMAKE_BUILD_TYPE DEBUG)
add_executable(what_is_this cmodules/sleep.c cmodules/print.c cmodules/stack.c man.c main.c)
