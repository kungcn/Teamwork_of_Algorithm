# README
## The organiaztion of folder

--> hw
----> makefile
----> README.md
----> src
------> Mnist.ds **should put here otherwise the command to run it should change**
------> main.cpp
------> def.h (define constant and variable type)
------> header.h (declaration of header files)
------> close_pair_pivot.h (close_pair_pivot class)
------> close_pair_pivot.cpp
------> project.h (project class)
------> project.cpp
------> readFile.h (readFile class)
------> readFile.cpp

## How to run the project

1. open the terminal, input "make"
2. the running command `./cp -n 60000 -d 784 -f ./src/Mnist.ds`

The result will print on the terminal

## About result

The result will show about the closest pair, the Eulidean Distance and the cloest distance of the specific dimension.
However, we don't print the total picture for we forget it. Sorry..
