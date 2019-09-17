#include "Yalgorithm.h"
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

//end