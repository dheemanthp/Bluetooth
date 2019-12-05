Function pointer:
https://aticleworld.com/function-pointer-in-c/
https://www.geeksforgeeks.org/callbacks-in-c/
https://stackoverflow.com/questions/2738463/implementing-callback-functions-in-c

#include<stdio.h>

typedef void (*callback_t) (int);//declaration 
callback_t callback;

//definition
void callback_proc(int a)
{
    printf ("Inside callback function %d \n", a);
}

//registers for a callback
void reg( callback_t _callback , int a)
{
    printf ("Inside registration \n");
    
    _callback(a);
}

int main ()
{
    callback = callback_proc;//assign the address of the function
    reg(callback, 4);//register the callback

    return 0;
}

=========================================================================
Structure padding , and pragma packing , and attribute packed
https://www.geeksforgeeks.org/how-to-avoid-structure-padding-in-c/
=========================================================================
Both pragma packing #pragma pack(1), and __attribute__((packed)) will result in size 13
without them , it will be size 16.(that char will take up 4 bytes).
#pragma pack(1) 
struct s { 
    int i; 
    char ch; 
    double d; 
}; 
struct s { 
    int i; 
    char ch; 
    double d; 
} __attribute__((packed));  
=========================================================================
  

=========================================================================
Volatile in C:https://barrgroup.com/Embedded-Systems/How-To/C-Volatile-Keyword
=========================================================================
Thus all shared global objects (variables, memory buffers, hardware registers, etc.) 
must also be declared volatile to prevent compiler optimization from introducing unexpected behaviors.

  =========================================================================
Const in C : https://www.geeksforgeeks.org/const-qualifier-in-c/
=========================================================================
Pointer to constant Integer : const int *ptr;
Constant pointer to Integer :  int * const ptr;
Constant pointer to Constant Integer : const int * const ptr;


=========================================================================
The memory region is divided into below regions
https://www.geeksforgeeks.org/memory-layout-of-c-program/
=========================================================================
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
=========================================================================
brk() and sbrk() are different. 
https://stackoverflow.com/questions/19676688/how-malloc-and-sbrk-works-in-unix
=========================================================================

Syscalls are expensive to process because of the additional overhead that a syscall places:
you have to switch to kernel mode. A system call gets into the kernel by issuing a "trap" or interrupt.
  It's a call to the kernel for a service, and because it executes in the kernel address space, 
  it has a high overhead switch to kernel (and then switching back).

This is why malloc reduces the number of calls to sbrk() and brk(). It does so by requesting more memory 
than you asked it to, so that it doesn't have to issue a syscall everytime you need more memory.

brk() and sbrk() are different.

brk is used to set the end of the data segment to the value you specify. 
It says "set the end of my data segment to this address". Of course, the address you specify 
must be reasonable, the operating system must have enough memory, and you can't make it point
to somewhere that would otherwise exceed the process maximum data size. Thus, brk(0) is invalid, 
since you'd be trying to set the end of the data segment to address 0, which is nonsense.

On the other hand, sbrk increments the data segment size by the amount you specify, 
and returns a pointer to the previous break value. Calling sbrk with 0 is valid; it is a 
way to get a pointer to the current data segment break address.

malloc is not a system call, it's a C library function that manages memory using sbrk. 
According to the manpage, malloc(0) is valid, but not of much use:

If size is 0, then malloc() returns either NULL, or a unique pointer value that 
can later be successfully passed to free().

So, no, brk(0), sbrk(0) and malloc(0) are not equivalent: the first of them is invalid,
the second is used to obtain the address of the program's break, and the latter is useless.

Keep in mind that you should never use both malloc and brk or sbrk throughout your program. 
malloc assumes it's got full control of brk and sbrk, 
if you interchange calls to malloc and brk, very weird things can happen.
