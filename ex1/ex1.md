
# Exercise 1: 
## Dust Off That Compiler


```C
int main(int argc, char *argv[])
{

    puts("Hello world.");

    return 0;

}
```

saved as ex1.c and run following in terminal
> $ make ex1, 

get warning.
> ex1.c:2:1: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]

the ex1.c is compiled
> $ ./ex1

output
> Hello world.

adding `#include <stdio.h>` to the top of the qoute eliminates the warning.

## Extra Credit
- Print out 5 more lines of text or something more complex than hello world.
```C
int main(int argc, char *argv[])
{

    puts("Hello world.");
    puts("I'm learning C");
    
    return 0;
}
```
- Run `man 3 puts` and read about this function and many others.
- 
>The function puts(const char *s) writes the string s, and a terminating newline character, to the stream stdout, it returns a nonnegative integer on success and EOF on error.

from https://github.com/Frederick-S/Learn-C-The-Hard-Way-Exercise/tree/master/Ex1
