#include <iostream>

using namespace std;

int bigMod(int b, int p, int m)
{
	// base condition
	if (p == 1)
	{
		return b;
	}

	int ans;
	if (p%2 == 0)
	{
		//even
		int half = bigMod(b, p/2, m);
		ans = ((half % m) * (half % m)) % m;

	}
	else
	{
		int other = bigMod(b, p-1, m);
		ans = ((b % m) * (other % m)) % m;
	}

	cout << "returning: " << ans << endl;
	return ans;
}


int main()
{
	int base, power,  mod;
	base  = 2;
	power = 31;
	mod = 10000007;

	int ans = bigMod(base, power, mod);

	cout << ans << endl;
	return 0;
}