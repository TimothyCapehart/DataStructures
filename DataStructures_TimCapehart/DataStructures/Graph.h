
#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include "Arc.h"
#include "Exception.h"
#include<stack>
#include<queue>
#include <list>
#include <iterator>
using std::find;
using std::list;
using std::stack;
using std::queue;


template<class V>
void Visit(V it)
{
	std::cout << it << endl;
};

template<class V, class E>
class Graph
{
private:
	list<Vertex<V, E>> _vertices;
	int _count;
	void(*_visit)(V it) = Visit;

public:
	Graph();
	Graph(const Graph<V, E> & rhs);
	~Graph() {};

	Graph<V, E> & operator=(const Graph<V, E> & rhs);
	void InsertVertex(const V & data);
	void DeleteVertex(const V & data);
	Vertex<V, E> * GetVertex(V data);
	list<Vertex<V, E>> GetVertices() { return _vertices; };
	void SetFunction(void(*func)(V));
	void SetDefFunc(void(*func)(V)) { _visit = Visit; };
	void InsertArc(const V & from, const V & to, Arc<V, E> arc);
	void InsertArc(const V & from, const V & to, const E & data);
	void InsertArc(const V & from, const V & to, const E & data, int weight);
	void DeleteArc(const V & from, const V & to, const E & data);
	void DeleteArc(const V & from, const V & to, Arc<V, E> arc);
	void DepthFirst(void(*visit)(V it));
	void DepthFirst() { DepthFirst(_visit); };
	void BreadthFirst(void(*visit)(V it));
	void BreadthFirst() { BreadthFirst(_visit); };
	bool IsEmpty() { return _count == 0; };
	void ResetProcessed();
	void Purge() { _vertices.clear(); _count = 0; };

};

template<class V, class E>
inline Graph<V, E>::Graph()
{
	_count = 0;
}

template<class V, class E>
inline void Graph<V, E>::SetFunction(void(*func)(V))
{
	_visit = func;
}

template<class V, class E>
inline Vertex<V, E>* Graph<V, E>::GetVertex(V data)
{

	for (auto iter = _vertices.begin(); iter != _vertices.end(); iter++)
	{
		if ((*iter).GetData() == data)
		{
			return &*iter;
		}
	}
	return nullptr;
	//throw Exception("Vertex not found.");
}

template<class V, class E>
inline Graph<V, E>::Graph(const Graph<V, E> & rhs)
{
	
	Vertex<V, E> *temp;
	for (auto it = rhs._vertices.begin(); it != rhs._vertices.end(); it++)
	{
		V v = (*it).GetData();
		this->InsertVertex(v);
	}

	for (auto it = rhs._vertices.begin(); it != rhs._vertices.end(); it++)
	{
		if ((*it).GetOutDeg() > 0)
		{
			list<Arc<V, E>> outArcs = (*it).GetOutEdges();
			for (auto it2 = outArcs.begin(); it2 != outArcs.end(); it2++)
			{
				Vertex<V, E> temp = *(it2->GetDest());
				InsertArc((*it).GetData(), temp.GetData(), (*it2));
			}

		}
		else if ((*it).GetInDeg() > 0)
		{
			list<Arc<V, E>> inArcs = (*it).GetInEdges();
			for (auto it2 = inArcs.begin(); it2 != inArcs.end(); it2++)
			{
				Vertex<V, E> temp = *(it2->GetDest());
				InsertArc((*it).GetData(), temp.GetData(), (*it2));
			}
		}
	}
	_count = rhs._count;
}

