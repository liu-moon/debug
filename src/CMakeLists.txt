# 添加可执行文件
add_executable(main swap_buggy.cpp)
add_executable(prog leak.cpp)
target_compile_options(prog PRIVATE -g)