#include <iostream>
#include "LinkNode.h"
using namespace std;

void main() {
	List<int> lst;
	int bn = 5;
	lst.Insert(2, bn);
	for (int i = 0; i < 10; i++){
		lst.Insert(i, i);
	}
	int a;
	for (int i = 0; i < 10; i++){
		lst.getData(i+2, a);
		
		cout << "a is " << a << endl;
	}
	List<int> lst2 = lst;
	for (int i = 0; i < 10; i++){
		lst2.getData(i + 2, a);
		cout << "address: " << lst.Locate(i + 2) << endl;
		cout << "address: "<<lst2.Locate(i + 2) << endl;
		cout << "a is " << a << endl;
	}
	lst2.output();

	List<double> dLst;
	dLst.input(0.0);
	dLst.output();

	system("pause");

}