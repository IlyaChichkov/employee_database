cmake_minimum_required(VERSION 3.24)
# Add your project name
project(employee_database)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        src/Employee.cpp
        src/Employee.h
        src/Database.cpp
        src/Database.h
        src/UserInterface.cpp
        src/UserInterface.h)
