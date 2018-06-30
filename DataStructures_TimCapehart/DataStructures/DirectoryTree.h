#ifndef DIRECTORYTREE_H
#define DIRECTORYTREE_H
#include <list>
using std::list;

template<class T>
class DirectoryNode
{
public:
	list<DirectoryNode<T *>> * _children;
	DirectoryNode<T*> * _parent;
	T * _data;
	bool _file = false;
	DirectoryNode() { _children = nullptr; };
	DirectoryNode(const wchar_t * data, bool file) { _children = nullptr; _data = data;  _file = file; }
};

template<class T>
class DirectoryTree
{
	
private:
	DirectoryNode<T*> * _root;

public:
	DirectoryTree() { _root = nullptr; };
	DirectoryNode<wchar_t*> & GetRoot() { return _root; };
	void InsertDirectory(DirectoryNode<T> *& root, T & data);
	void InsertDirectory(DirectoryNode<T *> *& root, T * data);
};

//template<class T>
//inline void DirectoryTree<T*>::InsertDirectory(DirectoryNode<T*> *& root, T * data)
//{
//	if (root == nullptr)
//		root = new DirectoryNode<T*>(data, false);
//	
//}




#endif
