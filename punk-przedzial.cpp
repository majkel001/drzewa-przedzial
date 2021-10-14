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
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		v = v / 2;
	}
}

long long query(int p, int k)
{
	p = p + base - 1;
	k = k + base + 1;
	long long res = 0;
	while (p - k != 1)
	{
		if (p % 2 == 0) res += tree[p + 1];
		if (k % 2 == 1) res += tree[k - 1];
		p /= 2;
		k /= 2;
	}
	return res;
}



int main()
{



	return  0;
}