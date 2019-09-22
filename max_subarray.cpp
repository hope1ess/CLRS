/*
for max subarray	
*/
#include "Yalgorithm.h"

max_subarray_hub find_max_crossing_subarray(int* a, int left, int mid, int right)	//NO DEBUG TODO
{
	max_subarray_hub res;
	int left_sum = -1, sum = 0, left_i;
	for (int i = mid; mid >= left; --i)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			left_i = i;
		}
	}
	int right_sum = -1, right_i;
	sum = 0;
	for (int i = mid + 1; i <= right; ++i)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			right_i = i;
		}
	}
	res.max_left = left_i;
	res.max_rgith = right_i;
	res.max_sum = left_sum + right_sum;
	return res;
}

max_subarray_hub find_maximum_subarray(int* a, int left, int right)
{
	if (left == right)
		return  max_subarray_hub{ left, right, a[left] };
	else
	{
		int mid = (left + right) / 2;
		max_subarray_hub left_subarray = find_maximum_subarray(a, left, mid - 1);
		max_subarray_hub right_subarray = find_maximum_subarray(a, mid + 1, right);
		max_subarray_hub cross_subarray = find_max_crossing_subarray(a, left, mid, right);
		if (left_subarray.max_sum >= right_subarray.max_sum && left_subarray.max_sum >= cross_subarray.max_sum)
			return left_subarray;
		else if (right_subarray.max_sum >= left_subarray.max_sum && right_subarray.max_sum >= cross_subarray.max_sum)
			return right_subarray;
		else
			return cross_subarray;
	}
}