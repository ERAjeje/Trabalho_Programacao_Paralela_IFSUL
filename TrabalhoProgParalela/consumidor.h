#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef OPENMP
#include <omp.h>
#endif // !OPENMP



using namespace std;

void consume(char list[TAM][TAM], int &read, int *result, string searched, bool &mutex_consumidor, bool &mutex_produtor);

void consume(char list[TAM][TAM], int& read, int *result, string searched, bool& mutex_consumidor, bool& mutex_produtor) {
	int numThreads = omp_get_num_threads();
#pragma omp parallel num_threads(numThreads)
	{
#pragma omp critical
		if (mutex_consumidor == 1 && mutex_produtor == 0) {
			countWordInLine(normalizeWord(list[read]), result, searched);
			read = ++read % TAM;
			mutex_consumidor = false;
			mutex_produtor = true;
		}
	}
	
}