template<class V, class E>
inline Graph<V, E> & Graph<V, E>::operator=(const Graph<V, E> & rhs)
{
	Purge();

	Vertex<V, E> *temp;
	for (auto it = rhs._vertices.begin(); it != rhs._vertices.end(); it++)
	{
		V v = (*it).GetData();
		this->InsertVertex(v);
	}

	for (auto it = rhs._vertices.begin(); it != rhs._vertices.end(); it++)
	{
		if ((*it).GetOutDeg() > 0)
		{
			list<Arc<V, E>> outArcs = (*it).GetOutEdges();
			for (auto it2 = outArcs.begin(); it2 != outArcs.end(); it2++)
			{
				Vertex<V, E> temp = *(it2->GetDest());
				InsertArc((*it).GetData(), temp.GetData(), (*it2));
			}

		}
		else if ((*it).GetInDeg() > 0)
		{
			list<Arc<V, E>> inArcs = (*it).GetInEdges();
			for (auto it2 = inArcs.begin(); it2 != inArcs.end(); it2++)
			{
				Vertex<V, E> temp = *(it2->GetDest());
				InsertArc((*it).GetData(), temp.GetData(), (*it2));
			}
		}

	}
	_count = rhs._count;
	return *this;
}

template<class V, class E>
inline void Graph<V, E>::InsertVertex(const V & data)
{
	Vertex<V, E> v(data);
	_vertices.push_back(v);
	_count++;
}

template<class V, class E>
inline void Graph<V, E>::DeleteVertex(const V & data)
{

	typename list<Vertex<V, E>>::iterator _it = _vertices.begin();
	typename list<Vertex<V, E>>::iterator end = _vertices.end();
	while (_it != end)
	{
		list<Arc<V, E>>::iterator ait, aend, aait;
		ait = (*_it).GetOutEdges().begin();
		aend = (*_it).GetOutEdges().end();
		while(ait != aend)
		{
			if ((*ait).GetDest()->GetData() == data)
			{
				aait = ait;
				ait++;
				(*_it).RemoveOutArc(*aait);
			}
			else
				ait++;
		}
		_it++;
	}
	_it = _vertices.begin();
	while ((*_it).GetData() != data && _it != end)
		_it++;
	bool found = false;
	if ((*_it).GetData() == data)
		found = true;
	try
	{
		_vertices.erase(_it);
		_count--;
	}
	catch (Exception & e)
	{
		std::cout << e.getMessage() << std::endl;
	}
	if (!found)
		throw Exception("Vertex not found.");
	
	
}

template<class V, class E>
inline void Graph<V, E>::ResetProcessed()
{
	typename list<Vertex<V, E>>::iterator it = _vertices.begin();
	typename list<Vertex<V, E>>::iterator end = _vertices.end();
	while (it != end)
	{
		(*it).SetProcessed(false);
		it++;
	}
}

template<class V, class E>
inline void Graph<V, E>::InsertArc(const V & from, const V & to, Arc<V,E> arc)
{
	Vertex<V, E> * fromVertex;
	Vertex<V, E> * toVertex;
	bool fromFound = false;
	bool toFound = false;
	for (auto iter = _vertices.begin(); iter != _vertices.end(); iter++)
	{
		if ((*iter).GetData() == from)
		{
			fromVertex = &*iter;
			fromFound = true;
		}
		if ((*iter).GetData() == to)
		{
			toVertex = &*iter;
			toFound = true;
		}
	}
	if (!fromFound || !toFound)
		throw Exception("Vertex not found.");
	fromVertex->AddOutArc(arc);
	toVertex->AddInArc(arc);
}

template<class V, class E>
inline void Graph<V, E>::InsertArc(const V & from, const V & to, const E & data, int weight)
{
	Vertex<V, E> * fromVertex;
	Vertex<V, E> * toVertex;
	bool fromFound = false;
	bool toFound = false;
	for (auto iter = _vertices.begin(); iter != _vertices.end(); iter++)
	{
		if ((*iter).GetData() == from)
		{
			fromVertex = &*iter;
			fromFound = true;
		}
		if ((*iter).GetData() == to)
		{
			toVertex = &*iter;
			toFound = true;
		}
	}
	if (!fromFound || !toFound)
		throw Exception("Vertex not found.");

	Arc<V, E> inArc(fromVertex, weight, data);
	Arc<V, E> outArc(toVertex, weight, data);
	fromVertex->AddOutArc(outArc);
	toVertex->AddInArc(inArc);
}

