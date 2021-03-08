#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef QUEUE
typedef struct {
	char element[TAM];
} elemento;
//definição da fila com 50 elementos do tipo char[50]
typedef struct {
	int tam;
	elemento element[TAM];
}list;
#include <iostream>
#endif // !QUEUE


using namespace std;

void product(list lista[TAM], string str, int* position, bool mutex_produtor);

void product(list lista[TAM], string str, int* position, bool mutex_produtor) {
	
}
