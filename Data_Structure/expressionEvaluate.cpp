#include <iostream>
#include "LinkedStack.h"
#include <string>
using namespace std;

class Expression{
public:
	//输入表达式
	void inputExp();
	//由中缀表达式转换为后缀表达式
	void postfix();
	int isp(char ch);
	int icp(char ch);
	//打印表达式
	void printExp(){ cout << "expression is " << expression; }
	//设置表达式
	void setExp(string str){ expression = str; }
	//返回表达式
	string getExp(){ return expression; }
	//计算表达式的值
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
		//左括号直接入栈
		else if (ch == '(') ss.Push(ch);
		//右括号输出，匹配到左括号
		else if (ch == ')'){
			ss.Pop(tempSymbol);
			while (tempSymbol != '('){
				cout << tempSymbol << endl;
				ss.Pop(tempSymbol);
			}
		}
		//其他符号，一直
		else {
			ss.getTop(tempSymbol);
			//如果新的符号ch的优先级不比栈顶低，一直输出
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
	//依次读入表达式，如果是操作符，则计算，然后入栈；如果是操作数,直接入栈
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

	//取两个操作数
	if (!getTwoOperand(left, right)){ cout << "get Operand ERROR!" << endl;  exit(0); };

	//根据操作符进行计算
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
//取两个操作数
bool Expression::getTwoOperand(double &a, double &b){
	if (!s.Pop(b)){ cout << "can't get left operator" << endl; return false; }
	if (!s.Pop(a)){ cout << "can't get right operator" << endl; return false; }
	return true;
}
//将操作数加入栈中
void Expression::addOperand(double a){
	s.Push(a);
}
