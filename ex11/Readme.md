## Exercise11
#### Arrays Of Strings, Looping

Learn to use `While-loop`

```C
while(i < argc) {
    CODE;
}
```

#### How to Break It

- Forget to initialize the first int i; so have it loop wrong.

make error: use of undeclared identifier 'i'.

- Forget to initialize the second loop's i so that it retains the value from the end of the first loop. Now your second loop might or might not run.

the counter i continues from first loop's i

- Forget to do a i++ increment at the end of the loop and you get a "forever loop", one of the dreaded problems of the first decade or two of programming.

it runs non-stop. Strangely ^C doesn't stop output from returning instantly.
Valgrind also doesn't report "error".

#### Extra Credit

- Make these loops count backward by using i-- to start at argc and count down to 0. You may have to do some math to make the array indexes work right.

```C
int i = argc - 1;
while(i >= 0) {
    printf("argc %d: %s", i, argv[i]);
    i--;
}
```

- Use a while loop to copy the values from argv into states. Make this copy loop never fail such that if there's too many argv elements it won't put them all into states.

```C
i = 0;
while(i < argc) {
  states[i] = argv[i];
  i++;
}
int num_states = argc;
```

- Research if you've really copied these strings. The answer may surprise and confuse you though.
