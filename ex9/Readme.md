## Exercise 9
#### Arrays And Strings

To declare an array of strings of specific size
```C
int numbers[4] = {0};
char name[4] = {'a'};
```

int numbers[4] creates an int array of four 0s, with size of 16 bytes.
char name[4] create an array which include {'a', \0, \0, \0} in ascii or {97,0,0,0} , with size of 4 bytes.

#### How To Break It

- Get rid of the initializers that setup name.

`char name[4] = {};`
compilable and every members is asigned as 0. 0 error from valgrind.

`char name[4]`
compilable, every members is assigned with unrecognized numbers, errors from valgrind

- Accidentally set name[3] = 'A'; so that there's no terminator.

compilable, no warning, however string printing doesn't terminate with the end of string. (also print the previous string somehow)

- Set the initializer to {'a','a','a','a'} so there's too many 'a' characters and no space for the '\0' terminator.

 same result

#### Self Observation

when  assign more character into a char array with smaller size, no error, compilable, print correcty, 
However the sizeof is still small.

printing an array of numbers with %s results in a strange character.
printing an array of numbers with %d results in a strange number.

#### Extra Credits

- Assign the characters into numbers and then use printf to print them a character at a time. What kind of compiler warnings did you get?

Nothing, no warning since a character is actually a number interpreted in ascii.

- Do the inverse for name, trying to treat it like an array of int and print it out one int at a time. What does Valgrind think of that?

No error

- If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat the whole name array like it's just an integer? How might you accomplish this crazy hack?

https://github.com/Frederick-S/Learn-C-The-Hard-Way-Exercise/tree/master/Ex9

```C
char name[4] = { 'a', 'b', 'c', 'd' };
int number = (name[0] << 24) + (name[1] << 16) + (name[2] << 8) + name[3];
```

- Convert name to be in the style of another and see if the code keeps working.

Yes, however assign an integer to a member of `char *another = 'Zed'` results in `Segmentation fault (core dumped)`
Since this method assign variable as a read-only memory.

`"Segmentation fault" means that you tried to access memory that you do not have access to.`
http://stackoverflow.com/questions/19641597/what-is-segmentation-fault-core-dumped
