cmake_minimum_required(VERSION 3.16)
project(enemy)

set(CMAKE_CXX_STANDARD 14)

add_executable(enemy main.cpp Enemigo.cpp Enemigo.h Espectro.cpp Espectro.h Rojo.cpp Rojo.h Azul.cpp Azul.h Node.h Node.cpp LinkedList.h LinkedList.cpp)