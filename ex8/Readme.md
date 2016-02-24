##Exercise 8
####Sizes and Arrays

####Size Of An Variable

Defining a variable is important on allocating size.
character variable = 1 byte ( sizeof(char) )
integer variable = 4 bytes  ( sizeof(int) )
In spite of size, C handles char var & int var exactly the same.
The output however depends on `format string` (%x).
'''C
int var = 2;
printf("%c %d\n", var, var)
char var = 2;
printf("%c %d\n", var, var)
'''

for instance, %c tells printf to print var as a character according to ASCII.
%d tells printf to print var as an integer.

unlike python, `int var = 2`, `int var = '2'`, `char var = 2`, and `char var = '2'` are totally the same.

An important note is that, 
in spite of same handling, an integer output from char variable can handle only a 0-255 unsigned integer. (2^8)
while an integer output from int variable can handle a 0-4294967295 unsigned integer. (2^(8*4))

#### Size of An Array

To create an array, it has to be defined whether it's an int or a character as well.

A member of int array is given a size of 4 bytes.
```C
int var[] = {2,4,6,7,8};
printf("size of var[]: %d\n", sizeof(var) / sizeof(int));
```

A member of char array (string) is given a size of 1 byte.
```C
char var[] = {'H','e','l','l','o'};
// or char var[] = "Hello";
printf(size of var[] : %dn", sizeof(var) / sizeof(char));
```
#### Etra Cedits

- Go search online for the different sizes used for integers on different CPUs.

Despite difference between 32 bit/ 64 bit cpu, int is normally assigned for 32 bit, unless long type integer is assigned.
For 32 bit system, a long type integer handling 64 bit value, and takes up 2 memory addresses.
While 64 bit system can assign long integer to a single memory address.
