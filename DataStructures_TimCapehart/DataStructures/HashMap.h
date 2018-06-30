#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>
#include <list>
#include <iterator>
using std::list;
using std::vector;
using std::endl;

template<class V>
void visit(V value)
{
	std::cout << value.Title << endl;
	std::cout << value.Author << endl;
	std::cout << value.Pages << endl;
};

template<class K, class V>
class HashNode
{
private:
	K key_;
	V value_;

public:
	HashNode(K key, V value) { key_ = key; value_ = value; };
	K GetKey() { return key_; };
	K GetKey() const { return key_; };
	V GetValue() { return value_; };
	V GetValue() const { return value_; };
	void SetKey(K key) { key_ = key; };
	void SetValue(V value) { value_ = value; };
};

template<class K, class V>
class HashMap
{
public:
	HashMap() = delete;
	HashMap(size_t table_size, int(*hash)(K key, size_t size));
	HashMap(const HashMap & copy);
	HashMap(HashMap&& copy) noexcept;
	HashMap<K,V> & operator=(HashMap&& rhs) noexcept;
	HashMap<K, V> & operator=(const HashMap & rhs);
	~HashMap() = default;
	bool Find(K key);
	void Insert(K key, V value);
	void Delete(K key);
	void Update(K key, V value);
	void Rehash(size_t new_size);
	void SetHash(int(*hash)(K key, size_t size), size_t table_size);
	V operator [] (K key);
	V operator [] (K key) const;
	void Traverse(void(*visit)(V value));

private:
	vector<list<HashNode<K, V>>> hashtable_; 
	int(*hash_)(K key, size_t size) = nullptr; // hash function
	void(*visit_)(V value) = visit; // visit function
	size_t table_size_ = 0;
};

template<class K, class V>
inline HashMap<K, V>::HashMap(size_t table_size, int(*hash)(K key, size_t size))
{
	hashtable_.resize(table_size);
	table_size_ = table_size;
	SetHash(hash, table_size);
}

template<class K, class V>
inline HashMap<K, V>::HashMap(HashMap&& copy) noexcept
{
	hashtable_ = copy.hashtable_;
	SetHash(copy.hash_, copy.table_size_);
	table_size_ = copy.table_size_;
}

template<class K, class V>
inline HashMap<K, V>::HashMap(const HashMap & copy)
{
	hashtable_ = copy.hashtable_;
	SetHash(copy.hash_, copy.table_size_);
	table_size_ = copy.table_size_;
}

template<class K, class V>
inline HashMap<K, V> & HashMap<K, V>::operator=(HashMap&& rhs) noexcept
{
	hashtable_ = rhs.hashtable_;
	SetHash(rhs.hash_, rhs.table_size_);
	table_size_ = rhs.table_size_;
}

template<class K, class V>
inline HashMap<K, V> & HashMap<K, V>::operator=(const HashMap& rhs) 
{
	hashtable_ = rhs.hashtable_;
	SetHash(rhs.hash_, rhs.table_size_);
	table_size_ = rhs.table_size_;
	return *this;
}

template<class K, class V>
inline void HashMap<K, V>::Insert(K key, V value)
{
	HashNode<K, V> newNode(key, value);
	hashtable_[hash_(key, table_size_)].emplace_back(newNode);
}

template<class K, class V>
inline void HashMap<K, V>::Delete(K key)
{
	int i = hash_(key, table_size_);
	if (hashtable_[i].size() == 1)
		hashtable_[i].clear();
	else
	{
		for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
			if ((*it).GetKey() == key)
			{
				hashtable_[i].erase(it);
				return;
			}
	}
}

template<class K, class V>
inline void HashMap<K, V>::Update(K key, V value)
{
	int i = hash_(key, table_size_);
	if (hashtable_[i].size() == 1)
		hashtable_[i].front().SetValue(value);
	else
	{
		for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
			if ((*it).GetKey() == key)
				(*it).SetValue(value);
	}
}

template<class K, class V>
inline void HashMap<K, V>::SetHash(int(*hash)(K key, size_t size), size_t table_size)
{
	hash_ = hash;
	Rehash(table_size);
}

template<class K, class V>
inline void HashMap<K, V>::Rehash(size_t newsize)
{
	vector<list<HashNode<K, V>>> rehashed;
	rehashed.resize(newsize);
	for (size_t i = 0; i < newsize; i++)
		for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
		{
			HashNode<K, V> newNode((*it).GetKey(), (*it).GetValue());
			rehashed[i].emplace_back(newNode);
		}

	hashtable_ = rehashed;
}

template<class K, class V>
inline V HashMap<K, V>::operator[](K key)
{
	int i = hash_(key, table_size_);
	if (hashtable_[i].size() == 1)
		return hashtable_[i].front().GetValue();
	else
	{
		for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
			if ((*it).GetKey() == key)
				return (*it).GetValue();
	}
}

template<class K, class V>
inline V HashMap<K, V>::operator[](K key) const
{
	int i = hash_(key, table_size_);
	if (hashtable_[i].size() == 1)
		return hashtable_[i].front().GetValue();
	else
	{
		for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
			if ((*it).GetKey() == key)
				return (*it).GetValue();
	}
}

template<class K, class V>
inline void HashMap<K, V>::Traverse(void(*visit)(V value))
{
	for (size_t i = 0; i < table_size_; i++)
	{
		if (hashtable_[i].empty())
			continue;
		if (hashtable_[i].size() == 1)
			visit(hashtable_[i].front().GetValue());
		else
		{
			for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
				visit(it.GetValue());
		}
	}
}

template<class K, class V>
inline bool HashMap<K,V>::Find(K key)
{
	for (size_t i = 0; i < table_size_; i++)
	{
		if (hashtable_[i].empty())
			continue;
		else
		{
			for (auto it = hashtable_[i].begin(); it != hashtable_[i].end(); it++)
				if ((*it).GetKey() == key)
					return true;
		}
	}
	return false;
}
#endif