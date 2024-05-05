cmake_minimum_required(VERSION 3.15)

project(MSV_ORIGIN)

set(CMAKE_CXX_STANDARD 20)

add_executable(MSV_ORIGIN Main/main.cpp SyntaxAnaliys/Syntax.cpp SyntaxAnaliys/Syntax.h Includes/Liabrary.h GeneralTypes/TypeController/TypeController.cpp GeneralTypes/TypeController/TypeController.h GeneralTypes/BaseTypes/BaseType.cpp GeneralTypes/BaseTypes/BaseType.h)