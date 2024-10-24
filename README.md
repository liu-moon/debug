# debug

## useful command

清屏

或者 Ctrl+L

```shell
!clear
```

开始调试

```shell
start
```

列出源码

```shell
list
```

执行下一行代码 不进入函数

```shell
next
```

执行下n行代码

```shell
next n
```

在函数处添加断电

```shell
b fun_name
```

查看断点信息

```shell
info breakpoints
```

运行代码

```shell
r
run
```

显示源代码窗口

```shell
layout src
```

显示调用栈

```shell
bt
```

运行完当前函数并返回到调用该函数的地方

```shell
finish
```

逐步执行代码，进入函数调用内部进行调试

```shell
s
step
```

重新绘制当前的 TUI（文本用户界面）窗口

```shell
refresh
```

继续运行程序，直到下一个断点、异常、或程序结束

```shell
continue
```

删除断点

在使用 delete 命令之前，你可以使用 info breakpoints 命令查看所有断点的编号

```shell
(gdb) delete num
```

显示当前程序中所有线程的信息

```shell
info threads
```

打印变量 a 的当前值

```shell
print a
```

显示变量 a 的类型

```shell
whatis a
```

gdb --tui --silent your_program

--tui：启用文本用户界面（TUI，Text User Interface）模式
--silent：启用静默模式，即启动时不显示 gdb 的版本信息、版权信息和欢迎消息

显示当前函数中所有局部变量的值

```shell
info locals
```

自动显示指定表达式或变量的值，对于调试过程中持续监视某些变量的变化非常有用。

```shell
display <表达式>
```

Valgrind 是一个非常强大的程序分析工具，主要用于内存泄漏检测和调试内存管理问题。它能够帮助开发者检测 C、C++ 以及其他使用动态内存分配的程序中常见的错误，如内存泄漏、非法内存访问和未初始化内存的使用等。

分析

```shell
valgrind ./main
```

indent

在编程中，indent 是一个 Unix 工具，主要用于格式化 C、C++ 代码。它能够将代码格式化为一致的缩进风格，增强代码的可读性，确保不同的代码块在缩进和排版上统一。

```shell
indent filename
indent -gnu filename
indent -kr filename
indent -bsd filename
```

查看gdb版本

```shell
gdb --version
```

lldb

LLDB 是一个调试器，与 gdb 类似，用于调试程序。LLDB 是由苹果公司开发的，并且作为 LLVM 项目的一部分维护。它支持 C、C++、Objective-C 和 Swift 等多种编程语言。LLDB 提供了强大的调试功能，包括断点设置、单步调试、查看内存、变量值等，与 gdb 类似，适合调试大型和复杂项目。

退出

```shell
q
```

编译时

- 在程序运行之前
- 示例错误
  - 语法相关错误
  - 缺失文件
  - 链接目标文件时的错误
- 可以使用 static_assert（C++11）捕获
- 编译器有时可以通过“警告”提示我们可能的错误
- 其他静态分析工具也可以保守地尝试预测并报告错误

运行时

当程序运行时

- 示例错误
  - 内存泄漏
  - 段错误（Segmentation Faults）
  - 性能相关错误
- 可以通过异常捕获和处理
- 可以通过 assert 捕获

编译器根据语言语法解析我们的代码

启用所有常见的编译器警告

```shell
gcc -Wall main.c -o prog 
```

比较数值是否相等写为：

```c++
7 == x
```

检测和报告在类型转换过程中可能出现的问题或潜在错误。

```shell
-Wconversion
```

将所有警告视为错误

```shell
-Werror
```

可以对用不同的编译器对一个程序进行检查

printf debugging

```c++
#define DEBUG 1

#if DEBUG
    printf("a = %d",a);
#endif
```

停用

```c++
#define DEBUG 1
#undef DEBUG

#if DEBUG
    printf("a = %d",a);
#endif
```

或者

```c++
#if DEBUG
    printf("a = %d",a);
#endif
```

在编译的时候加入

```shell
gcc -DDEBUG swap_buggy.c -o prog
```

编译程序时生成调试信息
在我们编译的代码中添加调试符号

- 文件名
- 行号
- 符号名

```shell
gcc -g
```

cmake中编译程序时生成调试信息

1. 使用 CMAKE_BUILD_TYPE 设置调试模式
  在 CMake 文件中设置编译类型为 Debug，CMake 会自动添加 -g 选项：
  
  ```cmake
  set(CMAKE_BUILD_TYPE Debug)
  ```

  然后，在构建项目时，确保使用以下命令生成调试信息：

  ```bash
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
  cmake --build build
  ```

2. 手动添加编译选项
  可以直接在 CMakeLists.txt 中通过 CMAKE_CXX_FLAGS 或 CMAKE_C_FLAGS 来添加 -g 选项。

  ```cmake
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
  ```

3. 为特定的目标添加 -g
  如果你只想为某个特定的目标添加 -g 选项，可以使用 target_compile_options()：
  
  ```cmake
  add_executable(my_program main.cpp)
  target_compile_options(my_program PRIVATE -g)
  ```

关闭优化

gcc -O0 是 GCC 编译器的一个选项，用于关闭优化。当你编译代码时，编译器通常会进行不同程度的优化，以提高代码的执行效率。然而，优化有时会使得调试变得更加复杂，因为编译器可能会对代码进行重排或省略某些部分。在某些情况下，优化可能会隐藏一些调试信息。

设置在使用 list 命令时显示的源代码行数

```bash
set listsize <number>
```

显示源代码中指定行号附近的代码。

```bash
list <number>
```

打印变量、类型或表达式的类型信息

```bash
ptype <name>
```

显示指定函数或文件范围内的所有变量和函数

```bash
info scope <function_name>
info scope <filename>
```

列出程序中定义的所有类型

```bash
info types
```

设置一个临时断点

```bash
tbreak <location>
```

`<location>`：可以是函数名、行号或地址，指定你希望设置临时断点的位置。

设置断点

```bash
break <location>
```

`<location>`：可以是函数名、行号、地址，甚至是某些条件。它指定你希望设置断点的程序位置。
