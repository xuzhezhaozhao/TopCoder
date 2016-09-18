

vector <int> prime_factor;
void getPrimeFactor(int n)
{
	int lim = floor( sqrt(n * 1.0 + 0.5) );
	for (int i = 2; i <= lim; i++) {
		while (n % i == 0) {
			prime_factor.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		prime_factor.push_back(n);
	}
}