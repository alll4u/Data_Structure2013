#include <iostream>
#include <string>
#include <stdio.h>
#include "SeqQueue.h"
using namespace std;

//������뻹������Ȥ��
//һ������ʵ��
void YANGHUI(int n){
	SeqQueue<int> sq(n+2);
	int t, s=0, u = 0;
	sq.EnQueue(1);
	sq.EnQueue(1);

	for (int i = 1; i <= n; i++){
		cout << endl;
		sq.EnQueue(0);
		//����һ�䲻��Ҫ
		//s = 0;
		for (int j = 1; j <= i + 2; j++){
			sq.DeQueue(t);
			u = t+s;
			sq.EnQueue(u);
			s = t;
			if (j!=i+2)
				cout << s << " ";
		}
	}
}

//int main(){
//
//	YANGHUI(4);
//
//
//
//	system("pause");
//	return 0;
//}