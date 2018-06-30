#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "ListStack.h"
#include "ListQueue.h"

template<class T>
class BSTNode
{
public:
	BSTNode<T> * _left, *_right;
	T _data;

	BSTNode() { _left = _right = nullptr; };
	BSTNode(const T & e, BSTNode<T> * l = nullptr, BSTNode<T> * r = nullptr)
		{ _data = e; _left = l; _right = r; };
	//destructor? delete left and right
};
//------------------------------------------------------------------------
template<class T>
void Visit(BSTNode<T> * p)
{
	if(p != nullptr)
		std::cout << p->_data << ' ';
}
// -----------------------------------------------------------------------

template<class T>
class BST
{
private:
	BSTNode<T> * _root;
	void(*_Visit)(BSTNode<T> *) = Visit;
public:
	BST() { _root = nullptr; };
	~BST() { Purge(); };
	
	BSTNode<T> * Search(const T & data) { return Search(_root, data); }
	void InOrder() { InOrder(_Visit, _root); };
	void PreOrder() { PreOrder(_Visit, _root); };
	void PostOrder() { PostOrder(_Visit, _root); };
	void BreadthFirst() { BreadthFirst(_Visit, _root); };
	void Insert(const T & data) { Insert(_root, data); };
	int Height() { return Height(_root); };
	void Purge() { Purge(_root); _root = nullptr; };

	void SetFunction(void(*func)(BSTNode<T> *));
	void InOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p);
	void PreOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p);
	void PostOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p);
	void BreadthFirst(void(*func)(BSTNode<T> *), BSTNode<T> * p);
	
	BSTNode<T> * Search(BSTNode<T> * root, const T & data);
	void Insert(BSTNode<T> *& _root, const T & data);
	void Delete(const T & data);
	void DeleteNode(BSTNode<T> * p, BSTNode<T> * d);
	
	void Purge(BSTNode<T> * p);
	bool IsEmpty() const { return _root == nullptr; };
	int Height(BSTNode<T> *);
};
// --------------------------------------------------------------------
template<class T>
inline void BST<T>::SetFunction(void(*func)(BSTNode<T> *))
{
	_Visit = func;
}

template<class T>
inline void BST<T>::Purge(BSTNode<T> * p)
{
	if (p != nullptr)
	{
		if (p->_left != nullptr)
			Purge(p->_left);
		if (p->_right != nullptr)
			Purge(p->_right);
		delete p;
	}
}

template<class T>
inline BSTNode<T> * BST<T>::Search(BSTNode<T> * root, const T & data)
{
	if (root == nullptr || root->_data == data)
		return root;
	else if (root->_data < data)
		return Search(root->_right, data);
	else
		return Search(root->_left, data);
}

template<class T>
inline void BST<T>::InOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p)
{
	if (p != nullptr)
	{
		if (p->_left != nullptr)
			InOrder(func, p->_left);
		func(p);
		if (p->_right != nullptr)
			InOrder(func, p->_right);
	}
}

template<class T>
inline void BST<T>::PreOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p)
{
	if (p != nullptr)
	{
		func(p);
		if (p->_left != nullptr)
			PreOrder(func, p->_left);
		if (p->_right != nullptr)
			PreOrder(func, p->_right);
	}
}

template<class T>
inline void BST<T>::PostOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p)
{
	if (p != nullptr)
	{
		if (p->_left != nullptr)
			PostOrder(func, p->_left);
		if (p->_right != nullptr)
			PostOrder(func, p->_right);
		func(p);
	}
}

template<class T>
inline void BST<T>::BreadthFirst(void(*func)(BSTNode<T> *), BSTNode<T> *p)
{
	ListQueue<BSTNode<T> *> queue;
	p = _root;
	if (p != nullptr)
	{
		queue.Enqueue(p);
		while (!queue.IsEmpty())
		{
			p = queue.Dequeue();
			func(p);
			if (p->_left != nullptr)
				queue.Enqueue(p->_left);
			if (p->_right != nullptr)
				queue.Enqueue(p->_right);
		}
	}
}

template<class T>
inline void BST<T>::Insert(BSTNode<T> *& root, const T & data)
{
	if (root == nullptr)
		root = new BSTNode<T>(data);
	else
	{
		if (data < root->_data)
			Insert(root->_left, data);
		else
			Insert(root->_right, data);
	}
}

template<class T>
inline void BST<T>::Delete(const T & data)
{
	if (IsEmpty())
		throw Exception("Tree is empty!");
	else
	{
		BSTNode<T> * cur, *prev;
		cur = prev = _root;
		while (cur != nullptr && cur->_data != data)
		{
			prev = cur;
			if (cur->_data > data)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		if (cur == nullptr)
			throw Exception("Error.");
		else
			DeleteNode(prev, cur);
	}
}

template<class T>
inline void BST<T>::DeleteNode(BSTNode<T> * p, BSTNode<T> * d)
{
	BSTNode<T> * cur = d;
	BSTNode<T> * prev = p;

	if (p == nullptr)
		throw Exception("Parent is nullptr.");
	else if (d->_left == nullptr && d->_right == nullptr) // leaf
	{
		if (p->_data > d->_data)
			p->_left = nullptr;
		else
			p->_right = nullptr;
	}
	else if (d->_left == nullptr && d->_right != nullptr) // right tree
	{
		if (p->_data > d->_data)
			p->_left = d->_right;
		else
			p->_right = d->_right;
	}
	else if (d->_right == nullptr && d->_left != nullptr) // left tree
	{
		if (p->_data > d->_data)
			p->_left = d->_left;
		else
			p->_right = d->_left;
	}
	else // left and right tree
	{
		cur = d->_right;
		prev = cur;
		while(cur->_left != nullptr)
		{
			prev = cur;
			cur = cur->_left;
		}
		d->_data = cur->_data;
		if (cur->_right != nullptr)
			d->_right = cur->_right;
		else
			prev->_left = nullptr;
	}
	delete cur;
	cur = nullptr;
}

template<class T>
inline int BST<T>::Height(BSTNode<T> * n)
{
	if (n == nullptr)
		return 0;
	int l = n->_left ? Height(n->_left) : 0;
	int r = n->_right ? Height(n->_right) : 0;
	return ((l > r) ? l : r);
}
#endif