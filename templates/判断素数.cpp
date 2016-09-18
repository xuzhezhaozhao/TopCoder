bool isPrime(int n)
{
	int lim = floor( sqrt(n * 1.0 + 0.5) );
	for (int i = 2; i <= lim; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}