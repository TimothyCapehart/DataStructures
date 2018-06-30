#ifndef VERTEX_H
#define VERTEX_H
#include<list>
using std::list;


template<class V, class E >
class Arc;

template<class V, class E>
class Vertex
{
private:
	V _data;
	int _inDegree = 0;
	int _outDegree = 0;;
	bool _processed = false;
	list<Arc<V, E>> _inEdges;
	list<Arc<V, E>> _outEdges; 

public:
	Vertex();
	Vertex(V data) { _data = data; };
	~Vertex() {};

	V GetData() { return _data; };
	V GetData() const { return _data; };
	void SetData(const V & data) { _data = data; };
	int GetInDeg() { return _inDegree; };
	int GetInDeg() const { return _inDegree; };
	int GetOutDeg() { return _outDegree; };
	int GetOutDeg() const { return _outDegree; };
	bool Processed() const { return _processed; }; 
	bool Prcessed() const { return _processed; };
	void SetProcessed(bool proc) { _processed = proc; };
	void AddInArc(const Arc<V, E> & arc);
	void AddOutArc(const Arc<V, E> & arc);
	void RemoveInArc(const Arc<V, E> & arc);
	void RemoveInArc(const E & data);
	void RemoveOutArc(const Arc<V, E> & arc);
	void RemoveOutArc(const E & data);
	void DeincOut() { _outDegree--; };
	void DeincIn() { _inDegree--; };
	list<Arc<V,E>> & GetInEdges() { return _inEdges; };
	list<Arc<V, E>> & GetOutEdges() { return _outEdges; };
	list<Arc<V, E>>  GetInEdges() const { return _inEdges; };
	list<Arc<V, E>>  GetOutEdges() const { return _outEdges; };
	void SetInEdges(list<Arc<V, E>> & edges) { _inEdges = edges; };
	void SetOutEdges(list<Arc<V, E>> & edges) { _outEdges = edges; };
	Vertex<V, E> & operator=(const Vertex<V, E> & rhs);
	Arc<V, E> FindInArc(Vertex<V, E> v);
	Arc<V, E> FindOutArc(Vertex<V, E> v);
	Arc<V, E> & GetOutArc(const E & data);
	Arc<V, E> & GetInArc(const E & data);
	bool operator!=(const Vertex<V,E>& rhs);
	
};

template<class V, class E>
inline Vertex<V, E> & Vertex<V, E>::operator=(const Vertex<V, E> & rhs)
{
	_data = rhs._data;
	_inDegree = rhs._inDegree;
	_outDegree = rhs._outDegree;
	_inEdges = rhs._inEdges;
	_outEdges = rhs._outEdges;
	_processed = rhs._processed;
	return *this;
}

template<class V, class E>
inline bool Vertex<V, E>::operator!=(const Vertex<V, E> & rhs)
{
	return (_data != rhs._data &&
		_inDegree != rhs._inDegree &&
		_outDegree != rhs._outDegree &&
		_inEdges != rhs._inEdges &&
		_outEges != rhs._outEdges);
}

template<class V, class E>
inline Vertex<V, E>::Vertex()
{
	_inDegree = 0;
	_outDegree = 0;
	_processed = true;
}

template<class V, class E>
inline void Vertex<V, E>::AddInArc(const Arc<V, E> & arc)
{
	_inEdges.push_back(arc);
	_inDegree++;
}

template<class V, class E>
inline void Vertex<V, E>::AddOutArc(const Arc<V, E> & arc)
{
	_outEdges.push_back(arc);
	_outDegree++;
}

template<class V, class E>
inline Arc<V, E> Vertex<V, E>::FindInArc(Vertex<V, E> v)
{
	for (auto iter = _inEdges.begin(); iter != _inEdges.end(); iter++)
	{
		return *iter;
	}
	throw Exception("Arc not found.");
}

template<class V, class E>
inline Arc<V, E> Vertex<V, E>::FindOutArc(Vertex<V, E> v)
{
	for (auto iter = _outEdges.begin(); iter != _outEdges.end(); iter++)
	{
		return *iter;
	}
	throw Exception("Arc not found.");
}

template<class V, class E>
inline void Vertex<V, E>::RemoveInArc(const Arc<V, E> & arc)
{
	_inEdges.remove(arc);
	_inDegree--;
}

template<class V, class E>
inline void Vertex<V, E>::RemoveOutArc(const Arc<V, E> & arc)
{
	_outEdges.remove(arc);
	_outDegree--;
}

template<class V, class E>
inline void Vertex<V, E>::RemoveOutArc(const E & data)
{
	RemoveOutArc(GetOutArc(data));
}

template<class V, class E>
inline void Vertex<V, E>::RemoveInArc(const E & data)
{
	RemoveInArc(GetInArc(data));
}

template<class V, class E>
inline Arc<V,E> & Vertex<V, E>::GetOutArc(const E & data)
{
	Arc<V, E>  arc;
	for (auto it = _outEdges.begin(); it != _outEdges.end(); it++)
	{
		arc = *it;
		return  arc;
	}
	throw Exception("Arc not found.");
}

template<class V, class E>
inline Arc<V, E> & Vertex<V, E>::GetInArc(const E & data)
{
	Arc<V, E>  arc;
	for (auto it = _inEdges.begin(); it != _inEdges.end(); it++)
	{
		arc = *it;
		return arc;
	}
	throw Exception("Arc not found.");
}
#endif