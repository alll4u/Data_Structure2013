#include <string>
#include "Queue.h"
#include "LinkNode.h"
#include <assert.h>

using namespace std;

template <class T>
class LinkedQueue :public Queue<T>{
public:
	LinkedQueue() :front(NULL), rear(NULL){};
	~LinkedQueue(){ makeEmpty(); };
	void makeEmpty();
	bool EnQueue(const T& x);
	bool DeQueue(T &x);
	bool getFront(T& x)const;
	bool IsEmpty()const{ return (front==NULL) ? true : false; };
	bool IsFull()const{ return false; };
	int getSize()const;
protected:
	LinkNode<T> *front, *rear;
};

template <class T>
void LinkedQueue<T>::makeEmpty(){
	LinkNode<T> *temp = NULL;
	//这里应该用NULL还是rear做判断呢？
	while (front != NULL){
		temp = front;
		
		front = front->link;
		delete temp;
	}
}
template <class T>
bool LinkedQueue<T>::EnQueue(const T& x){
	if (front == NULL){
		front = rear = new LinkNode<T>(x);
		assert(front != NULL);
	}
	
	else{
		rear->link = new LinkNode<T>(x);

		if (rear->link == NULL)return false;
		rear = rear->link;
	}
	return true;
}

template <class T>
bool LinkedQueue<T>::DeQueue(T& x){
	if (IsEmpty() == true) return false;
	LinkNode<T> *p = front;
	x = front->data;
	p = front;
	front = front->link;
	delete p;
	return true;
}
template <class T>
bool LinkedQueue<T>::getFront(T& x)const{
	if (!front) return false;
	x = front->data;
	return true;
}
template <class T>
int LinkedQueue<T>::getSize()const{
	int count=0;
	if (IsEmpty()) return 0;
	LinkNode<T> *p = front;
	while (p != NULL){
		count++;
		p = p->link;
	}
	return count;
}