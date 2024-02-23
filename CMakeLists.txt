cmake_minimum_required(VERSION 3.27)
project(LoxInterpreter C)

set(CMAKE_C_STANDARD 11)

add_executable(LoxInterpreter main.c
        common.h
        chunk.h
        memory.h
        chunk.c
        memory.c
        debug.h
        debug.c
        value.h
        value.c
        vm.h
        vm.c
)
