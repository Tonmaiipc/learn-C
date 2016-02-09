# EXCERCISE 3
## Formatted Printing

## External Research
http://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

> $ man printf gives the /x format control.

## How to Break Them

- Take the age variable out of the first printf call then recompile. You should get a couple of warnings.

> warning: format `%d` expects a matching 'int' argument [-Wformat=]
printf("I am %d years old.\n");

- Run this new program and it will either crash, or print out a really crazy age.

> I am -1076009436 years old.

- Put the printf back the way it was, and then don't set age to an initial value by changing that line to int age; then rebuild and run again.

> warning: 'age' is used uninitialized in this function [-Winitialized]
printf("I am %d years old.\n", age);

## Extra Credit

- Find as many other ways to break ex3.c as you can

> Too many arguments when amount of % in string < arguments given.

- Run man 3 printf and read about the other '%' format characters you can use. These should look familiar if you used them in other languages (printf is where they come from).

> http://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

- add ex3 in `add` and `clean` in Makefile


## Self Research
- number in man 3 printf

http://stackoverflow.com/questions/62936/what-does-the-number-in-parentheses-shown-after-unix-command-names-mean

- if no argument declared?

fail
> error: `age` undeclared (first use in this function)
printf("I am %d tears old.\n, age);

