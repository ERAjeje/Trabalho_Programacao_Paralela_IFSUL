// TrabalhoProgParalela.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#ifndef _OPENMP
#include <omp.h>
#endif // !_OPENMP

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef PRODUTOR
#include "produtor.h"
#endif // !PRODUTOR

#ifndef CONSUMIDOR
#include "consumidor.h"
#endif // !CONSUMIDOR


int main()
{
	using namespace std;

	FILE* fp;
	char arq[TAM*2];
	printf("Digite o caminho completo e o nome do arquivo onde deseja procurar a palavra (coloque a extensao do arquivo):\n");
	gets_s(arq);
	fopen_s(&fp, arq, "r");
	char str[TAM];
	int result = 0;
	printf("Digite a palavra a ser pesquisada: ");
	char word[TAM];
	gets_s(word);

	//definição da fila com 50 elementos do tipo char[50]
	char list[TAM][40];

	//definição das variáveis de controle
	int position = 0;
	int read = 0;
	bool mutex_produtor = true;
	bool mutex_consumidor = false;

	/*
	* Realiza o tratamento para as vogais acentuadas e para o ç
	*/
	std::string search = converteTabelaAscii(word);
	
	int numThreads = omp_get_max_threads();


#pragma omp parallel num_threads(numThreads)
	while (fscanf_s(fp, "%s", str, _countof(str)) != EOF)
	{
		//chama a função product da biblioteca produtor
		product(list, str, position, mutex_produtor, mutex_consumidor);
		//chama a função consume da biblioteca consumidor
		consume(list, read, &result, search, mutex_consumidor, mutex_produtor);
	}

	fclose(fp);
	std::cout << std::endl;
	std::cout << result << std::endl;
}

