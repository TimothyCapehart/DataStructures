#ifndef AVL_H
#define AVL_H
#include"ListStack.h"
#include"ListQueue.h"

enum BF { RH = -1, EH = 0, LH = 1 };

template<class T>
class AVLNode
{
public:
	
	AVLNode<T> *_left, *_right;
	T _data;
	BF _bf;
	AVLNode() { _left = _right = nullptr; _bf = EH; };
	AVLNode(const T & data, AVLNode<T> * l = nullptr, AVLNode<T> * r = nullptr)
	{
		_data = data; _left = l; _right = r; _bf = EH;
	}
};
//------------------------------------------------------------------------
template<class T>
void Visit(AVLNode<T> * p)
{
	if (p != nullptr)
		std::cout << p->_data << ' ';
}
// -----------------------------------------------------------------------

template<class T>
class AVL
{
private:
	AVLNode<T> * _root;
	bool _taller;
	bool _shorter;
	bool _success;
	void(*_Visit)(AVLNode<T> *) = Visit;

	void Purge(AVLNode<T> * p);
	void InOrder(void(*func)(AVLNode<T> *), AVLNode<T> * p);
	void PreOrder(void(*func)(AVLNode<T> *), AVLNode<T> * p);
	void PostOrder(void(*func)(AVLNode<T> *), AVLNode<T> * p);
	void BreadthFirst(void(*func)(AVLNode<T> *), AVLNode<T> * p);

	void Insert(AVLNode<T> *& _root, const T & data, bool & _taller);
	void LeftBalance(AVLNode<T> *& root, bool & taller);
	void RightBalance(AVLNode<T> *& root, bool & taller);
	AVLNode<T> * RotateRight(AVLNode<T> * root);
	AVLNode<T> * RotateLeft(AVLNode<T> * root);
	AVLNode<T> * Delete(AVLNode<T> *& root, const T & data, bool & success, bool & shorter);
	AVLNode<T> * DeleteRightBalance(AVLNode<T> *& root, bool & shorter);
	AVLNode<T> * DeleteLeftBalance(AVLNode<T> *& root, bool & shorter);
	AVLNode<T> * Search(AVLNode<T> * root, const T & data);

public:
	AVL() { _root = nullptr; _taller = false; _success = false; };
	~AVL() { Purge(); };

	void SetFunction(void(*func)(AVLNode<T> *));
	void InOrder() { InOrder(_Visit, _root); };
	void PreOrder() { PreOrder(_Visit, _root); };
	void PostOrder() { PostOrder(_Visit, _root); };
	void BreadthFirst() { BreadthFirst(_Visit, _root); };

	void Insert(const T & data) { Insert(_root, data, _taller); };
	void Purge() { Purge(_root); };
	int Height() { return Height(_root); };
	int Height(AVLNode<T> * n);
	AVLNode<T> * Delete(const T & data) { return Delete(_root, data, _success, _shorter); };
	AVLNode<T> * Search(const T & data) { return Search(_root, data); };

};

template<class T>
inline void AVL<T>::SetFunction(void(*func)(AVLNode<T> *))
{
	_Visit = func;
}

template<class T>
inline AVLNode<T> * AVL<T>::Search(AVLNode<T> * root, const T & data)
{
	if (root == nullptr || root->_data == data)
		return root;
	else if (root->_data < data)
		return Search(root->_right, data);
	else
		return Search(root->_left, data);
}

template<class T>
inline void AVL<T>::Purge(AVLNode<T> * p)
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
inline void AVL<T>::Insert(AVLNode<T> *& root, const T & data, bool & taller)
{
	if (root == nullptr)
	{
		root = new AVLNode<T>(data);
		taller = true;
		return;
	}
	if (data < root->_data) // left subtree
	{
		Insert(root->_left, data, taller);
		if (taller)
		{
			switch (root->_bf)
			{
			case LH: LeftBalance(root, taller); break;
			case EH: root->_bf = LH; break;
			case RH: root->_bf = EH; taller = false; break;
			}
		}
	}
	else if (data > root->_data) // right subtree
	{
		Insert(root->_right, data, taller);
		if (taller)
		{
			switch (root->_bf)
			{
			case LH: root->_bf = EH; taller = false; break; 
			case EH: root->_bf = RH; break;
			case RH: RightBalance(root, taller); break;
			}
		}
	}
}

template<class T>
inline void AVL<T>::LeftBalance(AVLNode<T> *& root, bool & taller)
{
	switch (root->_left->_bf)
	{
	case LH:
		root->_bf = EH;
		root->_left->_bf = EH;
		root = RotateRight(root);
		taller = false;
		break;
	case EH: throw Exception("Error.");
	case RH:
		switch (root->_left->_right->_bf)
		{
		case LH:
			root->_bf = RH;
			root->_left->_bf = EH;
			break;
		case EH:
			root->_bf = EH;
			root->_left->_bf = EH;
			break;
		case RH:
			root->_bf = EH;
			root->_left->_bf = LH;
			break;
		}
		root->_left->_right->_bf = EH;
		root->_left = RotateLeft(root->_left);
		root = RotateRight(root);
		taller = false;
		break;
	}
}

template<class T>
inline void AVL<T>::RightBalance(AVLNode<T> *& root, bool & taller)
{
	switch (root->_right->_bf)
	{
	case RH:
		root->_bf = EH;
		root->_right->_bf = EH;
		root = RotateLeft(root);
		taller = false;
		break;
	case EH: throw Exception("Error.");
	case LH:
		switch (root->_right->_left->_bf)
		{
		case RH:
			root->_bf = LH;
			root->_right->_bf = EH;
			break;
		case EH:
			root->_bf = EH;
			root->_right->_bf = EH;
			break;
		case LH:
			root->_bf = EH;
			root->_right->_bf = RH;
			break;
		}
		root->_right->_left->_bf = EH;
		root->_right = RotateRight(root->_right);
		root = RotateLeft(root);
		taller = false;
		break;
	}
}

