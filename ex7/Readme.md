# Exercise 7
## More Variables, Some Math

## How to Break It

> warning: format '%s' expects argument of type 'char *', but argument 2 has type 'int' [-Wformat=]
What means you should care (null)%.

valgrind reports 0 errors from 0 contexts.

## Extra Credit

- Make the number you assign to `universe_of_defects` various sizes until you get a warning from the compiler.

> maximum limit is around 4300000000L - 4290000000L (but it's printing out a negative large number)

- What do these really huge numbers actually print out?

> 0

- Change long to unsigned long and try to find the number that makes that one too big.

- Go search online to find out what unsigned does.

unsigned = the integer has only + not - sign, hence a bit can store larger integer instead of +,- of a smaller integer.

- Try to explain to yourself (before I do in the next exercise) why you can multiply a char and an int.

because in C, characters are actually represented by a number according to ACSII.
