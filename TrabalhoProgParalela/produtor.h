#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef OPENMP
#include <omp.h>
#endif // !OPENMP



using namespace std;

void product(char lista[TAM][40], string str, int &position, bool &mutex_produtor, bool &mutex_consumidor);

void product(char lista[TAM][40], string str, int &position, bool &mutex_produtor, bool &mutex_consumidor) {
	//verifica o numero de threads
	int numThreads = omp_get_num_threads();

//inicia o bloco paralelo setando o numero de threads para o recebido pela diretiva omp_get_num_threads()
#pragma omp parallel num_threads(numThreads)
{

	if (position < 50 && mutex_produtor == 1 && mutex_consumidor == 0) {
		//faz uma cópia da palavra lida dentro da fila
//utiliza a diretiva critical para definir um espaço de memória que deve ser executado por uma unica thread por vez
#pragma omp critical
		strcpy_s(lista[position], str.c_str());
		/*
		* Este bloco de códigos faz a alteração das variáveis de controle position (posição para inserir na fila)
		* e os mutex, fazendo com que eles recebam o seu oposto. 
		* 
		* por se tratar de uma fila circular, position sempre recebe o resultado do resto do seu incremento dividido
		* pela constante TAM. Neste trabalho foi definido TAM = 50
		*/
		position = ++position % TAM;
		mutex_consumidor = true;
		mutex_produtor = false;
	}
}
}
