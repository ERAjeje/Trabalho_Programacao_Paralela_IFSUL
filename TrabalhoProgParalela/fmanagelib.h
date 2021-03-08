#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <regex>

#define TAM 50

void countWordInLine(std::string str, int* r, std::string search);
std::string normalizeWord(std::string str);
std::string converteTabelaAscii(std::string str);

void countWordInLine(std::string str, int *r, std::string search) {
	std::regex b(search);
	bool aux = std::regex_match(str, b);
	if (aux) {
		*r += 1;
	}
}

std::string normalizeWord(std::string str) {
	std::string aux;

	std::wstring Utf8ToUtf16(const std::string & str);

	/*
	* regex para substituição dos acentos e caracteres especiais
	*/
	std::regex a("[aAáÁâÂàÀäÄãÃ]");
	std::regex e("[eEéÉêÊèÈëË]");
	std::regex i("[iIíÍîÎìÌïÏ]");
	std::regex o("[oOóÓôÔòÒöÖõÕ]");
	std::regex u("[uUúÚûÛùÙüÜ]");
	std::regex c("[cCçÇ]");
	std::regex space("[,.;:?!\+\*\-\=\<\>\(\)\&\%\$\#\@]");

	/*
	* função regex de subistituição
	*/
	aux = std::regex_replace(str, c, "c$2");
	aux = std::regex_replace(aux, a, "a$2");
	aux = std::regex_replace(aux, e, "e$2");
	aux = std::regex_replace(aux, i, "i$2");
	aux = std::regex_replace(aux, o, "o$2");
	aux = std::regex_replace(aux, u, "u$2");
	aux = std::regex_replace(aux, space, "$2");
	//std::cout << aux << std::endl;
	return aux;
}

std::string converteTabelaAscii(std::string str) {
	int tam = strlen(str.c_str());
	char aux[TAM];
	/*
	* Usa o laço for para percorrer a palavra recebida por input e, utilizando a tabela ASCII, faz manualmente os ratamentos para
	* vogais acentuadas e o ç
	*/
	for ( int i=0; i < tam; i++ )
	{
		int l = str[i];
			//
		if (l < 0) {
			l -= 4294967040;
			if (l == 135 || l == 128) {
				aux[i] = 'c';
				aux[i + 1] = '\0';
			}
			else if (l == 142 || l == 143 || l == 160 || (l >= 181 && l <= 183) || (l >= 131 && l <= 134) || l == 198 || l == 199) {
				aux[i] = 'a';
				aux[i + 1] = '\0';
			}
			else if (l == 130 || l == 144 || (l >= 136 && l <= 138) || (l >= 210 && l <= 212)) {
				aux[i] = 'e';
				aux[i + 1] = '\0';
			}
			else if ((l >= 139 && l <= 141) || (l >= 214 && l <= 216) || l == 161) {
				aux[i] = 'i';
				aux[i + 1] = '\0';
			}
			else if (l == 153 || l == 162 || l == 208 || l == 224 || (l >= 147 && l <= 149) || (l >= 226 && l <= 229)) {
				aux[i] = 'o';
				aux[i + 1] = '\0';
			}
			else if ((l >= 233 && l <= 236) || l == 129 || l == 150 || l == 151 || l == 154 || l == 161 || l == 163) {
				aux[i] = 'u';
				aux[i + 1] = '\0';
			}
			else {
				aux[i] = l;
				aux[i + 1] = '\0';
			}
		}
		else {
			if (l >= 65 && l <= 90) {
				l += 32;
				aux[i] = l;
				aux[i + 1] = '\0';
			}
			else {
				aux[i] = l;
				aux[i + 1] = '\0';
			}
			
		}
	}
	return aux;
}
