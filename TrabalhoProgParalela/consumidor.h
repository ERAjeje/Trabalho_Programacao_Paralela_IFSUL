#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef OPENMP
#include <omp.h>
#endif // !OPENMP



using namespace std;

void consume(char list[TAM][40], int &read, int *result, string searched, bool &mutex_consumidor, bool &mutex_produtor);

void consume(char list[TAM][40], int& read, int *result, string searched, bool& mutex_consumidor, bool& mutex_produtor) {
	//verifica o numero de threads
	int numThreads = omp_get_num_threads();

//inicia o bloco paralelo setando o numero de threads para o recebido pela diretiva omp_get_num_threads()
#pragma omp parallel num_threads(numThreads)
	{

		if (mutex_consumidor == 1 && mutex_produtor == 0) {
			/*
			* A função de contagem usa o resltado da função de normalização que recebe como
			* parâmetro a palavra lida do arquivo de texto e salva na fila pelo produtor
			*/
//utiliza a diretiva critical para definir um espaço de memória que deve ser executado por uma unica thread por vez
#pragma omp critical
			countWordInLine(normalizeWord(list[read]), result, searched);

			/*
			* Este bloco seta as variaveis de controle. A variável read indica o próximo ponto a realizar a leitura
			* Trava o mutex de consumidor e libera o mutex de produtor
			*/
			read = ++read % TAM;
			mutex_consumidor = false;
			mutex_produtor = true;
		}
	}
	
}