#ifndef SEQDEQUE_H
#define SEQDEQUE_H
#include <iostream>
#include <string>
#include "Deque.h"
#include "SeqQueue.h"
#include <assert.h>

using namespace std;

template <class T>
class SeqDeque :public Deque<T>, public SeqQueue<T>{
public:
	SeqDeque(int sz = 10){};
	bool getHead(T &x)const;
	bool getTail(T &x)const;
	/*bool EnQueue(const T &x);
	bool DeQueue(T &x);*/
	bool EnQueueHead(const T &x);
	bool DeQueueHead(T &x);
	bool EnQueueTail(const T &x);
	bool DeQueueTail(T &x);
};

template <class T>
bool SeqDeque<T>::getHead(T &x)const{
	T temp;
	bool tag = SeqQueue<T>::getFront(temp);
	x = temp;
	return tag;
}


template <class T>
bool SeqDeque<T>::getTail(T& x)const{
	if (SeqQueue<T>::IsEmpty())return false;
	x = elements[(rear + maxSize - 1) % maxSize];
	return true;
}
template <class T>
bool SeqDeque<T>::EnQueueHead(const T& x){
	if (SeqQueue<T>::IsFull()) return false;
	front = (front + maxSize - 1) % maxSize;
	elements[front] = x;
	return true;
}
template <class T>
bool SeqDeque<T>::DeQueueHead(T &x){
	T temp;
	bool tag = SeqQueue<T>::DeQueue(temp);
	x = temp;
	return tag;
}
template <class T>
bool SeqDeque<T>::EnQueueTail(const T &x){
	return SeqQueue<T>::EnQueue(x);
}
template <class T>
bool SeqDeque<T>::DeQueueTail(T& x){
	if (SeqQueue<T>::IsEmpty())return false;
	rear = (rear + maxSize - 1) % maxSize;
	x = elements[rear];

	return true;
}

#endif