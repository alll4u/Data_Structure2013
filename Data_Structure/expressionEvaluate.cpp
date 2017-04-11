#include <iostream>
#include "LinkedStack.h"
#include <string>
using namespace std;

class Expression{
public:
	//������ʽ
	void inputExp();
	//����׺���ʽת��Ϊ��׺���ʽ
	void postfix();
	int isp(char ch);
	int icp(char ch);
	//��ӡ���ʽ
	void printExp(){ cout << "expression is " << expression; }
	//���ñ��ʽ
	void setExp(string str){ expression = str; }
	//���ر��ʽ
	string getExp(){ return expression; }
	//������ʽ��ֵ
	double calculate();
	double doOperator(char ch);
	void addOperand(double operand);
	bool getTwoOperand(double &a, double &b);
private:
	string expression;
	LinkedStack<double> s;

};


void main(){

	//LinkedStack<double> a;
	//double b;
	//a.Push(12);
	//a.Push(13);
	//a.Pop(b);
	//cout << "b is " << b << endl;
	//a.Pop(b);
	//cout << "b is " << b << endl;
	

	double result = 0;
	Expression exp;
	//exp.inputExp();
	//exp.postfix();
	
	result = exp.calculate();

	system("pause");
}
int Expression::isp(char ch){
	int priority = 0;
	switch (ch){
	case '#':
		return 0;
	case '+':case '-':
		return 1;
	case '*':case'/':
		return 2;
	case '(':
		return 3;
	default:
		cout << "wrong symbol!" << endl;
	}
}
int Expression::icp(char ch){
	int priority = 0;
	switch (ch){
	case '+':case '-':
		return 2;
	case '*':case'/':
		return 1;
	default:
		cout << "wrong symbol!" << endl;
	}
}
int isp(char ch);
void Expression::postfix(){
	LinkedStack<char> ss;
	char ch;
	char tempSymbol;
	double operand;
	while (cin >> ch, ch != '#'){
		if (isdigit(ch)) {
			cin.putback(ch); cin >> operand; cout << operand << endl;
		}
		//������ֱ����ջ
		else if (ch == '(') ss.Push(ch);
		//�����������ƥ�䵽������
		else if (ch == ')'){
			ss.Pop(tempSymbol);
			while (tempSymbol != '('){
				cout << tempSymbol << endl;
				ss.Pop(tempSymbol);
			}
		}
		//�������ţ�һֱ
		else {
			ss.getTop(tempSymbol);
			//����µķ���ch�����ȼ�����ջ���ͣ�һֱ���
			while (isp(ch) > isp(tempSymbol)){
				ss.Push(ch);
			}
			while (isp(ch) <= isp(tempSymbol)){
				cout << ch << endl;
				ss.Pop(tempSymbol);
			}
		}
		

	}
	cout << "finished" << endl;
}
double Expression::calculate(){
	char ch;
	double operand;
	//���ζ�����ʽ������ǲ�����������㣬Ȼ����ջ������ǲ�����,ֱ����ջ
	while (cin >> ch, ch != '#'){
		switch(ch){
			//cout << "ch is " << ch << endl;
		case '+': case'-': case'*': case'/':
			operand = doOperator(ch);
			addOperand(operand);
			//cout << "operand is" << operand << endl;
			break;
		default:
			cin.putback(ch);
			cout << "ch is " << ch << endl;
			cin >> operand;
			addOperand(operand);
		}
	}
	cout << "operand is" << operand << endl;
	return operand;
};

double Expression::doOperator(char ch){
	double left=0, right=0, result;

	//ȡ����������
	if (!getTwoOperand(left, right)){ cout << "get Operand ERROR!" << endl;  exit(0); };

	//���ݲ��������м���
	switch (ch){
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left*right;
		break;
	case '/':
		result = left/right;
		break;
	default:
		cout << "wrong operator" << endl;
	}
	return result;
}
//ȡ����������
bool Expression::getTwoOperand(double &a, double &b){
	if (!s.Pop(b)){ cout << "can't get left operator" << endl; return false; }
	if (!s.Pop(a)){ cout << "can't get right operator" << endl; return false; }
	return true;
}
//������������ջ��
void Expression::addOperand(double a){
	s.Push(a);
}
