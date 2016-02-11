# Exercise 6
## Types of Variables

int = integer > declare substitution on string with %d or %i
float = floating-point number > %f
double = large floating-point number > %f
char variable = 'X' , char = single letter > %c
char variable[] = 'string' , char = array of letters > %s

## Extra credit

- Go search for "printf formats" and try using a few of the more exotic ones.

```C
#include <stdio.h>
int main(int argc, char *argv[])
{
  printf("%.2f is 2 decimal points of -56789.4532.\n", -56789.4532);
  printf("%o, is signed octal integer of 10.\n", 10);
  printf("%x, is unsigned hexadecimal integer of 10.\n", 10)
  
  return 0;
}
```

> -56789.45 is 2 decimal points of -56789.4532
12 is signed octal integer of -10.
a is unsigned hexadecimal integer of 10.
  
- Research how many different ways you can write a number. Try octal, hexadecimal, and others you can find.

- Try printing an empty string that's just "".

> warning: zero-length gnu_printf format string [-Wformat-zero-length]

## Self Experiment

replace %u instead of %f for -5432.6789 gives warning.

> warning: format '%u' expects arguments of type 'unsigned int', but argument 2 has type 'double' [-Wformat=]

```C
  printf"this number, %.2f, has 2 decimal points.\n", -56789.4532"
```

> this number, -56789.45, has 2 decimal points
