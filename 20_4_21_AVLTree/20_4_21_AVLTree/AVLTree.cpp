#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;
	int _bf;

	AVLNode(const T& value = T())
		:_left(nullptr)
		, _right(nullptr)
		,_parent(nullptr)
		, _value(value)
		,_bf(0)
	{}
};

template<class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent != _root)
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
			_root = subL;
			subL->_parent = nullptr;
		}
		parent->_parent = subL;

		subL->_bf = 0;
		parent->_bf = 0;
	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_left;
		pNode subRL = subR->_right;

		subR->_right = parent;
		parent->_left = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (parent != _root)
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
			_root = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;

		subR->_bf = 0;
		parent->_bf = 0;
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
				false;
			else if (cur->_value > value)
			{
				cur = cur->_left;
			}
			else if (cur->_value < value)
			{
				cur = cur->_right;
			}
		}
		cur = new Node(value);
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		while (parent)
		{
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					pNode subL = parent->_left;
					pNode subLR = subL->_right;
					int bf = subLR->_bf;

					RotateL(cur);
					RotateR(parent);

					if (bf == 1)
					{
						parent->_bf = 0;
						subL->_bf = -1;
					}
					else if (bf == -1)
					{
						parent->_bf = 1;
						subL->_bf = 0;
					}
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					pNode subR = parent->_left;
					pNode subRL = subR->_right;
					int bf = subRL->_bf;

					RotateR(cur);
					RotateL(parent);

					if (bf == 1)
					{
						parent->_bf = -1;
						subR->_bf = 0;
					}
					else if (bf == -1)
					{
						parent->_bf = 0;
						subR->_bf = 1;
					}
				}
				break;
			}
			else
				assert(false);
		}
		return true;
	}

	int height(pNode root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = height(root->_left);
		int right = height(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool isAVLTree()
	{
		return _isAVLTree(_root);
	}

	bool _isAVLTree(pNode root)
	{
		if (root == nullptr)
			return true;

		int left = height(root->_left);
		int right = height(root->_right);
		if (right - left != root->_bf)
		{
			cout << "´íÎó" << endl;
			return false;
		}
		return abs(root->_bf) < 2 && _isAVLTree(root->_left) && _isAVLTree(root->_right);
	}

private:
	pNode _root = nullptr;
};