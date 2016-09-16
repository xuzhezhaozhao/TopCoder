#include <cassert>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
#define mkp make_pair

const int MOD = 1000000007;

long long PowerMod(long long a, long long b, long long c)
{
	long long ans = 1;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans % c;
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open jam.in!\n");
		exit(-1);
	}
	if (!freopen("jam.out", "w", stdout)) {
		printf("Can't open jam.out\n");
		exit(-1);
	}
#endif

	int T;
	scanf("%d\n", &T);
	for (int casei = 0; casei < T; ++casei) {
		long long A, B, N, K;
		scanf("%lld %lld %lld %lld", &A, &B, &N, &K);

		vector<long long> cnta(K);
		vector<long long> cntb(K);
		vector<long long> repeated(K);
		long long times = N / K;
		long long rem = N % K;
		for (int i = 1; i <= K; i++) {
			// ¼ÆËã i^A % K, i^B % K
			long long ra = PowerMod(i, A, K);
			long long rb = PowerMod(i, B, K);
			long long n = times;
			if (i <= rem) {
				++n;;
			}
			cnta[ra] += n;
			cntb[rb] += n;
			cnta[ra] %= MOD;
			cntb[rb] %= MOD;
			if ( (ra+rb) % K == 0 ) {
				repeated[ra] += n;
				repeated[ra] %= MOD;
			}
		}
		long long res = 0;
		for (int i = 0; i < K; i++) {
			int j = (K - i) % K;
			res += cnta[i] * cntb[j] - repeated[i];
			res %= MOD;
		}
		printf("Case #%d: %lld\n", casei + 1, res);
	}
	
	return 0;
}