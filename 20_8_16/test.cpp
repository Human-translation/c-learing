#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LRU
{
public:
	LRU(int capacity)
	{
		CapaCity_ = capacity;
	}

	int get(int key)
	{
		auto listit = Map_.find(key);
		if (listit == Map_.end())
		{
			return -1;
		}
		else
		{
			auto ptr = listit->second;
			pair<int, int> kv = *ptr;

			Map_.erase(listit);
			List_.push_front(kv);
			Map_[key] = List_.begin();
			return kv.second;
		}
	}

	void put(int key, int value)
	{
		auto listit = Map_.find(key);
		if (listit == Map_.end())
		{
			if (Map_.size() == CapaCity_)
			{
				Map_.erase(List_.back().first);
				List_.pop_back();
			}

			List_.push_front(make_pair(key, value));
			Map_[key] = List_.begin();
		}
		else
		{
			auto ptr = listit->second;
			pair<int, int> kv = *ptr;
			kv.second = value;

			Map_.erase(listit);
			List_.push_front(kv);
			Map_[key] = List_.begin();
		}
	}

private:
	size_t CapaCity_;
	list<pair<int, int>> List_;
	unordered_map<int, list<pair<int, int>>::iterator> Map_;
};


int sort(vector<int> &arr,int left,int right)
{
	int tmp = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
			right--;
		arr[left] = arr[right];
		while (left < right && arr[left] <= tmp)
			left++;
		arr[right] = arr[left];
	}
	arr[left] = tmp;
	return left;
}

void kuaipai(vector<int> &arr,int left,int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = sort(arr, left, right);
	
	kuaipai(arr, left, mid - 1);
	kuaipai(arr, mid + 1, right);
}

void sort2(vector<int> &arr, int left, int mid, int right)
{
	vector<int> brr;
	for (int i = left; i <= right; i++)
	{
		brr.push_back(arr[i]);
	}

	int starA = left;
	int starB = mid + 1;

	for (int i = left; i <= right; i++)
	{
		if (starA > mid)
		{
			arr[i] = brr[starB-left];
			starB++;
		}
		else if (starB > right)
		{
			arr[i] = brr[starA-left];
			starA++;
		}
		else if (brr[starA - left] > brr[starB - left])
		{
			arr[i] = brr[starB - left];
			starB++;
		}
		else 
		{
			arr[i] = brr[starA - left ];
			starA++;
		}
	}
}

void mange(vector<int> &arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;

	mange(arr, left, mid);
	mange(arr, mid + 1, right);
	sort2(arr, left,mid, right);
}


class Share_ptr
{
public:

private:
	
};


class danli
{
public:

private:

};

int main()
{
	vector<int> arr{ 5,1,3,4,9,6,8 };
	mange(arr,0,arr.size()-1);
	for (auto ch : arr)
		cout << ch << ' ';
	cout << endl;
	return 0;
}