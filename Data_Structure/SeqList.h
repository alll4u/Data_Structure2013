#ifndef SEQLIST_H
#define SEQLIST_H


#include <iostream>
#include <stdlib.h>
#include "LinearList.h"
using namespace std;

const int defaultSize = 100;
template <class T>
class SeqList :public LinearList<T>
{
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList() { delete[] data; };
	int Size()const { return maxSize; };
	int Length()const { return last + 1; };
	int Search(T &x)const;
	//int locate(int i)const = 0;
	bool getData(int i, T& x)const {
		if (i > 0 && i <= last + 1) {
			x = data[i - 1];
			return true;
		}
		else
			return false;
	};
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()const;
	bool IsFull()const;
	//bool Sort();
	/*bool input();
	bool output()const;*/
	//LinearList<T> operator=(LinearList<T>& L) = 0;

protected:
	T *data;
	int maxSize;
	int last;
	void reSize(int newSize);

};


template <class T>
SeqList<T>::SeqList(int sz){
	if (sz > 0){
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == NULL) {
			cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
			exit(1);
		}
	}
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L) {
	maxSize = L.Size();
	last = L.Length();
	T value;
	data = new T[maxSize];
	if (data == NULL) {
		cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
		exit(1);
	}
	for (int i = 1; i < last + 1; i++) {
		L.getData(i, value);
		data[i - 1] = value;
	}

}

template <class T>
void SeqList<T>::reSize(int newSize) {

}

template <class T>
int SeqList<T>::Search(T &x)const{
	for (int i = 0; i < last; i++) {
		if (data[i] == x)
			return i + 1;
	}
	return -1;
}

template <class T>
void SeqList<T>::setData(int i, T &x){
	if (i>0 && i <= last+1){
		data[i - 1] = x;
	}
}
template <class T>
bool SeqList<T>::Insert(int i, T &x){
	if (last == maxSize - 1) return false;
	if (i<0 || i>last + 1)return false;
	for (int j = last; j >= i; j--){
		data[j+1] = data[j];
	}
	data[i] = x;
	last++;
	return true;
}
template <class T>
bool  SeqList<T>::IsFull() const{ return (last == maxSize - 1) ? true : false; }
template <class T>
bool SeqList<T>::IsEmpty() const{ return (last == -1) ? true : false; }
template <class T>
bool SeqList<T>::Remove(int i, T& x){
	if (last == -1) return false;
	x = data[i - 1];
	if (i < 0 || i>last + 1) return false;
	for (int j = last; j > i; j--){
		data[j - 1] = data[j];
	}
	last--;
	return true; 
}
#endif // !SEQLIST_H