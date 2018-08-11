1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

a. Ready -- When a process is ready to run but is not being executed yet by the Operating System.
b. Running -- When a process is being executed already.
c. Blocked -- When a process has been executed and halted by the OS for some reason or other.

2. What is a zombie process? How does one get created? How does one get destroyed?

A "zombie process" is also known as a "final state" wherein the process has already been executed (or has already exited) but has not yet been cleaned up. It is created when the child process is created, that is, upon forking or when the fork() system call is invoked. It is destroyed with the exit() system call.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

Compiled languages perform faster than non-compiled or interpreted languages. Non-compiled or interpreted langauges need to be "interpreted" or processed first before they are executed, so they're relatively slower. Also, the code used in compiled languages is native to the CPU.