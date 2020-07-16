cmake_minimum_required(VERSION 3.16)
project(PruebaServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(PruebaServer main.cpp main.cpp AlgoritmoGenetico/algoritmoGenetico.cpp AlgoritmoGenetico/algoritmoGenetico.h AlgoritmoGenetico/ListaEspectros.cpp AlgoritmoGenetico/ListaEspectros.h AlgoritmoGenetico/Espectro.cpp AlgoritmoGenetico/Espectro.h AlgoritmoGenetico/NodoEspectro.cpp AlgoritmoGenetico/NodoEspectro.h AlgoritmoGenetico/stdc++.h AlgoritmoGenetico/Utilities.cpp AlgoritmoGenetico/Utilities.h)

