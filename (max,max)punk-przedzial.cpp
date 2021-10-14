#include <bits/stdc++.h>

using namespace std;

const int base = 1 << 17;
long long tree[base << 1];


void update(int v,long long value)
{
	v = v + base;
	tree[v] = value;
	v = v / 2;
	while (v>0)
	{
		tree[v] = max(tree[v * 2] , tree[v * 2 + 1]);
		v = v / 2;
	}
}

long long query(int p, int k)
{
	p = p + base - 1;
	k = k + base + 1;
	long long res = max(tree[p + 1], tree[k - 1]);
	while (k - p > 1)
	{
		if (p % 2 == 0) res = max(tree[p + 1],res);
		if (k % 2 == 1) res = max(tree[k - 1],res);
		p /= 2;
		k /= 2;
	}
	return res;
}



int main()
{


	return  0;
}