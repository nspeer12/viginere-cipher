# viginere-cipher
A simple viginere cipher program in C language.
Run this program on the command line.
The firt arguement should be a a key file, the second is the message you want to encrypt.
Note that this program only uses alphabetical characters, and discards any symbols and spaces. It also converts uppercase characters to lower case.

here's a quick example of how to compile and run this on a linux terminal.
step 1: gcc viginere.c -o viginere.exe
step 2: ./viginere.exe key.txt plain.txt

the program will then echo the key, plain text, and cipher text
