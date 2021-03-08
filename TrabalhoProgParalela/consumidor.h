#pragma once

#ifndef _FMANAGELIB
#include "fmanagelib.h"
#endif // !_FMANAGELIB

#ifndef STACK
#include <queue>
#include <iostream>
#endif // !STACK


using namespace std;

void consume(queue<string> list, int result, string searched);

void consume(queue<string> list, int result, string searched) {
	string source;
	if (!list.empty()) {
		source = list.front();
		list.pop();
		countWordInLine(normalizeWord(source), &result, searched);
	}
}