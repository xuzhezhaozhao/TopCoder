// Sieve of Eratosthenes
// Initially, all element of isPrime is true except for 0 and 1
for (int x = 2; x * x <= B; x++) {
	if (isPrime[x]) {
		for (int y = 2 * x; y <= B; y += x) {
			isPrime[y] = false;
		}
	}
}