cmake_minimum_required(VERSION 3.27.7)

project(game LANGUAGES CXX)
set(wxWidgets_ROOT_DIR "C:/Users/User/Project/wxWidgets")
set(wxWidgets_LIB_DIR "C:/Users/User/Project/wxWidgets/lib/gcc1320_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
 if(wxWidgets_USE_FILE) # not defined in CONFIG mode
include(${wxWidgets_USE_FILE})
 endif()

 add_library(game STATIC game.cpp)