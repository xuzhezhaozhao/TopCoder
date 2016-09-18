long long gcd(long long a, long long b)
{
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

long long gcd (long long x,long long y)
{
	return y==0?x:gcd(y,x%y);
}