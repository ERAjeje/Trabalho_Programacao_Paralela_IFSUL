// TrabalhoProgParalela.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#ifndef _OPENMP
#include <omp.h>
#endif // !_OPENMP

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB


int main()
{
	using namespace std;

	FILE* fp, *aux;
	fopen_s(&fp, "file.txt", "r");
	fopen_s(&aux, "Texto.txt", "w+");
	char str[TAM];
	int result = 0;
	printf("Digite a palavra a ser pesquisada: ");
	char word[TAM];
	scanf_s("%s", word, (rsize_t)sizeof word);
	string refactorWord = normalizeWord(word);
	while (fscanf_s(fp, "%s", str, _countof(str)) != EOF)
	{
		countWordInLine(normalizeWord(str), &result, refactorWord);
	}
	fclose(fp);
	printf("%d", result);
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