template<class V, class E>
inline void Graph<V, E>::InsertArc(const V & from, const V & to, const E & data)
{
	Vertex<V, E> * fromVertex;
	Vertex<V, E> * toVertex;
	bool fromFound = false;
	bool toFound = false;
	for (auto iter = _vertices.begin(); iter != _vertices.end(); iter++)
	{
		if ((*iter).GetData() == from)
		{
			fromVertex = &*iter;
			fromFound = true;
		}
		if ((*iter).GetData() == to)
		{
			toVertex = &*iter;
			toFound = true;
		}
	}
	if (!fromFound || !toFound)
		throw Exception("Vertex not found.");

	Arc<V, E> inArc(fromVertex, data);
	Arc<V, E> outArc(toVertex, data);
	fromVertex->AddOutArc(outArc);
	toVertex->AddInArc(inArc);
}

template<class V, class E>
inline void Graph<V, E>::DeleteArc(const V & from, const V & to, Arc<V, E> arc)
{
	Vertex<V, E> * fromVertex;
	Vertex<V, E> * toVertex;
	bool fromFound = false;
	bool toFound = false;

	for (auto it = _vertices.begin(); it != _vertices.end(); it++)
	{
		if ((*it).GetData() == from)
		{
			fromVertex = &*it;
			fromFound = true;
		}
		if ((*it).GetData() == to)
		{
			toVertex = &*it;
			toFound = true;
		}
	}
	if (!fromFound || !toFound)
		throw Exception("Vertex not found.");

	fromVertex->RemoveOutArc(arc);
	toVertex->RemoveInArc(arc);
}

template<class V, class E>
inline void Graph<V, E>::DeleteArc(const V & from, const V & to, const E & data)
{
	Vertex<V, E> * fromVertex;
	Vertex<V, E> * toVertex;
	bool fromFound = false;
	bool toFound = false;

	for (auto it = _vertices.begin(); it != _vertices.end(); it++)
	{
		if ((*it).GetData() == from)
		{
			fromVertex = &*it;
			fromFound = true;
		}
		if ((*it).GetData() == to)
		{
			toVertex = &*it;
			toFound = true;
		}
	}
	if (!fromFound || !toFound)
		throw Exception("Vertex not found.");

	Arc<V, E> out = fromVertex->GetOutArc(data);
	Arc<V, E> in = fromVertex->GetInArc(data);
	fromVertex->RemoveOutArc(out);
	toVertex->RemoveInArc(in);
}

template<class V, class E>
inline void Graph<V, E>::DepthFirst(void(*visit)(V it))
{
	ResetProcessed();
	stack<Vertex<V, E>> stack;
	list<Arc<V, E>>::iterator itt, end;
	_vertices.begin()->SetProcessed(true);
	stack.push(*_vertices.begin());
	while (!stack.empty())
	{
		list< Arc<V, E>> edges = stack.top().GetOutEdges();
		visit(stack.top().GetData());
		itt = edges.begin();
		end = edges.end();
		stack.pop();
		while(itt != end)
		{
			if (!(*itt).GetDest()->Processed())
			{
				stack.push(*(*itt).GetDest());
				(*itt).GetDest()->SetProcessed(true);
			}
			itt++;
		}
	}

}

template<class V, class E>
inline void Graph<V, E>::BreadthFirst(void(*visit)(V it))
{
	ResetProcessed();
	queue<Vertex<V, E>> queue;
	list<Arc<V, E>>::iterator itt, end;
	_vertices.begin()->SetProcessed(true);
	queue.push(*_vertices.begin());
	while (!queue.empty())
	{
		list< Arc<V, E>> edges = queue.front().GetOutEdges();
		visit(queue.front().GetData());
		itt = edges.begin();
		end = edges.end();
		queue.pop();
		while (itt != end)
		{
			if (!(*itt).GetDest()->Processed())
			{
				queue.push(*(*itt).GetDest());
				(*itt).GetDest()->SetProcessed(true);
			}
			itt++;
		}
	}
	ResetProcessed();
}
#endif