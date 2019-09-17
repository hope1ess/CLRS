#include "Yalgorithm.h"
#include <vector>
using namespace std;
//insert_sort
void insert_sort(int* a, int length)
{
	for (int i = 1; i < length; ++i)
	{
		int key = a[i];
		int index = i - 1;
		while (index >= 0 && a[index] > key)
		{
			a[index + 1] = a[index];
			index--;
		}
		a[index + 1] = key;
	}
}

void insert_sort_no_asc(int* a, int length)
{
	for (int i = 1; i < length; ++i)
	{
		int key = a[i];
		int index = i - 1;
		while (index >= 0 && a[index] < key)
		{
			a[index + 1] = a[index];
			index--;
		}
		a[index + 1] = key;
	}
}

//merge_sort
void merge(int* a, int left, int mid, int right)
{
	vector<int> v1, v2;
	for (int i = left; i <= mid; ++i)
		v1.push_back(a[i]);
	for (int i = mid + 1; i <= right; ++i)
		v2.push_back(a[i]);
	const int INF = 0x3fffffff;
	v1.push_back(INF);
	v2.push_back(INF);
	for (int i1 = 0, i2 = 0; true;)
	{
		if (v1[i1] == INF && v2[i2] == INF)
			break;
		if (v1[i1] <= v2[i2])
			a[left] = v1[i1++];
		else
			a[left] = v2[i2++];
		++left;
	}
}

void merge_sort(int* a, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	merge_sort(a, left, mid);
	merge_sort(a, mid + 1, right);
	merge(a, left, mid, right);
}