cmake_minimum_required(VERSION 3.26)
project(Taller2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taller2 main.cpp
        Phone.cpp
        Phone.h
        LinkedDouble.cpp
        LinkedDouble.h
        Node.h
        HandlingPhone.cpp
        HandlingPhone.h)
