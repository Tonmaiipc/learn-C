
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

> Hello world.

adding '#include <stdio.h>' to the top of the qoute eliminates the warning.

