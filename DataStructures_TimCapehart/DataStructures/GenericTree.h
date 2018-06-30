#ifndef GENERICTREE_H
#define GENERICTREE_H
#include "GenericTreeNode.h"
#include <queue>
#include <functional>
#include <locale>

using std::queue;
using std::list;

template<class T>
void visit(const GenericTreeNode<T> * const p)
{
	if (p != nullptr)
		std::wcout << p.GetData() << ' ';
}

template<class T>
class GenericTree
{
private:
	GenericTreeNode<T> * _root = nullptr;
	//void(*_visit)(const GenericTreeNode<T> * const node) = nullptr;
	std::function<void(const GenericTreeNode<T> * const p)> _visit;
	void _BreadthFirst(GenericTreeNode<T> * node) const;
	void _PostOrder(GenericTreeNode<T> * child, std::list<GenericTreeNode<T>*>& traversal);
public:
	GenericTree() = default;
	~GenericTree() = default;
	GenericTree(const GenericTree<T> & copy);
	GenericTree(GenericTree&& copy);
	void CopyConstructor(GenericTreeNode<T> * copy, GenericTreeNode<T> * copy2);
	GenericTree& operator=(const GenericTree<T> & rhs);
	GenericTree& operator=(GenericTree&& rhs);
	void SetFunction(std::function<void(const GenericTreeNode<T> * const p)> visit) noexcept { _visit = visit; };
	void BreadthFirst() noexcept { _BreadthFirst(_root); };
	void SetRoot(GenericTreeNode<T> * root) noexcept { _root = root; };
	void Purge();
};

template<class T>
inline GenericTree<T>::GenericTree(const GenericTree<T> & copy)
{
	if (this != &copy)
		*this = copy;
}

template<class T>
inline GenericTree<T>& GenericTree<T>::operator=(const GenericTree<T> & rhs)
{
	_visit = rhs._visit;
	if (rhs._root != nullptr)
	{
		_root = new GenericTreeNode<T>(rhs._root->GetData());
		CopyConstructor(rhs._root, _root);
	}
	return *this;
}

template<class T>
inline void GenericTree<T>::_BreadthFirst(GenericTreeNode<T> * node) const
{
	queue<GenericTreeNode<T>*> queue;
	list<GenericTreeNode<T>*> children;
	node = _root;
	if (node != nullptr)
	{
		queue.emplace(node);
		while (!queue.empty())
		{
			node = queue.front();
			queue.pop();
			_visit(node);
			if (!queue.empty())
			{
				auto children = node->GetChildren();
				for (auto child : children)
					queue.emplace(child);
			}
		}
	}
}

template<class T>
inline void GenericTree<T>::_PostOrder(GenericTreeNode<T> * child, std::list<GenericTreeNode<T> *>& traversal)
{
	auto children = child->GetChildren();
	for (auto child : children)
		_PostOrder(child, traversal);
	traversal.push_back(child);
}

template<class T>
inline void GenericTree<T>::Purge()
{
	list<GenericTreeNode<T> *> children;
	_PostOrder(_root, children);
	for (auto child : children)
		delete child;
}

template<class T>
inline void GenericTree<T>::CopyConstructor(GenericTreeNode<T>* copy, GenericTreeNode<T>* copy2)
{
	for (auto child : copy->GetChildren())
	{
		GenericTreeNode<T> * new_child = new GenericTreeNode<T>(child->GetData(), copy2);
		if (!new_child->GetChildren().empty())
		{
			CopyConstructor(child, new_child);
		}
		copy2->AddChild(new_child);
	}
}

#endif