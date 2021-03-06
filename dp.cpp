/*
CLRS DP's demo
*/
//cut_rod
#include "Yalgorithm.h"
#include <algorithm>
#include <iostream>
using namespace std;

struct cut_rod_ext
{
	int* s;
	int r;
};

//cut_road top-down
int memoized_cut_rod_aux(int* p, int n, int* r)
{
	if (r[n] != -1)
		return r[n];
	int q;
	if (n == 0)
		q = 0;
	else
	{
		q = -1;
		for (int i = 1; i <= n; ++i)
			q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
	}
	r[n] = q;
	return r[n];
}

int memoized_cut_rod(int* p, int n)
{
	int* r = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		r[i] = -1;
	return memoized_cut_rod_aux(p, n, r);
}

//cut_rod bottom_up
int bottom_up_cut_rod(int* p, int n)
{
	int* r = new int[n + 1];
	r[0] = 0;
	for (int j = 1; j <= n; ++j)
	{
		int q = -1;
		for (int i = 1; i <= j; ++i)
			q = max(q, p[i] + r[j - i]);
		r[j] = q;
	}
	return r[n];
}

cut_rod_ext extended_bottom_up_cut_rod(int* p, int n)
{
	int* r = new int[n + 1];
	int* s = new int[n + 1];
	r[0] = 0;
	for (int j = 1; j <= n; ++j)
	{
		int q = -1;
		for (int i = 1; i <= j; ++i)
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
		r[j] = q;
	}
	cut_rod_ext res;
	res.r = r[n];
	res.s = s;
	return res;
}