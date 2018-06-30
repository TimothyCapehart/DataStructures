#ifndef ARC_H
#define ARC_H

template<class V, class E>
class Vertex;

template<class V, class E>
class Arc
{
private:
	Vertex<V, E> * _destination = nullptr;
	int _weight = 0;
	E _data;
	
public:
	Arc();
	Arc(Vertex<V, E> *dest, const E & data) { _destination = dest; _data = data; _weight = 0; };
	Arc(Vertex<V, E> *dest, const int & weight, const E & data);
	~Arc() {};

	Vertex<V, E> *& GetDest() { return _destination; };
	void SetDestination(const V & dest) { _destination = dest; };
	int GetWeight() { return _weight; };
	int GetWeight() const { return _weight; };
	void SetWeight(const int & weight) { _weight = wieght; };
	E GetData() { return _data; };
	E GetData() const { return _data; };
	void SetData(const E & data) { _data = data; };
	Arc<V, E> & operator=(const Arc<V, E> & rhs);
	bool operator==( Arc<V, E> rhs);
};

template<class V, class E>
inline bool Arc<V, E>::operator==( Arc<V, E> rhs)
{
	return (_destination == rhs.GetDest() && _weight == rhs.GetWeight() && _data == rhs.GetData());
}


template<class V, class E>
inline Arc<V, E> & Arc<V, E>::operator=(const Arc<V, E> & rhs)
{
	_destination = rhs._destination;
	_weight = rhs._weight;
	_data = rhs._data;
	return *this;
}

template<class V, class E>
inline Arc<V, E>::Arc()
{
	 _destination = nullptr;
	 _weight = 0; 
}

template<class V, class E>
inline Arc<V, E>::Arc(Vertex<V, E> * dest, const int & weight, const E & data)
{
	_destination = dest;
	_weight = weight;
	_data = data;
}
#endif