template<class T>
inline AVLNode<T> * AVL<T>::RotateRight(AVLNode<T> * root)
{
	AVLNode<T> * temp = root->_left;
	root->_left = temp->_right;
	temp->_right = root;
	return temp;
}

template<class T>
inline AVLNode<T> * AVL<T>::RotateLeft(AVLNode<T> * root)
{
	AVLNode<T> * temp = root->_right;
	root->_right = temp->_left;
	temp->_left = root;
	return temp;
}

template<class T>
inline AVLNode<T> * AVL<T>::Delete(AVLNode<T> *& root, const T & data, bool & success, bool & shorter)
{
	if (root == nullptr)
		throw Exception("Tree is empty!");
	if (data < root->_data)
	{
		root->_left = Delete(root->_left, data, success, shorter);
		if (shorter) // tree shorter?
			root = DeleteRightBalance(root, shorter);
	}
	else if (data > root->_data)
	{
		root->_right = Delete(root->_right, data, success, shorter);
		if (shorter) // tree shorter?
			root = DeleteLeftBalance(root, shorter);
	}
	else
	{
		AVLNode<T> * n_root = root;
		AVLNode<T> * cur = nullptr;
		if (root->_left == nullptr && root->_right == nullptr) // leaf node
		{
			delete root;
			success = true;
			root = nullptr;
		}
		else if (root->_left != nullptr && root->_right == nullptr) // left subtree, no right
		{
			
			delete root;
			success = true;
			return n_root;
		}
		else if (root->_left == nullptr && root->_right != nullptr) // right subtree, no left
		{
			n_root = root->_right;
			delete root;
			success = true;
			return n_root;
		}
		else // left and right subtrees
		{
			//n_root = root;
			cur = root->_left;
			while (cur->_right != nullptr)
			{
				cur = cur->_right;
			}
			T temp = cur->_data;
			root->_data = temp;
			root->_left = Delete(root->_left, temp, success, shorter);
			if (shorter) // tree shorter?
				root = DeleteRightBalance(root, shorter);
		}
	}
	return root;
}

template<class T>
inline AVLNode<T> * AVL<T>::DeleteRightBalance(AVLNode<T> *& root, bool & shorter)
{
	switch (root->_bf)
	{
	case LH:
		root->_bf = EH;
		break;
	case EH:
		root->_bf = RH;
		break;
	case RH:
		if (root->_right->_bf == LH)
		{
			AVLNode<T> * leftTree = root->_right->_left;
			switch (leftTree->_bf)
			{
			case LH:
			{
				root->_bf = LH;
				root->_right->_bf = EH;
				break;
			}
			case EH:
			{
				root->_bf = EH;
				root->_right->_bf = EH;
				break;
			}
			case RH:
			{
				root->_bf = EH;
				root->_right->_bf = RH;
				break;
			}
			}
			leftTree->_bf = EH;
			root = RotateLeft(root);
		}
		else
		{
			AVLNode<T> * rightTree = root->_right;
			switch (rightTree->_bf)
			{
			case LH: break;
			case RH:
			{
				root->_bf = EH;
				rightTree->_bf = EH;
				break;
			}
			case EH :
			{
				root->_bf = RH;
				rightTree->_bf = LH;
				shorter = false;
				break;
			}
			}
			root = RotateLeft(root);
		}
	}
	return root;
}

template<class T>
inline AVLNode<T> * AVL<T>::DeleteLeftBalance(AVLNode<T> *& root, bool & shorter)
{
	switch (root->_bf)
	{
	case RH:
		root->_bf = EH;
		break;
	case EH:
		root->_bf = LH;
		break;
	case LH:
		if (root->_left->_bf == RH)
		{
			AVLNode<T> * rightTree = root->_left->_right;
			switch (rightTree->_bf)
			{
			case RH:
				root->_bf = RH;
				root->_left->_bf = EH;
				break;
			case EH:
				root->_bf = EH;
				root->_left->_bf = EH;
				break;
			case LH:
				root->_bf = EH;
				root->_left->_bf;
				break;
			}
			rightTree->_bf = EH;
			root = RotateRight(root);
		}
		else
		{
			AVLNode<T> * leftTree = root->_left;
			switch (leftTree->_bf)
			{
			case RH: break;
			case LH:
				root->_bf = EH;
				leftTree->_bf = EH;
				break;
			case EH:
				root->_bf = LH;
				leftTree->_bf = RH;
				shorter = false;
				break;
			}
		}
		root = RotateRight(root);
	}
	return root;
}

template<class T>
inline void AVL<T>::BreadthFirst(void(*func)(AVLNode<T> *), AVLNode<T> *p)
{
	ListQueue<AVLNode<T> *> queue;
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
inline void AVL<T>::InOrder(void(*func)(AVLNode<T> *), AVLNode<T> * p)
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
inline void AVL<T>::PreOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p)
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
inline void AVL<T>::PostOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p)
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
inline int AVL<T>::Height(AVLNode<T> * n)
{
	if (n == nullptr)
		return 0;
	int l = n->_left ? Height(n->_left) : 0;
	int r = n->_right ? Height(n->_right) : 0;
	return ((l > r) ? l : r);
}

#endif