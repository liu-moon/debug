# 指定 CMake 的最低版本要求为 3.20.0
cmake_minimum_required(VERSION 3.20.0)

project(debug CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Debug")

# 只在 Debug 模式下使用 no optimization (-O0)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_subdirectory(src bin)