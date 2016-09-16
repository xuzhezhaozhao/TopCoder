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

bool is_number(char c) {
	return ( c >= '0' && c <= '9' );
}
bool is_alpha(char c) {
	return ( c >= 'A' && c <= 'Z' );
}

const double eps = 1e-10;

double calc(int C[], int M, double r) {
	double mul = 1.0;
	double res = 0;
	for (int i = M; i >= 0; --i) {
		res += C[i] * mul;
		mul *= (1 + r);
	}
	return res;
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open jam.in!\n");
	}
	if (!freopen("jam.out", "w", stdout)) {
		printf("Can't open jam.out!\n");
	}
#endif

	int T;
	scanf("%d", &T);
	int C[101];
	for (int case_i = 0; case_i < T; ++case_i) {
		int M;
		scanf("%d", &M);
		for (int i = 0; i <= M; ++i) {
			scanf("%d", &C[i]);
		}
		C[0] = -C[0];
		double high = 1.0, low = -1.0;
		int iters = 500;
		while (iters--) {
			double mid = (high + low) / 2;
			double result = calc(C, M, mid);
			if (result > 0) {
				low = mid;
			} else {
				high = mid;
			}
		}
		double r = low;
		printf("Case #%d: %.16f\n", case_i + 1, r);
	}

	return 0;
}

