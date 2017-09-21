
A simple shell written in C.

FEATURES SUPPORTED
-------------------------------------------------------
The shell supports cd,pwd,echo,ls,exit and other built in commands.
Errors are handled properly.


HOW TO COMPILE
-------------------------------------------------------
to compile run the command:-  make

HOW TO RUN
-------------------------------------------------------
run the command:- ./main

FILES
-------------------------------------------------------
main.c:- the main function along with builting commands like cd,echo and pwd
ls.c:- the function to execute ls command
readline.c:- the function to parse the given string of commands properly
splitline.c:- to split and tokenise the content of the string parsed
execute.c:- the function to execute other commands in background or foreground

