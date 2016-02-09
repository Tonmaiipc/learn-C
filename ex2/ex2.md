# Excercise 2
## Make Is Your Python Now

```
CFLAGS=-Wall -g

clean:
  rm -f ex1 ex1.dSYM
```
saved as `Makefile

>$make clean

remove `ex1` and `ex1.dSYM` 
(.dSYM file store debugging symbol for apps, other service use it to replace symbols in crash log, making it readable)

```
CFLAGS=-Wall -g

clean:
  rm -f ex1 ex1.dSYM
```

## How to Break It

> Makefile:4: *** missing separator.  Stop.

## Extra Credit

- Create an all: ex1 target that will build ex1 with just the command make.
```
CFLAGS=-Wall -g

all: ex1

clean:
  rm -f ex1
```

>make 
>cc -Wall -g ex1.c -o ex1

by running 'make' in terminal, it searches for Makefile and run its first function. (all: in this case) 
However running `make clean` will tell system to run `clean` in `Makefile`

- Read man make to find out more information on how to run it.
`make` runs cc compiler on a target.

- Read man cc to find out more information on what the flags -Wall and -g do.
`cc` is C Compiler. -Wall enables all warnings -g Produce debugging information in the operating system's native format
read more here : [learn C Github](https://github.com/Frederick-S/Learn-C-The-Hard-Way-Exercise/tree/master/Ex2)

- Research Makefiles online and see if you can improve this one even more
> you can add comment using # at the start of the line
> able to use variables too
[learn C Github](https://github.com/Frederick-S/Learn-C-The-Hard-Way-Exercise/tree/master/Ex2)

CFLAGS and CXXFLAGS are either the name of environment variables or of Makefile variables that can be set to specify additional switches to be passed to a compiler in the process of building computer software.
