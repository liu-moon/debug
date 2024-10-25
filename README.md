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

检测程序 main 中的内存泄漏问题的命令。

```shell
valgrind --leak-check=full ./main
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

在TUI（文本用户界面）模式下显示寄存器窗口

```bash
layout regs
```

这个窗口会显示当前所有 CPU 寄存器的内容，帮助开发者在调试时监视寄存器值的变化。

显示程序的汇编代码

```bash
layout asm
```

切换到汇编视图窗口，显示当前程序的汇编指令，而不是源代码。这对调试低级程序或深入了解程序执行的汇编层细节非常有用。

在 TUI（Text User Interface，文本用户界面）模式下切换和控制当前活动窗口的焦点。

```bash
focus <window>
```

- focus src：将焦点切换到源代码窗口。
- focus asm：将焦点切换到汇编代码窗口。
- focus regs：将焦点切换到寄存器窗口。
- focus next：将焦点切换到下一个窗口，按顺序循环。

调整 TUI 模式下窗口的高度

```bash
winheight <window> <height>
```

- <window>：指定要调整的窗口，常用的有 src（源代码窗口）、asm（汇编窗口）、regs（寄存器窗口）等。
- <height>：设置窗口的高度（行数），即窗口显示的行数。

设置程序的输入/输出终端

```bash
$ tty
/dev/pts/4

