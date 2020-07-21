cmake_minimum_required(VERSION 3.16)
project(PruebaServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(PruebaServer main.cpp main.cpp algoritmoGenetico/algoritmoGenetico.cpp algoritmoGenetico/algoritmoGenetico.h algoritmoGenetico/Espectro.cpp algoritmoGenetico/Espectro.h algoritmoGenetico/LinkendList.h algoritmoGenetico/Node.h algoritmoGenetico/Utilities.h algoritmoGenetico/Simulacion.cpp algoritmoGenetico/Simulacion.h algoritmoGenetico/stdc++.h)

