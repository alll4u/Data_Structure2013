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
	List(){ first = new LinkNode<T>; };    //�޲ι��캯��
	List(const T& x){ first = new LinkNode(x); };  //�вι��캯��
	List(List<T> &L);  //���ƺ���
	~List(){ makeEmpty(); };  //��������
	void makeEmpty(); //�������
	LinkNode <T> *getHead(){ return first; }; //��ȡͷ����ַ
	int Length()const; //����������
	LinkNode<T> *Search(T x); //������������x��Ԫ��
	LinkNode<T> *Locate(int i); //������i��Ԫ�صĵ�ַ
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
		cerr << "�ڴ�������" << endl;
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
	//û������ ��=�� �Ļ�������������ĸ�ֵ�����
	LinkNode<T> *del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}

#endif