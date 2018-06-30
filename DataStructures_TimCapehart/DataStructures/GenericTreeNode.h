#ifndef GENERICTREENODE_H
#define GENERICTREENODE_H
#include<list>


template<class T>
class GenericTreeNode
{
private:
	GenericTreeNode<T>* _parent = nullptr;
	std::list<GenericTreeNode<T>*> _children;
	T _data;

public:
	explicit GenericTreeNode(T data, GenericTreeNode<T>* parent = nullptr)
		: _data(data), _parent(parent) { }

	~GenericTreeNode() { _children.clear(); _parent = nullptr; };
	GenericTreeNode<T>* GetParent() const noexcept { return _parent; };
	void SetParent(GenericTreeNode<T>* parent) noexcept { _parent = parent; };
	GenericTreeNode(const GenericTreeNode<T> & copy);
	std::list<GenericTreeNode<T>*> GetChildren() const noexcept { return _children; };
	void AddChild(GenericTreeNode<T> * const child) noexcept { _children.emplace_back(child); };
	T GetData() { return _data; };
	T GetData() const { return _data; };
};

template<class T>
inline GenericTreeNode<T>::GenericTreeNode(const GenericTreeNode<T> & copy)
{
	_parent = copy._parent;
	_children = copy._children;
}

#endif
