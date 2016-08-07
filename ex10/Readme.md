## Exercise10
#### Arrays Of Strings, Looping

Learn to use `for loop`

by using i as a counter in a `for loop` for(i = 0; i < argc; i++), i variable must be assigned first 
`int i = 0` or `for(int i = 0; i <argc; i++)`
this is ok too `for(int i =0, j =4; i < j; i++)`
or `for(int i = 4; i >2; i--)`

```C
for(INITIALIZER; TEST; INCREMENTER) {
    CODE;
}
```

#### How to Break It

- Initialize i to 0 and see what that does. Do you have to adjust argc as well or does it just work? Why does 0-based indexing work here?

It works, ./ex10 is the argv[0]

- Set num_states wrong so that it's a higher value and see what it does.

valgrind report error, and yield `segmentation fault` as it tries to access unavailable memory.

- Read what a NULL is and try to use it in one of the elements of the states array to see what it'll print.

an implementation-defined null pointer constant, which in C99 can be portably expressed as the integer value 0 converted implicitly or explicitly to the type void*

- See if you can assign an element from the states array to the argv array before printing both. Try the inverse.

assigning states array > argv array. Doable
assigning argv array > states array. error: array type 'char *[3]' is not assignable
