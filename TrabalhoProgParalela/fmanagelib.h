#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <regex>

#define TAM 50

void countWordInLine(std::string str, int *r, std::string word);
std::string normalizeWord(std::string str);

void countWordInLine(std::string str, int *r, std::string word) {
	if (strcmp(str.c_str(), word.c_str()) == 0)
		*r += 1;
}

std::string normalizeWord(std::string str) {
	std::string aux;

	/*
	* regex para substituição dos acentos
	*/
	std::regex a("[aAáÁâÂàÀäÄãÃ]");
	std::regex e("[eEéÉêÊèÈëË]");
	std::regex i("[iIíÍîÎìÌïÏ]");
	std::regex o("[oOóÓôÔòÒöÖõÕ]");
	std::regex u("[uUúÚûÛùÙüÜ]");
	std::regex c("[cCçÇ]");
	std::regex upper("[A-Z]", std::regex::ECMAScript);
	std::regex space("[,.;:?!]");

	/*
	* função regex de subistituição
	*/
	aux = std::regex_replace(str, c, "c$2");
	aux = std::regex_replace(aux, upper, "[a-z]");
	aux = std::regex_replace(aux, a, "a$2");
	aux = std::regex_replace(aux, e, "e$2");
	aux = std::regex_replace(aux, i, "i$2");
	aux = std::regex_replace(aux, o, "o$2");
	aux = std::regex_replace(aux, u, "u$2");
	aux = std::regex_replace(aux, space, "$2");
	std::cout << aux << std::endl;
	return aux;
}
