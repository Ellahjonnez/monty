# Project Title: 0x19. C - Stacks, Queues - LIFO, FIFO
**About:** Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### About the Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Learning Objectives:
To be able to explain to anyone, *without the help of Google* the following:
**General:**
* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

### Resource:
* [How do I use extern to share variables between source files in C?](https://intranet.alxswe.com/rltoken/0KVWTdE8xXy__jUfBfakCw)
* [Stacks and Queues in C](https://intranet.alxswe.com/rltoken/udmomL4F4mF630D2Z-ltqg)
* [Stack operations](https://intranet.alxswe.com/projects/249#quiz-completed:~:text=Queues%20in%20C-,Stack%20operations,-Queue%20operations)
* [Queue operations](https://intranet.alxswe.com/rltoken/6Y_GVoIH_rV45xd7w0a9FA)

## Requirements
* Allowed editors: **vi**, **vim**, **emacs**
* All your files will be compiled on **Ubuntu 20.04 LTS using gcc**, using the options *-Wall -Werror -Wextra -pedantic -std=c89*
* All your files should end with a **new line**
* A **README.md** file, at the root of the folder of the project is mandatory
* Your code should use the **Betty style**. It will be checked using *betty-style.pl* and *betty-doc.pl*
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the **C standard library**
* The prototypes of all your functions should be included in your header file called **monty.h**
* Don’t forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

## Instruction:
* *We are allowed to use the following data structures for this project, and to also include them in the header file.*
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

## Compilation & Output
* The codes were compiled using: ```gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
* Any output must be printed on ```stdout```
* Any error message must be printed on ```stderr```

## Author
[Innocent Ellah](https://github.com/Ellahjonnez)

