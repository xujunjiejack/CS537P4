cmake_minimum_required(VERSION 3.6)
project(CS537P4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c xv6/user/clonetest.c xv6/user/locktest.c xv6/user/spinlock.h xv6/user/spinlock.c)
add_executable(CS537P4 ${SOURCE_FILES})