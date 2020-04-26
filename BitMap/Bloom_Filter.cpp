#include <vector>
#include <iostream>
#include <string>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		_array.resize((range >> 5) + 1);
	}

	void set(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] |= (1 << bitIdx);
	}

	bool test(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		return (_array[idx] >> bitIdx) & 1;
	}

	void reset(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _array;
};

template <class K,class HF1,class HF2,class HF3>
class BloomFilter
{
public:
	BloomFilter(size_t range)
		:_bm(range * 5)
		, _bitnum(range * 5)
	{}

	void set(const K& key)
	{
		size_t idx1 = HF1()(key) % _bitnum;
		size_t idx2 = HF2()(key) % _bitnum;
		size_t idx3 = HF3()(key) % _bitnum;
		_bm.set(idx1);
		_bm.set(idx2);
		_bm.set(idx3);
	}

	void test()
	{
		size_t idx1 = HF1()(key) % _bitnum;
		size_t idx2 = HF2()(key) % _bitnum;
		size_t idx3 = HF3()(key) % _bitnum;
		if (!_bm.test(idx1))
			return false;
		if (!_bm.test(idx2))
			return false;
		if (!_bm.test(idx3))
			return false;
		return true;
	}

private:
	BitMap _bm;
	size_t _bitnum;
};

struct HF1
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		for (const auto& ch:str)
		{
			key = key * 131 + ch;
		}
		return key;
	}
};

struct HF2
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		size_t magic = 63689;
		for (const auto& ch : str)
		{
			key = key * magic + ch;
			magic *= 378551;
		}
		return key;
	}
};

struct HF3
{
	size_t operator()(const string& str)
	{
		size_t key = 0;
		for (const auto& ch : str)
		{
			key = key * 131 + ch;
		}
		return key;
	}
};


void test()
{
	BitMap bm(500);
	bm.set(511);
	bm.set(16);
	bm.set(63);
	bool ret = bm.test(511);
	ret = bm.test(63);
	ret = bm.test(16);
	ret = bm.test(100);
	bm.reset(16);
	ret = bm.test(16);
}

int main()
{
	test();
	return 0;
}
