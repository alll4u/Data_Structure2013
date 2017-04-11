#include <iostream>
#include <string>
#include <stdio.h>
#include "LinkedStack.h"
using namespace std;

void PrintMatchedPairs(string exp){
	LinkedStack<int> s;
	int length = exp.length();
	cout << "length is " << length << endl;
	int j;
	for (int i = 1; i <= length; i++){
		if (exp[i - 1] == '(')s.Push(i);
		else if (exp[i - 1] == ')')
		{
			if (s.Pop(j) == true)
				cout << i << " match " << j << endl;

			else
				cout << "no match with " << i << endl;
		}

	}
	while (s.Pop(j)){
		cout << "nomatch with " << j << endl;
	}

	//int j = 0;
	//for (int i = 1; i <= length; i++){
	//	if (exp[i - 1] == '(') s.Push(i);
	//	else if (exp[i - 1] == ')'){
	//		if (s.Pop(j) == true)
	//			cout << j << " and " << i << " match " << endl;
	//		else cout << j << "no math with " << i << exp[i - 1] << endl;
	//	}
	//	else
	//		cout << exp[i - 1] << endl;
	//}
	//while (s.IsEmpty() == false){
	//	s.Pop(j);
	//	cout << "no match with " << j << exp[j - 1] << endl;
	//}
}

//void main() {
//
//	PrintMatchedPairs("((((dd(123d)");
//
//
//	system("pause");
//
//}