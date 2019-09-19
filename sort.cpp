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

//quicksort
int partition(int* a, int left, int right)
{
	int pivot = a[right];
	int index = left;
	for (int i = left; i < right; ++i)
	{
		if (a[i] <= pivot)
		{
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			++index;
		}
	}
	int temp = a[index];
	a[index] = a[right];
	a[right] = temp;
	return index;
}

void quick_sort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int pivot = partition(a, left, right);
	quick_sort(a, left, pivot - 1);
	quick_sort(a, pivot + 1, right);
}

//head_sort
int heap_parent(int i)
{
	return ((i + 1) / 2 - 1);
}

int heap_left(int i)
{
	return i * 2 + 1;
}

int heap_right(int i)
{
	return i * 2 + 2;
}

void max_heapify(int* a, int heapSize, int i)
{
	int left = heap_left(i);
	int right = heap_right(i);
	/*if (left >= heapSize || right >= heapSize)
		return;*/
	int largest = i;
	if (left < heapSize && a[largest] < a[left])
		largest = left;
	if (right < heapSize && a[largest] < a[right])
		largest = right;
	if (largest != i)
	{
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		max_heapify(a, heapSize, largest);
	}
}

void build_heap(int* a, int length)
{
	int nonLeaf = (length - 1) / 2;
	for (int i = nonLeaf; i >= 0; --i)
		max_heapify(a, length, i);
}

void heap_sort(int* a, int length)
{
	build_heap(a, length);
	for (int i = length - 1; i > 0; --i)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		max_heapify(a, --length, 0);
	}
}