long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}