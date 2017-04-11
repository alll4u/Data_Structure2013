#ifndef SLINK_H
#define SLINK_H
#include <iostream>
using namespace std;
const int maxSize = 100;
struct SLinkNode<T>{
	T data;
	int link;
};
template <class T>
class StaticList{
	SLinkNode<T> elem[maxSize];
	int avil;
public:
	void InitList();
	void Length();
	int Search(T x);
	int Locate(int i);
	bool Append(T x);
	bool Insert(int i, T x);
	bool Remove(int i);
	bool IsEmpty();

};

#endif