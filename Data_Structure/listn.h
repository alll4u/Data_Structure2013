#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "LinearList.h"
using namespace std;
template <class T>
class LinkNode{
	LinkNode<T> *link;
	T data;
	LinkNode(LinkNode<T> *ptr == NULL){link = ptr};
	LinkNode(const T& x, LinkNode<T> *ptr == NULL){
		data = x; link = ptr;
	}
};

template <class T>
class List{
public:
	List(){ first = new LinkNode<T>; };
	List(const T& x){ first = new LinkNode(x); };
	List(List<T> &L);
	~List(){ makeEmpty(); };
	void makeEmpty();
	LinkNode <T> *getHead(){ return first; };
	int Length()const;

protected:
	LinkNode<T> *first;
};
template <class T>
List<T>::List(List<T>& L){
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL){
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
};

template <class T>
void List<T>::makeEmpty(){
	LinkNode<T> *p = getHead();
	LinkNode<T> *current = p->link;
	while (p->link != NULL){
		current = p;
		p = p->link;
		delete p;
	}
	/*LinkNode<T>* q;
	while (first->link != NULL){
		q = first->link;
		first->link = q->link;
		delete q;
	}*/

}
template <class T>
int List<T>::Length()const{
	int length = 0;
	LinkNode<T> *p = first->link;
	while (p != NULL){
		length++;
		p = p->link;
	}
	return length;
}

#endif