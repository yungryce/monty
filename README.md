<p align="center">
  <img src="https://img.shields.io/badge/C-Language-blue" alt="C Language">
  <img src="https://img.shields.io/badge/Data_Structures-Stack_Queue-green" alt="Data Structures">
  <img src="https://img.shields.io/badge/Interpreter-Monty_0.98-orange" alt="Interpreter">
  <img src="https://img.shields.io/badge/Brainf*ck-Integration-red" alt="Brainf*ck">
  <img src="https://img.shields.io/badge/Status-Complete-brightgreen" alt="Status">
</p>

<div align="center">
  <h1>🖥️ Monty Interpreter</h1>
  <p><em>A complete stack and queue interpreter for Monty 0.98 bytecode with Brainf*ck integration</em></p>
</div>

---

## 📋 Table of Contents
- [📖 Overview](#-overview)
- [🎯 Learning Objectives](#-learning-objectives)
- [🛠️ Tech Stack](#️-tech-stack)
- [📁 Project Structure](#-project-structure)
- [🚀 Getting Started](#-getting-started)
- [💡 Usage](#-usage)
- [🏆 Key Features](#-key-features)
- [📚 Resources](#-resources)
- [👥 Contributors](#-contributors)

## 📖 Overview
The Monty Interpreter is a comprehensive implementation of a stack and queue-based programming language interpreter, designed as part of the ALX Software Engineering Program's low-level programming specialization. This project demonstrates advanced systems programming skills through the creation of a complete bytecode interpreter that supports both LIFO (stack) and FIFO (queue) operations with dynamic mode switching.

The interpreter processes Monty 0.98 bytecode files, executing a rich set of instructions including arithmetic operations, stack manipulation, I/O operations, and advanced features like Brainf*ck language integration. This project showcases expertise in language design, data structure implementation, memory management, and robust error handling in C programming.

## 🎯 Learning Objectives
- **Data Structure Mastery**: Implement and understand stack (LIFO) and queue (FIFO) operations
- **Interpreter Design**: Build a complete language interpreter from scratch
- **Memory Management**: Master dynamic memory allocation and cleanup in C
- **File Processing**: Handle command-line arguments and file I/O operations
- **Error Handling**: Implement comprehensive error detection and reporting
- **Language Integration**: Develop Brainf*ck language interpreter capabilities
- **Systems Programming**: Apply low-level programming concepts in practical applications
- **Code Organization**: Structure large C projects with modular design principles
- **Algorithm Implementation**: Translate theoretical concepts into working code
- **Professional Development**: Follow industry standards for code quality and documentation

**Read or watch**:

-   [Google](https://alx-intranet.hbtn.io/rltoken/tn1X658KGumYYq_szFJI5w "Google")
-   [How do I use extern to share variables between source files in C?](https://alx-intranet.hbtn.io/rltoken/0KVWTdE8xXy__jUfBfakCw "How do I use extern to share variables between source files in C?")

Learning Objectives
-------------------

At the end of this project, you are expected to be able to [explain to anyone](https://alx-intranet.hbtn.io/rltoken/_kxhiyVFey_mAGnzuHKL1w "explain to anyone"), **without the help of Google**:

### General

-   What do LIFO and FIFO mean
-   What is a stack, and when to use it
-   What is a queue, and when to use it
-   What are the common implementations of stacks and queues
-   What are the most common use cases of stacks and queues
-   What is the proper way to use global variables

Requirements
------------

### General

-   Allowed editors: `vi`, `vim`, `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c90
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project is mandatory
-   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   You allowed to use a maximum of one global variable
-   No more than 5 functions per file
-   You are allowed to use the C standard library
-   The prototypes of all your functions should be included in your header file called `monty.h`
-   Don't forget to push your header file
-   All your header files should be include guarded
-   You are expected to do the tasks in the order shown in the project

### GitHub

**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

More Info
---------

### Data structures

Please use the following data structures for this project. Don't forget to include them in your header file.

```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

```

```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

```

### Compilation & Output

-   Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

```

-   Any output must be printed on `stdout`
-   Any error message must be printed on `stderr`
    -   [Here is a link to a GitHub repository](https://alx-intranet.hbtn.io/rltoken/Cv-FVD5dZn3814FM4WkBPQ "Here is a link to a GitHub repository") that could help you making sure your errors are printed on `stderr`

### Tests

We strongly encourage you to work all together on a set of tests

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

---

*This project demonstrates comprehensive mastery of systems programming, data structures, language implementation, and professional software development practices essential for advanced software engineering roles.*
