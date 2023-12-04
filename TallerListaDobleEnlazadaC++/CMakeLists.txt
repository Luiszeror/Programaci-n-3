cmake_minimum_required(VERSION 3.26)
project(TallerListaDobleEnlazadaC__)

set(CMAKE_CXX_STANDARD 17)

add_executable(TallerListaDobleEnlazadaC__ main.cpp
        Phone.cpp
        Phone.h
        LinkedDouble.cpp
        LinkedDouble.h
        Node.h
)
