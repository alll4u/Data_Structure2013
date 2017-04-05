#include <iostream>
#include "SeqList.h"
using namespace std;

void main() {
	SeqList<int> test(10);
	int x = 1;
	test.Insert(0, x);
	x = 2; 
	test.Insert(1, x);
	test.Insert(1, x);
	test.Insert(1, x);
	test.Insert(1, x);
	test.Insert(1, x);
	cout << "length " << test.Length() << endl; 
	cout << "isfull " << test.IsFull() << endl;
	cout << "isempty " << test.IsEmpty() << endl;
	cout << test.Size() << endl;
	cout << test.Length() << endl;
	int y;
	test.Remove(2, y);
	cout << "Length is " << test.Length() << " y " << y << endl;
	system("pause");

}