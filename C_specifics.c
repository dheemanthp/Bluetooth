
Const in C : https://www.geeksforgeeks.org/const-qualifier-in-c/
Pointer to constant Integer : const int *ptr;
Constant pointer to Integer :  int * const ptr;
Constant pointer to Constant Integer : const int * const ptr;


The memory region is divided into below regions
https://www.geeksforgeeks.org/memory-layout-of-c-program/

1)text or code segment
there are executable instructions here
2)data segment
a) initialized data segment
  ->read/write only are static variables , global variables
  ->read only are const variables
b) uninitialized data segment [BSS - block started by symbol is named after an Assembly instruction]
by default initialized to zero. by the kernel to arithmetic 0 before the program starts executing
 contains all global variables and static variables that are initialized to zero 
 or do not have explicit initialization in source code.
For instance a variable declared static int i; would be contained in the BSS segment.
For instance a global variable declared int j; would be contained in the BSS segment.   


3)STACK
Each time a function is called, the address of where to return to and certain information about the caller’s environment,
such as some of the machine registers, are saved on the stack. The newly called function then allocates room on the stack for
its automatic and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself,
a new stack frame is used, so one set of variables doesn’t interfere with the variables from another instance of the function.
4)HEAP
Heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size 
