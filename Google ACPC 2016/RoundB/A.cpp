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
		int L, R;
		scanf("%d %d", &L, &R);
		long long N = min(L, R);
		long long m = (N + 1) * N / 2;
		printf("Case #%d: %lld\n", casei + 1, m);
	}
	
	return 0;
}