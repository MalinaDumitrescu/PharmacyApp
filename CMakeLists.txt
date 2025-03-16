cmake_minimum_required(VERSION 3.28)
project(Lab4_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4_OOP main.cpp
        UI/UserInterface.h
        UI/UserInterface.cpp
        Controller/Controller.cpp
        Controller/Controller.h
        Test/Test.cpp
        Domain/Medicine.cpp
        Repository/Repository.cpp)
