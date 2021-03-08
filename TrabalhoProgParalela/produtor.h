#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef OPENMP
#include <omp.h>
#endif // !OPENMP



using namespace std;

void product(char lista[TAM][TAM], string str, int &position, bool &mutex_produtor, bool &mutex_consumidor);

void product(char lista[TAM][TAM], string str, int &position, bool &mutex_produtor, bool &mutex_consumidor) {
	int numThreads = omp_get_num_threads();
#pragma omp parallel num_threads(numThreads)
{
#pragma omp critical
	if (position < 50 && mutex_produtor == 1 && mutex_consumidor == 0) {
		strcpy_s(lista[position], str.c_str());
		position = ++position % TAM;
		mutex_consumidor = true;
		mutex_produtor = false;
	}
}
}
