#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <string>
#include "Queue.h"
#include <assert.h>
template <class T>
class Deque :public Queue<T>{
public:
	virtual bool getHead(T &x)const = 0;
	virtual bool getTail(T &x)const = 0;
	bool EnQueue(const T &x);
	bool DeQueue(T &x);
	virtual bool EnQueueHead(const T &x)=0;
	virtual bool DeQueueHead(T &x)=0;
	virtual bool EnQueueTail(const T &x)=0;
	virtual bool DeQueueTail(T &x)=0;
};


#endif
