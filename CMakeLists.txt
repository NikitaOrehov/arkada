cmake_minimum_required(VERSION 3.27.7)
project(game LANGUAGES CXX)
set(wxWidgets_ROOT_DIR "C:/Users/User/Project/wxWidgets")
set(wxWidgets_LIB_DIR "C:/Users/User/Project/wxWidgets/lib/gcc1320_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
 if(wxWidgets_USE_FILE) # not defined in CONFIG mode
include(${wxWidgets_USE_FILE})
 endif()

#include_directories(game)
#add_subdirectory(game)
 
#include_directories(MyPanel)
#add_subdirectory(MyPanel)

add_executable(game main.cpp game.cpp MyPanel.cpp patron.cpp ship.cpp ship1.cpp ship2.cpp ship3.cpp)
target_link_libraries(game ${wxWidgets_LIBRARIES})#game MyPanel
target_include_directories(game PRIVATE ${wxWidgets_INCLUDE_DIRS})