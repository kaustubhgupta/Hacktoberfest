section    .text
   global _start   ;must be declared for linker (ld)
    
_start:              ;tells linker entry point
   mov    rdx,len   ;message length
   mov    rsi,msg   ;message to write
   mov    rdi,1     ;file descriptor (stdout)
   mov    rax,1     ;system call number (sys_write)
   syscall          ;call kernel
    
   mov	  rdi,0
   mov    rax,60     ;system call number (sys_exit)
   syscall          ;call kernel

section    .data
msg db 'Hello, world!', 0xa  ;string to be printed
len equ $ - msg     ;length of the string
