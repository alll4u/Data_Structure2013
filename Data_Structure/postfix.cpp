#include <iostream>
#include <string>
#include "LinkedStack.h"
using namespace std;
int priority(char ch){
	switch (ch){
	case '+':case'-':
		return 1;
	case '*':case'/':
		return 2;
	case '(':
		return 3;
	case '#':
		return 0;
	default:
		cout << "priority error" << endl;
		return -1;
	}
}
void run(){
	char ch,tmpOprnd;
	double operand;
	LinkedStack<char> ss;
	ss.Push('#');
	cout << "plz input the operand or operator" << endl;
	cin >> ch;

	while (cin>> ch, ch != '#'){
		cout << "plz input the operand or operator" << endl;
		//����ֱ�����
		if (isdigit(ch)){
			cin.putback(ch);
			cin >> operand;
			/*cout << "operand is " << operand << endl;
			cout << "char is " << ch << endl;*/
		}
		else if (ch == '('){
			ss.Push(ch);
		}
		else if (ch == ')'){
			ss.getTop(tmpOprnd);
			while (tmpOprnd != '('){
				cout << tmpOprnd << endl;
				ss.Pop(tmpOprnd);
			}
		}
		else {
			ss.getTop(tmpOprnd);
			if (priority(ch) > priority(tmpOprnd))
			{
				ss.Push(ch);
			}
			else{
				while (!ss.IsEmpty())
				{
					//�µ�Ԫ�����ȼ�������ջ��Ԫ�����ȼ�����������ӡ
					if (priority(ch) <= priority(tmpOprnd)){
						ss.Pop(tmpOprnd);
						cout << tmpOprnd << endl;
						ss.getTop(tmpOprnd);
					}
					else {
						ss.Push(ch);
						break;
					}
				}
			}
		}
	}
	ss.Pop(ch);
	while (ch != '#'){
		cout << "operator: " << ch << endl;
		ss.Pop(ch);
	}
}

//void main(){
//	run();
//	system("pause");
//}
