#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
struct BinTreeNode{
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL){}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
		:data(x), leftChild(l), rightChild(r){}
};

template <class T>
class BinTree{
public:
	BinTree() :root(NULL){}  //���캯��
	BinTree(T value) :RefValue(value), root(NULL){} //���캯��
	BinTree(BinTree<T>& s);   //���ƹ��캯��
	~BinTree(){ destroy(root); }											//��������
	bool IsEmpty(){ return (root == NULL) ? true : false; }					//�ж϶������Ƿ�Ϊ��
	BinTreeNode<T> *Parent(BinTreeNode<T> *current){						//���ظ��ڵ�
		return (root == NULL || root == current) ?
		NULL : Parent(root, current);
	}
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *current){						//��������
		return (current != NULL) ? current->leftChild : NULL;				
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T> *current){					//�����Һ���
		return (current != NULL) ? current->rightChild : NULL;
	}
	int Height(){ return Height(root); }									//�������߶�
	int Size(){ return Size(root); }										//���ؽڵ���
	BinTreeNode<T> *getRoot()const { return root; }							//ȡ���ڵ�
	void preOrder(void (*visit)(BinTreeNode<T> *p)){ preOrder(root, visit); }//�������
	void inOrder(void (*visit)(BinTreeNode<T> *p)){ inOrder(root, visit); }
	void postOrder(void(*visit)(BinTreeNode<T> *p)){ postOrder(root, visit); }
	void levelOrder(void(*visit)(BinTreeNode<T> *p));						//��α���
	int Insert(const T& item);												//����Ԫ��
	BinTreeNode<T> *Find(T& item)const;										//����Ԫ��
protected:		
	BinTreeNode<T> *root;
	T RefValue;
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)const;
	void destroy(BinTreeNode<T> *subTree);
	int Height(BinTreeNode<T> *subTree)const;
	int Size(BinTreeNode<T> *subTree)const;
	void preOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	void inOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	void postOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	BinTreeNode<T> *Copy(BinTreeNode<T> * orignode);
	
};
template <class T>
BinTreeNode<T>::BinaryTree(const BinaryTree<T>& s){
	root = Copy(s.root);
}
template <class T>
BinTreeNode<T> *BinTree<T>::Copy(BinTreeNode<T> * orignode){
	if (orignode == NULL) return NULL;
	BinTreeNode<T> * temp = new BinTreeNode<T>;
	temp->data = prignode->data;
	temp->leftChild = Copy(orignode->leftChild);
	temp->rightChild = Copy(orignode->rightChild);
	return temp;
}
template <class T>
BinTreeNode<T> *BinTree<T>::
template <class T>
BinTreeNode<T> *BinTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current){
	if (subTree == NULL)return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;
	BinTreeNode<T> *p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)
		return p;
	else return Parent(subTree->rightChild, current);

}
template <class T>
void BinTree<T>::destroy(BinTreeNode<T> *subTree){
	if (subTree != NULL){
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}
template <class T>
int BinTree<T>::Height(BinTreeNode<T> *subTree)const{
	if (subTree == NULL) return 0;
	else{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rigtChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

template<class T>
int BinTree<T>::Size(BinTreeNode<T> *subTree)const{
	if (subTree == NULL)return 0;
	else return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}


template<class T>
void BinTree<T>::preOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p)){
	if (subTree != NULL){
		visit(subTree);
		preOrder(subTree.leftChild, visit);
		preOrder(subTree.rightChild, visit);
	}
}
template<class T>
void BinTree<T>::inOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p)){
	if (subTree != NULL){
		inOrder(subTree.leftChild, visit);
		visit(subTree);
		inOrder(subTree.rightChild, visit);
	}
}
template<class T>
void BinTree<T>::postOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p)){
	if (subTree != NULL){
		postOrder(subTree.leftChild, visit);
		postOrder(subTree.rightChild, visit);
		visit(subTree);
	}
}
template<class T>
void BinTree<T>::levelOrder(void(*visit)(BinTreeNode<T> *p)){

}
template<class T>
int BinTree<T>::Insert(const T& item){

}

template<class T>
BinTreeNode<T> *BinTree<T>::Find(T& item)const;

#endif