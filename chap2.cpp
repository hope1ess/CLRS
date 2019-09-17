//2.1-3
//set nil is -1
int linear_sort(int* a, int length, int v)
{
	for (int i = 0; i < length; ++i)
		if (a[i] == v)
			return i;
	return -1;
}

//2.1-4
int* binary_add(int* a, int* b, int length)
{
	int* result = new int[length + 1];
	int carry = 0;
	for (int i = length - 1, index = length; i >= 0; --i, --index)
	{
		int sum = a[i] + b[i] + carry;
		carry = sum / 2;
		result[index] = sum % 2;
	}
	result[0] = carry;
	return result;
}