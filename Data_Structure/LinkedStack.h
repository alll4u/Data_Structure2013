#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
#include "LinkNode.h"
#include"Stack.h"
#include <assert.h>

template <class T>
class LinkedStack :public Stack<T>{
public:
	LinkedStack() :top(NULL){}
	LinkedStack(int x) :top(NULL){}
	~LinkedStack(){ makeEmpty(); }
	void Push(const T& x);
	bool Pop(T &x);
	bool getTop(T& x)const;
	bool IsEmpty()const{ return (top == NULL) ? true : false; };
	bool IsFull()const{ return false; };
	int getSize()const;
	void makeEmpty();
	friend ostream& operator<<(ostream& os, LinkedStack<T>& Q){
		os << Q.getSize();
		return os;
	};
private:
	LinkNode<T> *top;
};
template <class T>
void LinkedStack<T>::Push(const T& x){
	top = new LinkNode<T>(x, top);
	assert(top != NULL);
};
template <class T>
bool LinkedStack<T>::Pop(T& x){
	if (IsEmpty() == true)return false;
	LinkNode<T> *p = top;
	top = top->link;
	x = p->data;
	delete p;
	return true;
};

template <class T>
bool LinkedStack<T>::getTop(T& x)const{
	if (IsEmpty() == true)return false;
	x = top->data;
	return true;
};
template <class T>
int LinkedStack<T>::getSize()const{
	LinkNode<T> *p = new LinkNode<T>;
	int count = 0;
	p = top;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
};
template <class T>
void LinkedStack<T>::makeEmpty(){
	LinkNode<T> *p;
	while (top != NULL){
		p = top;
		top = top->link;
		delete p;
	}
}
//template <class T>
//ostream& operator<<(ostream& os, LinkedStack<T>& Q){
//	/*os << "front = " << Q.front << ", rear = " << Q.rear << endl;
//
//	for (int i = front; i != rear; i = (i + 1) % maxSize){
//	os << i << ":" << Q.elements[i] << endl;
//	}*/
//	os << Q.getSize();
//	return os;
//}

#endif