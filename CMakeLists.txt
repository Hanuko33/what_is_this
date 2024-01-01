cmake_minimum_required(VERSION 3.10)
project(wtf_is_this)
set(CMAKE_BUILD_TYPE DEBUG)
add_executable(wtf_is_this cmodules/print.c cmodules/stack.c man.c main.c)
