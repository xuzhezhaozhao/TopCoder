
// Çó C[N][k]
void calc()
{
	memset(C, 0, sizeof(C));
	for (int i = 1; i < MAX_C; i++) {
		C[i][0] = 1;
		if (i < 501) {
			C[i][i] = 1;
		}
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= MOD;
		}
	}
}
