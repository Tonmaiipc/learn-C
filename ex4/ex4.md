# Exercise 4
## Introducing Valgrind

Installing valgrind
> $curl -O http://valgrind.org/downloads/valgrind-3.11.0.tar.bz

-O is a capital O (OH) telling curl to save file at current folder.
http://stackoverflow.com/questions/16362402/save-file-to-specific-folder-with-curl-command

> $md5sum valgrind-3.11.0.tar.bz2

to check

> $tar -xjvf valgrind-3.11.0.tar.bz2

this unpack the file

> $cd valgrind-3.11.0

> $./configure

to configure << research more

> $make

make the program according to its `Makefile`

> sudo make install

this install valgrind

## Using Valgrind

after a file compiled
>$ valgrind ./filename 

## Extra Credit

- read up on valgrind on the internet



- Download other software and build it by hand. Try something you already use but never built for yourself.

download winrar
> $curl -O http://www.rarlab.com/rar/rarlinux-x64-5.3.0.tar.gz

to decompressed .tar.gz use this command
> $tar -zxvf rarlinux-x64-5.3.0.tar.gz

install
> $sudo make install

