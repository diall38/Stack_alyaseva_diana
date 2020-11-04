#include <iostream>
#include "cmath"
#include "string"
#include "stack.h"

//Задача 1. Правильная скобочная последовательность в арифметическом выражении
inline bool isOpenBracket(char ch) {
	return ch == '(' || ch == '{' || ch == '[';
}

inline bool isClosingBracket(char ch) {
	return ch == ')' || ch == '}' || ch == ']';
}

int main(int argc, char** argv)
{
	for (size_t i = 1; i < argc; i++) {
		std::string a(argv[i]);
		Stack<char> st;
		std::cout << a << "\n";
		int f = 0;
		for (char x : a) {
			if (!isOpenBracket(x) && !isClosingBracket(x)) continue;
			if (isOpenBracket(x))
				st.push(x);                   //открывающие скобки добавляем в стек
			else
				if (!st.empty() && abs(x - st.top()) <= 2) //если стек не пуст, скобка закрывающая
					st.pop();                 //и по виду совпадает с открывающей на вершине стека
				else {
					std::cout << "invalid bracket sequence\n";
					f = 1;
					break;
				}
		}
		if (!f) {
			if (st.empty())
				std::cout << "correct bracket sequence\n";
			else
				std::cout << "invalid bracket sequence\n";
		}
	}
	return 0;
}
