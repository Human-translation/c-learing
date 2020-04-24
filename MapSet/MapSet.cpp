#include <iostream>
#include <utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class V>
struct RBNode
{
	RBNode<V>* _left;
	RBNode<V>* _right;
	RBNode<V>* _parent;
	V _value;
	COLOR _color;

	RBNode(const V& value = V())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template <class V>
struct RBIterator
{
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIterator<V> Self;
	pNode _node;

	RBIterator(pNode node)
		:_node(node)
	{}

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if(_node->_right != parent)
				_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}

};


template <class K, class V,class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIterator<V> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}

	iterator end()
	{
		return iterator(_header);
	}

	iterator rbegin()
	{
		return iterator(_header->_right);
	}

	iterator rend()
	{
		return iterator(_header);
	}

	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur;
	}


	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = subL;
			subL->_parent = gParent;
		}
		else
		{
			_header->_parent = subL;
			subL->_parent = _header;
		}
		parent->_parent = subL;
	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subR;
			else
				gParent->_right = subR;
			subR->_parent = gParent;
		}
		else
		{
			_header->_parent = subR;
			subR->_parent = _header;
		}
		parent->_parent = subR;
	}

	pair<iterator,bool> Insert(const V& value)
	{
		if (_header->_parent == nullptr)
		{
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return make_pair(iterator(root), true);
		}
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		KeyOfValue kov;
		while (cur)
		{
			parent = cur;
			if (kov(cur->_value)== kov(value))
			{
				return make_pair(iterator(cur), false);
			}
			else if (kov(cur->_value) > kov(value))
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		cur = new Node(value);
		pNode newNode = cur;
		if (kov(parent->_value) > kov(cur->_value))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;


		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		_header->_parent->_color = BLACK;

		_header->_left = leftMost();
		_header->_right = rightMost();
		return make_pair(iterator(newNode), true);
	}

	bool isRBTree()
	{
		pNode root = _header->_parent;
		if (root == nullptr)
			return true;
		if (root->_color == RED)
		{
			cout << "根必须为红色" << endl;
			return false;
		}
		pNode cur = root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++blackCount;
				cur = cur->_right;
			}
		}

		int k = 0;
		return _isRBTree(root, k, blackCount);

	}

	bool _isRBTree(pNode root, int curBlackCount, int totalBlackCount)
	{
		if (root == nullptr)
		{
			if (curBlackCount != totalBlackCount)
			{
				cout << "每条路径黑色节点个数不同" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == BLACK)
			++curBlackCount;
		pNode parent = root->_parent;
		if (parent->_color == RED && root->_color == RED)
		{
			cout << "有红色连续的节点" << endl;
			return false;
		}
		return _isRBTree(root->_left, curBlackCount, totalBlackCount) && _isRBTree(root->_right, curBlackCount, totalBlackCount);
	}

private:
	pNode _header;
};

template <class K,class V>
class MyMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _rb.begin();
	}

	iterator end()
	{
		return _rb.end();
	}

	iterator rbegin()
	{
		return _rb.rbegin();
	}

	iterator rend()
	{
		return _rb.rend();
	}

	V& operator[](const K& key)
	{
		return (*(_rb.Insert(make_pair(key, V())).first)).second;
	}

	pair<iterator,bool> Insert(const pair<K,V>& data)
	{
		return _rb.Insert(data);
	}

private:
	RBTree<K, pair<K, V>, MapKeyOfValue> _rb;
};


template <class K>
class MySet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;

	pair<iterator, bool> Insert(const K& data)
	{
		return _rb.Insert(data);
	}

private:
	RBTree<K, K, SetKeyOfValue> _rb;
};

int main()
{
	MyMap<int, int> m;
	m.Insert(make_pair(2, 2));
	m.Insert(make_pair(1, 1));
	m[3] = 3;

	MyMap<int, int>::iterator it = m.rbegin();
	while (it != m.rend())
	{
		cout << it->first << "  " << it->second << endl;
		--it;
	}
	MySet<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	return 0;
}