(gdb) tty /dev/pts/4
```

输出到文件

```bash
(gdb) run > output.txt
```

添加条件断点

```bash
br 9 if i > 995
br 9 if i > 995 && i < 999
```

继续运行到指定的代码行或函数名

```bash
advance <location>
```

<location>：可以是行号、函数名、或文件中的行号。程序会继续运行到该位置并暂停。

让程序继续执行，直到到达当前循环结束或指定位置

```bash
until [<location>]
```

<location>：可选参数，可以是行号、函数名或文件中的行号。如果不指定，gdb 会继续执行程序，直到到达当前堆栈帧中的下一个行号（常用于跳过循环中的剩余代码）。

在 gdb 中，jump 命令用于立即跳转到指定的代码行或地址，并从该位置继续执行。与其他调试命令不同，jump 会改变程序的控制流，不执行中间的代码部分。它不会执行到达该行之前的代码，而是直接跳转到目标位置并从那里开始执行。

```bash
jump <location>
```

- <location>：可以是行号、函数名或内存地址，指定你希望跳转到的位置。该命令立即将控制流跳转到该位置。

主要使用场景：
- 跳过代码：当你在调试时，发现某些代码部分不需要执行，或者你想跳过一些中间的代码，可以使用 jump 直接跳到后面的代码继续执行。
- 跳回某段代码重新执行：如果你希望重新执行某些代码（如重新进入一个循环或条件语句），可以使用 jump 跳回到之前的位置，重复执行该部分代码。
- 跳过异常代码段：当程序因为某些错误无法继续运行时，使用 jump 跳过有问题的代码段，继续执行。

设置观察点

```bash
watch <expression>
```

<expression>：可以是一个变量或任意内存表达式。当该表达式的值发生变化时，程序会暂停。

设置一个只读观察点

```bash
rwatch <expression>
```

即当指定的变量或内存地址被读取时，程序会暂停执行。这与 watch 命令（用于监视变量的写操作）不同，rwatch 专注于监视变量的读取操作，帮助你调试程序中变量何时、如何被读取。

<expression>：可以是一个变量名或内存地址。当该变量或地址的内容被读取时，程序会暂停。

禁用断点、观察点或捕捉点

```bash
disable [breakpoints] [<number> ...]
disable watchpoints [<number> ...]
disable catchpoints [<number> ...]
```

- breakpoints：禁用指定的断点。可以通过编号指定某个断点，或者不指定编号时禁用所有断点。
- watchpoints：禁用指定的观察点。
- catchpoints：禁用指定的捕捉点。

将你当前设置的断点保存到一个文件中

```bash
save breakpoints <filename>
save breakpoints debugging_session_august.txt
```

加载保存的断点
可以在以后的调试会话中使用 source 命令从文件中恢复断点：

```bash
(gdb) source breakpoints.txt
```

自动显示指定表达式或变量的值
每当程序暂停时（例如遇到断点或单步执行时），gdb 会自动显示这些表达式的当前值。这个命令对于在调试过程中持续监视某些变量的变化非常有用。

```bash
display <expression>
```

- <expression>：你希望自动显示的变量或表达式。可以是简单的变量、数组、指针，甚至复杂的表达式。

停止显示：
如果你不再希望自动显示某个表达式或变量，可以使用 undisplay 命令来停止显示，格式如下：

```bash
(gdb) undisplay <display-number>
```

查看当前正在显示的表达式：
你可以使用 info display 查看所有当前设置的自动显示表达式：

```bash
(gdb) info display
```

以字节（byte）格式显示变量 p 的值

```bash
display /b <expression>
```

- /b：字节（byte）格式。
- /h：半字（halfword）格式（2 字节）。
- /w：字（word）格式（4 字节）。
- /g：双字（giant word）格式（8 字节）。
- /x：十六进制格式。
- /d：十进制格式。
- /u：无符号十进制格式。
- /o：八进制格式。
- /t：二进制格式。
- /f：浮点格式。

搜索包含某个关键词的命令或帮助主题

```bash
apropos <keyword>
apropos tui
```

![program_stack](./pic/program_stack.png)

显示程序的调用栈

```bash
backtrace
bt
```

显示当前函数的参数及其值

```bash
info args
```

显示当前函数中所有局部变量及其值

```bash
info locals
```

显示与当前**栈帧（frame）**相关的信息

```bash
info frame
```

显示内容：
info frame 命令会显示当前栈帧的以下信息：

- 栈帧地址：当前栈帧在内存中的地址。
- 程序计数器：当前执行的指令地址。
- 栈指针（SP）：指向当前栈顶的指针。
- 帧指针（FP）：指向当前栈帧的指针。
- 返回地址：从当前函数返回时程序继续执行的位置。
- 参数地址：当前函数的参数在内存中的位置。
- 局部变量地址：当前函数局部变量的地址。

向下移动栈帧

```bash
down
```

向上移动栈帧

```bash
up
```

段错误（Segmentation fault）发生在程序试图访问它没有权限使用的内存区域

内存泄露:程序运行时内存回收失败

Stack Overflow

使用 Clang 编译器编译程序并启用 LeakSanitizer 来检测内存泄漏问题的命令。

```bash
clang -g leak.c -fsanitize=leak
```

Delta Debugging（增量调试）是一种自动化调试技术，用于缩小导致错误的输入或代码的范围。其目的是在程序发生错误时，通过不断地减少测试用例的大小或修改程序代码，来找到引发错误的最小输入或最小代码改动。

constexpr

constexpr 是 C++11 引入的一个关键字，用于指示表达式或函数的结果在编译时就可以计算出来。它是 C++ 中用于编译期常量的工具，目的是提高代码效率，减少运行时开销。

```c++
constexpr int size = 10;
constexpr int area = size * size;
```

assert（运行时断言）：
assert 是一个运行时检查，用于在程序执行过程中验证某个条件是否为真。如果条件为假，程序会立即终止并输出错误信息，帮助开发者在调试时发现逻辑错误。

头文件：assert 定义在 <cassert> 头文件中。

static_assert（编译时断言）：
static_assert 是一个编译时检查，用于在编译期间验证某个条件是否成立。如果条件为假，编译器会报错。它主要用于在编译期捕捉错误，适用于模板元编程和常量表达式。
头文件：不需要额外的头文件，static_assert 是 C++11 引入的内置语言特性。

调用函数或执行表达式

```bash
call <expression>
```

<expression>：可以是一个函数调用或表达式，也可以带参数。

将调试器附加到正在运行的程序

用于查找与名称包含 "prog" 的进程相关信息

```bash
ps aux | grep prog
```

使用 gdb -p 附加到进程

```bash
sudo gdb -p 12345
```

从正在调试的进程中分离

```bash
detach
```

用于从正在调试的进程中分离，使得程序继续运行，而不再由 gdb 控制。detach 命令的主要作用是停止对目标进程的调试，而不会终止或影响它的运行状态。

Core dump（核心转储） 是操作系统在程序崩溃时生成的一个文件，保存了程序在崩溃时的内存状态。它通常包含程序的内存内容、CPU 寄存器的值、进程状态等信息，用于帮助开发者分析和调试导致程序崩溃的问题。

命令 nl xxx.c 用于显示文件 xxx.c 的内容，并在每一行的开头添加行号。nl 是 number lines 的缩写，它的作用是给文件的每一行内容加上行号，方便阅读和调试代码。

```bash
nl [选项] 文件名
```

显示当前 shell 会话中所有可用的系统资源限制

```bash
ulimit -a
```

允许生成 core dump 文件

```bash
sudo ulimit -c unlimited
```

查看core dump 文件限制

```bash
ulimit -c
```

systemd-coredump

systemd-coredump 是 systemd 中的一个服务，负责**处理和管理进程崩溃时生成的核心转储（core dump）**文件。systemd-coredump 通过拦截程序崩溃时产生的核心转储，将其存储在指定的地方，并可以使用 coredumpctl 工具查看和分析这些核心转储文件。

安装

```bash
sudo apt-get install systemd-coredump
```

查看存储的核心转储： 你可以使用 coredumpctl 工具列出系统中存储的所有核心转储文件。它会显示哪些程序崩溃了，崩溃的时间和相关信息。

```bash
coredumpctl
```

导出核心转储文件： 你可以将核心转储文件导出到文件系统，以便在其他地方分析

```bash
coredumpctl dump
coredumpctl dump > core.dump
```

直接在 gdb 中加载和分析核心转储文件

启动 gdb 调试最近的核心转储： 如果你想直接调试系统中最近的核心转储，可以使用以下命令：

```bash
coredumpctl gdb
```

coredumpctl 会找到最近发生的崩溃，启动 gdb 并加载与该崩溃相关的核心转储文件和可执行文件。然后你可以在 gdb 中调试这个崩溃的程序。

生成一个正在运行进程的核心转储文件（core dump）

gcore 是 gdb (GNU 调试器) 提供的一个命令，用于生成一个正在运行进程的核心转储文件（core dump）。它允许你在不让进程崩溃的情况下，捕获当前进程的内存状态，用于后续分析和调试。

```bash
sudo gcore <pid>
```

加载和调试核心转储（core dump）文件的命令

```bash
gdb <executable> -c <core_file>
```

示例：
假设你有一个名为 myapp 的程序，并且在运行时发生了崩溃，系统生成了一个核心转储文件 core.8822。你可以使用以下命令在 gdb 中调试这个核心转储文件：

```bash
gdb myapp -c core.8822
```

若没有源码可以

```bash
(gdb) file ./prog
```

检查内存的内容
在 gdb 中，x 命令用于检查内存的内容。你可以通过 x 来查看特定内存地址的值、变量的地址、数组内容等，帮助你调试程序的内存状态。这个命令的格式和选项非常灵活，可以根据需要指定查看的内容格式、大小、地址等。

```bash
x &mike
x/[n][f][u] <address>
```

- n：要显示的单元格数（可选）。默认值是 1。
- f：显示内容的格式（可选），可以是字符、十进制、十六进制等。
- u：每个单元格的大小（可选），比如字节、字、双字等。
- <address>：要查看的内存地址，通常是一个指针变量的地址或表达式。

常用的显示格式选项（f）：

- x：以十六进制显示。
- d：以有符号十进制显示。
- u：以无符号十进制显示。
- t：以二进制显示。
- f：以浮点数显示。
- s：以字符串形式显示。
- i：以汇编指令显示（用于查看代码）。
- c：表示以字符（character）格式显示内存中的内容。

常用的单元格大小选项（u）：

- b：字节（byte, 1 字节）。
- h：半字（halfword, 2 字节）。
- w：字（word, 4 字节）。
- g：双字（giant word, 8 字节）。

```bash
(gdb) print sizeof(mike)
$3 = 8
(gdb) x/8bb &mike
(gdb) x/1bb &mike.grade
(gdb) x/1cb &mike.grade
```

commands 命令用于为断点指定一系列命令，这些命令会在程序运行到该断点时自动执行。通过 commands，你可以指定在程序到达某个断点时 gdb 应该执行的调试操作，常用于自动化调试工作流程。

```bash
(gdb) commands
>print size
>bt
>end
```

查看 写好的commands

```bash
info breakpoints
```

定义用户自定义的调试命令。

在 gdb 中，define 命令用于定义用户自定义的调试命令。你可以通过 define 创建一个自定义命令，该命令可以包含一系列 gdb 调试器中的操作。当你在调试过程中需要反复执行某些操作时，使用 define 可以方便地将这些操作打包成一个命令，从而提高效率。

示例：
创建一个简单的自定义命令：
假设你想定义一个命令 myprint，它可以打印几个常用的变量 var1 和 var2。你可以使用以下命令：

```bash
(gdb) define myprint
> print var1
> print var2
> end
```

之后，每当你想打印 var1 和 var2，只需输入 myprint：

```bash
(gdb) myprint
$1 = 10
$2 = 20
```

~/.gdbinit 是一个配置文件，用于在启动 gdb 时自动加载用户自定义的设置和命令。该文件位于用户的主目录中，每次你运行 gdb 时，它会自动读取和执行其中的内容。这使得你可以在调试会话中预定义一些有用的命令、别名、调试环境等。

作用：
自动化配置：将一些常用的 gdb 设置和调试命令放在 ~/.gdbinit 中，免去每次手动输入命令的麻烦。
自定义调试环境：通过这个文件，你可以定义别名、自定义命令、设置断点等，为你的调试会话自动配置环境。
提高效率：你可以在文件中提前定义常用的断点、打印命令、变量观察等，提高调试效率。

在 gdb 会话中执行系统的 shell 命令

```bash
shell <command>
```

<command>：你想要在系统 shell 中运行的命令。例如，可以是 ls、pwd、cat 等任何常见的 shell 命令。

打开当前正在调试的源代码文件

在 gdb 中，edit 命令用于在一个文本编辑器中打开当前正在调试的源代码文件。这样你可以在调试时直接修改代码，而不必离开 gdb。gdb 会调用你系统默认的编辑器（如 vim、nano 或 emacs）来打开源文件。

可以在gdb中使用python

```python
python import gdb
python gdb.execute("start")
python gdb.execute("next 3")
```

或者新建xxx.py文件，在gdb中执行 source xxx.py

以静默模式启动 gdb

gdb --quiet 命令用于以静默模式启动 gdb，即在启动时不显示通常的欢迎信息和版本号等内容。这个选项非常适合需要干净调试环境的情况，尤其是在编写脚本或希望减少启动时输出的情况下。

修改程序中的变量

```bash
(gdb) set count = 42
(gdb) set var value = 42
```

Reverse debugging（反向调试）是指在调试程序时，允许你回溯程序的执行过程，查看和分析程序执行历史中的状态、变量值和指令。与传统的调试方式不同，反向调试允许你在程序从某个断点或错误位置倒回执行，帮助查找程序崩溃或逻辑错误的原因。

启用完整指令级别的执行记录的命令

在 gdb 中，target record-full 是用于启用完整指令级别的执行记录的命令。它可以记录程序的每一条指令的执行状态，包括所有寄存器和内存操作。这种记录方式为反向调试（reverse debugging） 提供支持，允许调试者在调试过程中回溯程序的执行历史，逐步找到错误的根源。

```bash
target record-full
next
reverse-next
```

查看线程信息

```bash
info threads
```

切换线程

```bash
thread 3
bt
finish
```

在调试多线程程序时锁定调试器的调度，使得在调试时只允许一个线程执行，而其他线程暂停。

```bash
set scheduler-locking [off|on|step]
```

set scheduler-locking on 是 gdb 中的一个设置，用于在调试多线程程序时锁定调试器的调度，使得在调试时只允许一个线程执行，而其他线程暂停。这对于调试多线程程序中的并发问题非常有用，因为它可以确保你专注于某个线程的执行，而不会受到其他线程的干扰。

- off：默认设置，所有线程都会运行，gdb 不会锁定线程调度。
- on：只有当前线程会运行，其他线程将暂停，直到调试器切换到另一个线程。
- step：当你单步执行（使用 step 或 next 等命令）时，只有当前线程会执行；在继续执行（使用 continue）时，所有线程都会运行。

显示所有线程的调用栈

```bash
thread apply all bt
```

fork 是 Unix 和 Linux 系统中用来创建新进程的系统调用。它通过复制调用它的当前进程（父进程），生成一个新的进程（子进程），并将几乎所有父进程的状态和资源（如代码、文件描述符等）复制到子进程中。fork 调用后，父进程和子进程会分别拥有不同的进程 ID，但它们的执行内容和资源几乎完全相同，直到执行其他不同操作或调用exec来加载新程序。

checkpoint（检查点）是用于在程序执行的某个特定时间点保存程序状态的功能。这一状态包括内存、寄存器、程序计数器等，以便之后可以恢复到这一状态，继续从保存的位置执行。这对于长时间运行的程序或复杂的调试过程非常有用，因为它允许开发者回到之前的状态，而不必从头开始执行程序。

检查点的作用
回到特定执行点：通过设置检查点，程序可以在调试过程中快速恢复到之前的某一状态，特别适合用于排查复杂的逻辑错误或调试不易重现的错误。

1. 创建检查点并恢复： 假设你在程序的不同执行点设置检查点，以便随时回到某一状态。

```bash
(gdb) checkpoint
Checkpoint 1 at 0x400544: file example.c, line 20.
```

2. 查看并恢复检查点： 运行 info checkpoints 查看已创建的检查点：

```bash
(gdb) info checkpoints
Num     Address       Line    Function
1       0x400544      20      main
```

3. 通过 restart 命令恢复到检查点 1：

```bash
(gdb) restart 1
```

程序将恢复到检查点 1 的状态，并从那个位置继续调试

DDD（Data Display Debugger）是一个基于图形用户界面的调试工具，它为多种调试器（如 gdb、dbx 和 xdb）提供了可视化界面。DDD 可以用于调试 C、C++、Fortran 等多种语言编写的程序，并且能够通过图形化方式直观地展示变量、数据结构、调用栈等信息，简化调试过程。

安装

```bash
sudo apt-get install ddd
```

启动

```bash
ddd ./my_program
```

strace 是 Linux 上一个非常强大的调试工具，它用于跟踪和记录一个正在运行的进程或启动的新进程所执行的系统调用及其返回值。strace 是系统管理员和开发人员在调试、分析程序行为和排查问题时常用的工具之一，特别是当程序表现异常（如崩溃、挂起或权限错误）时。

ltrace 是一个 Linux 下的调试工具，用于跟踪程序中使用的库函数调用，类似于 strace，但重点不同。strace 跟踪系统调用（如 open, read, write 等），而 ltrace 跟踪的是用户空间的动态库调用，如 printf, malloc, free 等函数。

cppcheck 是一个静态代码分析工具，用于检查 C 和 C++ 代码中的潜在错误、性能问题、安全漏洞、代码风格等问题。它不会编译代码，而是通过分析源代码的语法和逻辑结构来识别代码中的问题，适用于跨平台的 C/C++ 项目。

查看 C++ 程序中某个对象的虚函数表（vtable）信息

```bash
(gdb) info vtbl base_ptr
```
