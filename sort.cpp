#include "Yalgorithm.h"
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