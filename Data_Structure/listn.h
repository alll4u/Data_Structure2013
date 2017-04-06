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
	List(){ first = new LinkNode<T>; };    //无参构造函数
	List(const T& x){ first = new LinkNode(x); };  //有参构造函数
	List(List<T> &L);  //复制函数
	~List(){ makeEmpty(); };  //析构函数
	void makeEmpty(); //清空链表
	LinkNode <T> *getHead(){ return first; }; //获取头结点地址
	int Length()const; //返回链表长度
	LinkNode<T> *Search(T x); //搜索含有数据x的元素
	LinkNode<T> *Locate(int i); //搜索第i个元素的地址
	bool getData(int i, T& x);
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty(){ return first == NULL ? true : false; }
	bool IsFull(){ return false; }
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
template <class T>
LinkNode<T> *List<T>::Search(T x){
	LinkNode<T> *current = first->link;
	while (current != NULL){
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}
template <class T>
LinkNode<T> *List<T>::Locate(int i){
	if (i < 0) return NULL;
	LinkNode<T> *current = first;
	int count = 0;
	while (current != NULL && count < i){
		current = current->link;
		count++;
	}
	return current;
}
template <class T>
bool List<T>::getData(int i,T& x){
	if (i < 0) return NULL;
	LinkNode<T> *current = Locate(i);
	if (current == NULL)return false;
	else {
		x = current->data;
		return true;
	}
	
}
template <class T>
void List<T>::setData(int i, T& x){
	if (i < 0) return NULL;
	LinkNode<T> *current = Locate(i);
	if (current == NULL)return;
	else {
		current->data = x;
	}
}

template <class T>
bool List<T>::Insert(int i, T& x){
	if (i < 0) return NULL;
	LinkNode<T> *current = Locate(i);
	if (current == NULL)return false;
	LinkNode *newNode = new LinkNode(x);
	if (newNode == NULL){
		cerr << "内存分配错误" << endl;
		exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template <class T>
bool List<T>::Remove(int i, T& x){
	if (i < 0) return NULL;
	LinkNode<T> *current = Locate(i-1);
	if (current == NULL || current->link == NULL)return false;
	//没有重载 “=” 的话，可以用下面的赋值语句吗
	LinkNode<T> *del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}

#endif