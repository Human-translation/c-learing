#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _value;

	BSTNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_value(value)
	{}
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	pNode find(const T& value)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_value == value)
				return cur;
			else if (cur->_value > value)
			{
				cur = cur->_right;
			}
			else if (cur->_value < value)
			{
				cur = cur->_left;
			}
		}
		return cur;
	}

	bool Insert(const T& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(value);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == value)
				return false;
			else if (cur->_value > value)
			{
				cur = cur->_right;
			}
			else if (cur->_value < value)
			{
				cur = cur->_left;
			}
		}
		cur = new Node(value);
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	bool Erase(const T& value)
	{
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_value = value)
				break;
			else if (cur->_value > value)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_value < value)
			{
				parent = cur;
				cur = cur->_left;
			}
		}
		if (cur == nullptr)
			return false;


		if (cur->_left == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else
				_root = cur->right;
			delete cur;
			cur = nullptr;
		}
		else if (cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else
				_root = cur->_left;
			delete cur;
			cur = nullptr;
		}
		else
		{
			pNode pNext = cur->_left;
			pNode parent = cur;
			while (pNext->right)
			{
				parent = pNext;
				pNext = pNext->_right;
			}
			cur->_value = pNext->_value;
			if (parent->_left = pNext)
				parent->_left = pNext->_left;
			else
				parent->_right = pNext->_left;
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}


	void _inOrder(pNode root)
	{
		if (root)
		{
			inOrder(root->_left);
			cout << root->_value << ' ';
			inOrder(root->_right);
		}
	}
	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

private:
	pNode _root = nullptr;
};