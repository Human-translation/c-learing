#include <iostream>
#include <vector>
using namespace std;


template <class K>
struct KeyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};


template <class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{}
};

template <class K, class V, class KeyOfValue, class HFun>
class HashBucket;

template <class K, class V, class KeyOfValue, class HFun>
struct HIterator
{
	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HashBucket<K, V, KeyOfValue, HFun> htable;
	typedef HIterator< K, V, KeyOfValue, HFun> Self;



	pNode _node;
	htable* _ht;

	HIterator(pNode node, htable* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*()
	{
		return _node->_data;
	}

	V* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfValue kov;
			HFun hf;
			int idx = hf(kov(_node->_data)) % _ht->_table.size();

			++idx;
			for (; idx < _ht->_table.size(); idx++)
			{
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
			}
			if (idx == _ht->_table.size())
				_node = nullptr;
		}
		return *this;
	}

};

template <class K, class V, class KeyOfValue, class HFun>
class HashBucket
{
public:

	template <class K, class V, class KeyOfValue, class HFun>
	friend class HIterator;

	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HIterator< K, V, KeyOfValue, HFun> iterator;

	iterator begin()
	{
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i])
				return iterator(_table[i], this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> Insert(const V& data)
	{
		CheckCapacity();
		KeyOfValue kov;
		HFun hf;
		int idx = hf(kov(data)) % _table.size();
		pNode cur = _table[idx];
		pNode tt = NULL;
		while (cur)
		{
			if (kov(cur->_data) == kov(data))
			{
				return make_pair(iterator(cur, false), false);
			}
			tt = cur;
			cur = cur->_next;
		}
		cur = new Node(data);

		cur->_next = _table[idx];
		_table[idx] = cur;
		if (tt)
			cout << kov(tt->_next->_data) << endl;

		++_size;
		return make_pair(iterator(cur, false), true);
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();

			vector<pNode> _newT;
			_newT.resize(newC);
			KeyOfValue kov;
			HFun hf;
			for (int i = 0; i < _table.size(); i++)
			{
				pNode cur = _table[i];
				while (cur)
				{
					pNode next = cur->_next;
					int idx = hf(kov(cur->_data)) % _newT.size();
					cur->_next = _newT[idx];
					_newT[idx] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(_newT);
		}
	}

	bool erase(const K& key);

	bool find(const K& key);

private:
	vector<pNode> _table;
	size_t _size;
};

template <class K>
struct HashFun
{
	int operator()(const K& key)
	{
		return key;
	}
};

template <>
struct HashFun<string>
{
	int operator()(const string& key)
	{
		int hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


template <class K, class V, class HFun = HashFun<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};

public:
	typedef typename HashBucket<K, pair<K, V>, MapKeyOfValue, HFun>::iterator iterator;

	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}

	pair<iterator, bool> Insert(const pair<K, V>& data)
	{
		return _hb.Insert(data);
	}

	V&operator[](const K& key)
	{
		pair<iterator, bool> ret = _hb.Insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	HashBucket<K, pair<K, V>, MapKeyOfValue, HFun> _hb;

};

template <class K, class HFun = HashFun<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};

public:

	typedef typename HashBucket<K, K, SetKeyOfValue, HFun>::iterator iterator;

	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}

	pair<iterator, bool> Insert(const K& data)
	{
		return _hb.Insert(data);
	}

private:
	HashBucket<K, K, SetKeyOfValue, HFun> _hb;

};

int main()
{
	UnorderedMap<int,int> h;
	h[3]=3;
	h[21]=21;
	h[13]=13;
	h[23]=23;
	h[1]=1;
	h[4]=4;
	h[2]=2;
	h[9]=9;
	h[10] = 10;
	h[11] = 11;
	h[12] = 12;
	h[13] = 13;

	//UnorderedMap<string, int> mp;
	//mp["aa"] = 1;

	//
	UnorderedMap<int, int>::iterator it = h.begin();
	while (it != h.end())
	{
		cout <<it->first<<"-->" << it->second << endl;
		++it;
	}
	//UnorderedSet<int> st;
	//st.Insert(1);
	//st.Insert(2);
	//st.Insert(3);
	//st.Insert(4);
	return 0;
}