# 设置CMake最低版本要求  
cmake_minimum_required(VERSION 3.10)  
  
# 设置项目名称和版本  
project(MyProject VERSION 1.0)  
  
# 设置C++标准  
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
  
# 添加源文件  
add_executable(MyProject main.cpp)  
add_library(MyLibrary tools.cpp)
# 添加库文件（如果有的话）  
target_link_libraries(MyProject MyLibrary)  
  
