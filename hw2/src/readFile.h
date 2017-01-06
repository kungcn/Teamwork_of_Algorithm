#ifndef READFILE_H
#define READFILE_H

#include "header.h"
#include "def.h"

using namespace std;

float** createArray(int rows, int cols);
void freeArray(float** Array, int rows);
int reverseInt(unsigned char* Array, int Length);
void readFromMinst(char* MNIST, float** set, int number);

#endif
